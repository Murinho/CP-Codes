#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
#define RB(x) (x<n?r[x]:0)

using namespace std;

const ll maxn = 1e5+5;
const ll INF = 1e9+7;

struct Point {
    int64_t x, y;

    Point(int64_t x_, int64_t y_): x(x_), y(y_) {}

    Point operator - (const Point & p) const {
        return Point(x - p.x, y - p.y);
    }

    int64_t cross (const Point & p) const {
        return x * p.y - y * p.x;
    }

    int64_t cross (const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    int half () const {
        return int(y < 0 || (y == 0 && x < 0));
    }
};

map <ll,ll> M;
vector<Point> vertices;
ll cnt=0;
vi adj[maxn];

std::vector<std::vector<size_t>> find_faces() {
    size_t n = vertices.size();
    std::vector<std::vector<char>> used(n);
    for (size_t i = 0; i < n; i++) {
        used[i].resize(adj[i].size());
        used[i].assign(adj[i].size(), 0);
        auto compare = [&](size_t l, size_t r) {
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if (pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        std::sort(adj[i].begin(), adj[i].end(), compare);
    }
    std::vector<std::vector<size_t>> faces;
    for (size_t i = 0; i < n; i++) {
        for (size_t edge_id = 0; edge_id < adj[i].size(); edge_id++) {
            if (used[i][edge_id]) {
                continue;
            }
            std::vector<size_t> face;
            size_t v = i;
            size_t e = edge_id;
            while (!used[v][e]) {
                used[v][e] = true;
                face.push_back(v);
                size_t u = adj[v][e];
                size_t e1 = std::lower_bound(adj[u].begin(), adj[u].end(), v, [&](size_t l, size_t r) {
                    Point pl = vertices[l] - vertices[u];
                    Point pr = vertices[r] - vertices[u];
                    if (pl.half() != pr.half())
                        return pl.half() < pr.half();
                    return pl.cross(pr) > 0;
                }) - adj[u].begin() + 1;
                if (e1 == adj[u].size()) {
                    e1 = 0;
                }
                v = u;
                e = e1;
            }
            std::reverse(face.begin(), face.end());
            int sign = 0;
            for (size_t j = 0; j < face.size(); j++) {
                size_t j1 = (j + 1) % face.size();
                size_t j2 = (j + 2) % face.size();
                int64_t val = vertices[face[j]].cross(vertices[face[j1]], vertices[face[j2]]);
                if (val > 0) {
                    sign = 1;
                    break;
                } else if (val < 0) {
                    sign = -1;
                    break;
                }
            }
            if (sign < 0) {
                //faces.insert(faces.begin(), face);
            } else {
                faces.emplace_back(face);
            }
        }
    }
    return faces;
}

int geti(ll x, ll y){
    ll h = x*INF + y;
    if(M.find(h) != M.end())return M[h];
    M[h] = cnt;
    vertices.push_back({x,y});
    cnt++;
    return cnt-1;
}

ll getArea(vector <Point> poly){ //Calculo de area de poligono
    ll ans = 0;
    poly.pb(poly.front());
    fore(i,1,sz(poly)){
        ans += poly[i-1].cross(poly[i]);
    }
    return abs(ans);
}

int main(){
    fast;
    ll k;
    cin>>k;
    fore(i,0,k){
        Point p1 = Point(0,0), p2 = Point(0,0);
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        ll id1 = geti(p1.x,p1.y);
        ll id2 = geti(p2.x,p2.y);
        //cout<<id1<<" "<<id2<<nl;
        adj[id1].pb(id2);
        adj[id2].pb(id1);
    }

    std::vector<std::vector<size_t>> faces = find_faces();

    ld res = 0.0;
    for(auto face : faces){
        vector <Point> poly;
        for(auto elm : face) poly.pb(vertices[elm]);
        ld areaa = getArea(poly);
        res += (areaa*areaa);
    }
    cout<<fixed<<setprecision(18)<<res / 4.0<<nl;
    return 0;
}