#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;
 
static constexpr double EPS = 1e-9;
 
struct P3 {
    double x, y, z;
    P3() : x(0), y(0), z(0) {}
    P3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    P3 operator + (const P3& o) const { return {x + o.x, y + o.y, z + o.z}; }
    P3 operator - (const P3& o) const { return {x - o.x, y - o.y, z - o.z}; }
    P3 operator * (double k) const { return {x * k, y * k, z * k}; }
};
 
static inline double dot(const P3& a, const P3& b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
 
static inline P3 cross(const P3& a, const P3& b) {
    return {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x};
}
 
static inline double norm(const P3& a) { return sqrt(dot(a,a)); }
 
// Up to 2 opposite vertices for an undirected edge
struct PR {
    int a = -1, b = -1;
    void ins(int x) { (a == -1 ? a : b) = x; }
    void rem(int x) { (a == x ? a : b) = -1; }
    int cnt() const { return (a != -1) + (b != -1); }
    int any() const { return a != -1 ? a : b; } // the one that exists if cnt==1
};
 
struct Face {
    P3 n;          // (not unit) outward normal
    int a, b, c;   // CCW seen from outside
};
 
static inline bool visible(const Face& f, const vector<P3>& A, int p) {
    // dot(n, A[p] - A[a]) > 0 means point is on normal side -> face visible
    return dot(f.n, A[p] - A[f.a]) > EPS;
}
 
vector<Face> hull3d(const vector<P3>& A) {
    int n = (int)A.size();
    vector<Face> FS;
    if (n < 4) return FS;
 
    // ---- find a non-degenerate initial tetrahedron ----
    int i0 = 0;
    int i1 = -1, i2 = -1, i3 = -1;
 
    for (int i = 1; i < n; i++) {
        if (norm(A[i] - A[i0]) > EPS) { i1 = i; break; }
    }
    if (i1 == -1) return FS; // all same point
 
    for (int i = 0; i < n; i++) if (i != i0 && i != i1) {
        if (norm(cross(A[i1] - A[i0], A[i] - A[i0])) > EPS) { i2 = i; break; }
    }
    if (i2 == -1) return FS; // all collinear
 
    for (int i = 0; i < n; i++) if (i != i0 && i != i1 && i != i2) {
        double vol6 = dot(A[i] - A[i0], cross(A[i1] - A[i0], A[i2] - A[i0]));
        if (fabs(vol6) > EPS) { i3 = i; break; }
    }
    if (i3 == -1) return FS; // all coplanar (degenerate 3D hull)
 
    // Put tetra vertices in positions 0..3 by index mapping
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    // swap to ensure ord[0..3] are i0,i1,i2,i3
    auto bring = [&](int pos, int idx){
        int where = find(ord.begin(), ord.end(), idx) - ord.begin();
        swap(ord[pos], ord[where]);
    };
    bring(0, i0); bring(1, i1); bring(2, i2); bring(3, i3);
 
    vector<P3> B(n);
    for (int i = 0; i < n; i++) B[i] = A[ord[i]];
 
    // interior point: centroid of initial tetra (guaranteed inside final hull)
    P3 inside = (B[0] + B[1] + B[2] + B[3]) * 0.25;
 
    // Edge table
    vector<vector<PR>> E(n, vector<PR>(n));
    auto edge = [&](int u, int v) -> PR& {
        if (u > v) swap(u, v);
        return E[u][v];
    };
 
    auto orient_outward = [&](int &i, int &j, int &k, P3 &nn) {
        // Want inside to be on the non-positive side: dot(nn, inside - Bi) <= 0
        if (dot(nn, inside - B[i]) > EPS) {
            nn = nn * -1.0;
            swap(j, k);
        }
    };
 
    auto addFace = [&](int i, int j, int k) {
        P3 nn = cross(B[j] - B[i], B[k] - B[i]);
        orient_outward(i, j, k, nn);
        Face f{nn, i, j, k};
 
        edge(i, j).ins(k);
        edge(i, k).ins(j);
        edge(j, k).ins(i);
 
        FS.push_back(f);
    };
 
    // initial tetra faces
    addFace(0, 1, 2);
    addFace(0, 3, 1);
    addFace(0, 2, 3);
    addFace(1, 3, 2);
 
    // ---- incremental insertion ----
    for (int p = 4; p < n; p++) {
        // remove visible faces
        for (int idx = 0; idx < (int)FS.size(); idx++) {
            Face f = FS[idx];
            if (visible(f, B, p)) {
                edge(f.a, f.b).rem(f.c);
                edge(f.a, f.c).rem(f.b);
                edge(f.b, f.c).rem(f.a);
                swap(FS[idx--], FS.back());
                FS.pop_back();
            }
        }
 
        // horizon edges: edges with exactly 1 adjacent face after removals
        vector<pair<int,int>> horizon;
        horizon.reserve(FS.size() * 2);
 
        for (auto &f : FS) {
            auto take = [&](int u, int v, int opp) {
                PR &pr = edge(u, v);
                if (pr.cnt() == 1 && pr.any() == opp) horizon.push_back({u, v});
            };
            take(f.a, f.b, f.c);
            take(f.a, f.c, f.b);
            take(f.b, f.c, f.a);
        }
 
        // add new faces around the hole
        for (auto [u, v] : horizon) addFace(u, v, p);
    }
 
    // Map indices back to original indices if you need faces as indices.
    // For this problem we only need area/volume, so keep B/FS.
 
    return FS; // faces in B-indexing
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    cout.setf(std::ios::fixed);
    cout << setprecision(4);
 
    while (T--) {
        int n;
        cin >> n;
        vector<P3> A(n);
        for (int i = 0; i < n; i++) {
            double x, y, z;
            cin >> x >> y >> z;
            A[i] = P3(x, y, z);
        }
 
        // Build hull (faces are oriented outward, but note: internal reordering happens)
        // To compute area/volume, we need the same point array used by hull.
        // Weâ��ll rebuild the exact B used inside hull3d by duplicating the tetra-selection logic.
        // Easiest: re-run hull but keep also the re-ordered points. Here we just redo selection.
 
        // --- redo selection to get B (same as hull3d) ---
        int i0 = 0, i1=-1, i2=-1, i3=-1;
        for (int i = 1; i < n; i++) if (norm(A[i] - A[i0]) > EPS) { i1=i; break; }
        for (int i = 0; i < n && i2==-1; i++) if (i!=i0 && i!=i1)
            if (norm(cross(A[i1]-A[i0], A[i]-A[i0])) > EPS) i2=i;
        for (int i = 0; i < n && i3==-1; i++) if (i!=i0 && i!=i1 && i!=i2) {
            double vol6 = dot(A[i]-A[i0], cross(A[i1]-A[i0], A[i2]-A[i0]));
            if (fabs(vol6) > EPS) i3=i;
        }
 
 
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        auto bring = [&](int pos, int idx){
            int where = find(ord.begin(), ord.end(), idx) - ord.begin();
            swap(ord[pos], ord[where]);
        };
        bring(0,i0); bring(1,i1); bring(2,i2); bring(3,i3);
 
        vector<P3> B(n);
        for (int i = 0; i < n; i++) B[i] = A[ord[i]];
 
        auto faces = hull3d(A); // faces are in *some* reordered system internally
        // IMPORTANT: hull3d(A) internally reorders to B exactly as above.
        // Our B matches that reorder, so we can compute on B + faces.
 
        cout << sz(faces) << nl;
 
        for (auto &f : faces) {
        	cout << 3 << " " << f.a << " " << f.b << " " << f.c << nl;
        }
    }
    return 0;
} 