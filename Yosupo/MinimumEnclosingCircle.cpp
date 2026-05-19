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

using namespace std;

const ld EPS = 1e-7;

struct Point {
    ld x, y;
};

static inline Point operator+(const Point& a, const Point& b) { return {a.x + b.x, a.y + b.y}; }
static inline Point operator-(const Point& a, const Point& b) { return {a.x - b.x, a.y - b.y}; }
static inline Point operator*(const Point& a, ld k) { return {a.x * k, a.y * k}; }

static inline ld dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
static inline ld cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
static inline ld norm2(const Point& a) { return dot(a, a); }

struct Circle {
    Point c;
    ld r; // radius
};

static inline ld dist2(const Point& a, const Point& b) {
    return dot(a-b,a-b);
}

static inline bool contains(const Circle& C, const Point& p) {
    if (C.r < 0) return false;
    // allow small tolerance; compare squared to avoid sqrt
    ld d2 = dist2(C.c, p);
    ld rr = C.r + 1e-12L;
    return d2 <= rr * rr + 1e-12L;
}

Circle circle_from_2(const Point& a, const Point& b) {
    Point c = (a + b) * 0.5L;
    ld r = sqrtl(dist2(c, a));
    return {c, r};
}

// circumcircle of triangle (a,b,c). If nearly collinear, returns invalid circle (r = -1).
Circle circle_from_3(const Point& a, const Point& b, const Point& c) {
    // Compute circumcenter using perpendicular bisector intersection
    Point ab = b - a;
    Point ac = c - a;
    ld d = 2.0L * cross(ab, ac);
    if (fabsl(d) < 1e-18L) return {{0,0}, -1}; // collinear / degenerate

    ld ab2 = norm2(ab);
    ld ac2 = norm2(ac);

    // Formula for circumcenter relative to a
    ld ux = (ac.y * ab2 - ab.y * ac2) / d;
    ld uy = (ab.x * ac2 - ac.x * ab2) / d;

    Point center = {a.x + ux, a.y + uy};
    ld r = sqrtl(dist2(center, a));
    return {center, r};
}

Circle minimum_enclosing_circle(vector<Point> pts) {
    // Random shuffle (important for expected linear time)
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(ALL(pts), rng);
    Circle C = {{0,0}, -1}; // invalid
    fore(i,0,sz(pts)){
        if (contains(C, pts[i])) continue;
        C = {pts[i], 0.0L};
        fore(j,0,i){
            if (contains(C, pts[j])) continue;

            C = circle_from_2(pts[i], pts[j]);

            fore(k,0,j){
                if (contains(C, pts[k])) continue;

                Circle C3 = circle_from_3(pts[i], pts[j], pts[k]);
                if (C3.r < 0) {
                    // points collinear: MEC is determined by farthest pair among (i,j,k)
                    Circle Cij = circle_from_2(pts[i], pts[j]);
                    Circle Cik = circle_from_2(pts[i], pts[k]);
                    Circle Cjk = circle_from_2(pts[j], pts[k]);
                    C = Cij;
                    if (Cik.r > C.r) C = Cik;
                    if (Cjk.r > C.r) C = Cjk;
                } else {
                    C = C3;
                }
            }
        }
    }

    return C;
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {(ld)x, (ld)y};
    }

    Circle C = minimum_enclosing_circle(pts);

    for (int i = 0; i < n; i++) {
        ld d = sqrtl(dist2(C.c, pts[i]));
        if (fabsl(d - C.r) <= EPS) cout << '1';
        else cout << '0';
    }
    cout << "\n";
    return 0;
}