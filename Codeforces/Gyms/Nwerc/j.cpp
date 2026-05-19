#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define ld long double
#define pii pair <ll,ll>

using namespace std;

const int maxn = 12;
const int maxb = (1<<maxn);
const ld inf = 1e18;

struct Point{
    ld x,y;

    Point() {}
    Point (ld x, ld y): x(x), y(y) {}

    Point operator -(const Point &b) const { return Point{x-b.x, y-b.y};}

    ld magnitude() const { return sqrt((x*x) + (y*y)); }

    ld dist(const Point &b) { return (*this - b).magnitude();}
};

struct frac{
    ll num,den;

    frac() {}

    frac(ll num, ll den): num(num), den(den){
        if (!num) den = 1;
        if (num > 0 && den < 0) num = -num, den = -den;
    }
};

ld dp[maxb][maxn];
ll n;
vector <Point> a;
ld ans = inf;

ld mat[maxn][maxn];

void clean(){
    fore(i,0,maxb){
        fore(j,0,maxn) dp[i][j] = inf;
    }
}

void doit(ld slope){
    clean();

    queue <pii> q;
    fore(i,0,n){
        dp[(1<<i)][i] = 0.0;
        q.push({(1<<i),i});
    }

    while(sz(q)){
        auto [mk, node] = q.front();
        q.pop();

        ld cost = dp[mk][node];
        fore(i,0,n){
            if (!((1<<i)&mk)){
                ld aux = mat[node][i] - slope;

                ld add = a[node].dist(a[i]);

                add *= (abs(cos(aux)) + abs(sin(aux)));

                if (dp[mk + (1<<i)][i] == inf){
                    q.push({mk + (1<<i),i});
                }

                dp[mk + (1<<i)][i] = min(dp[mk + (1<<i)][i], cost + add);
            }
        }
    }

    fore(i,0,n){
        ans = min(ans, dp[(1<<n)-1][i]);
    }
}

int main(){
    fast;
    cin >> n;
    fore(i,0,n){
        int x,y;
        cin >> x >> y;
        a.pb(Point(x,y));
    }

    vector <ld> slopes;

    fore(i,0,n){
        fore(j,0,n){
            if (i != j){
                ll num = a[i].y - a[j].y;
                ll den = a[i].x - a[j].x;

                ld slope = atan2(num,den);
                
                slopes.pb(slope);

                mat[i][j] = slope;
            }
        }
    }

    for(auto &slope : slopes){
        doit(slope);
    }

    cout << fixed << setprecision(9) << ans << nl;
    return 0;
}