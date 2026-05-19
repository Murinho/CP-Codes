#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 1005;
const ll maxb = 105;
const ll inf = 1e18;

ll dp[maxn][maxb];
ll stx,sty,enx,eny;
ll n,m,b,t;
ll c[maxb];
ll cx[maxn],cy[maxn];
vector <pii> g[maxn];

void init(){
    fore(i,0,maxn){
        fore(j,0,maxb) dp[i][j] = inf;
    }
}

ll dist(ll x, ll y, ll x2, ll y2){
    ll ed = ((x-x2)*(x-x2)) + ((y-y2)*(y-y2));

    ll sq = sqrt(ed);

    if (sq*sq == ed) return sq; // perfect square.

    return sq+1; // round up to the nearest integer.
}

void daikra(){
    priority_queue < array <ll,3>, vector < array <ll,3> >, greater < array <ll,3> > > pq;

    // initalize the dp.
    fore(i,0,n){
        ll dis = dist(stx,sty,cx[i],cy[i]);
        if (dis <= b){
            dp[i][dis] = dis*c[0];
            pq.push({dp[i][dis],i,dis});
        }
    }

    while(sz(pq)){
        auto [cost,node,dis] = pq.top();

        pq.pop();

        if (dp[node][dis] != cost) continue;

        for(auto &[signode,mode] : g[node]){
            ll add_dis = dist(cx[node],cy[node],cx[signode],cy[signode]);
            ll add_cost = add_dis * c[mode];

            ll sigcost = cost + add_cost;
            ll sigdis = dis + add_dis;

            if (sigdis <= b && sigcost < dp[signode][sigdis]){
                dp[signode][sigdis] = sigcost;
                pq.push({sigcost,signode,sigdis});
            }
        }
    }
}

int main(){
    fast;
    init();
    cin >> stx >> sty;
    cin >> enx >> eny;
    cin >> b;
    cin >> c[0];
    cin >> t;
    fore(i,1,t+1) cin >> c[i];

    cin >> n;
    fore(i,0,n){
        ll k;
        cin >> cx[i] >> cy[i] >> k;
        fore(j,0,k){
            ll ot,mode;
            cin >> ot >> mode;
            g[i].pb({ot,mode});
            g[ot].pb({i,mode});
        }
    }

    daikra();

    ll ans = inf;

    // directly from the source to the destination.
    if (dist(stx,sty,enx,eny) <= b){
        ans = min(ans, dist(stx,sty,enx,eny) * c[0]);
    }

    // from any station to the destination:
    fore(i,0,n){
        fore(j,0,b+1){
            ll remdis = dist(cx[i],cy[i],enx,eny);
            ll remcost = remdis * c[0];
            if (j + remdis <= b){
                ans = min(ans,dp[i][j] + remcost);
            }
        }
    }

    if (ans >= inf) cout << -1 << nl;
    else cout << ans << nl;
    return 0;
}