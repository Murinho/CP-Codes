#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a)((int)a.size())
#define lsb(x)((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 1e5+5;
const ll mod = 1e9+7;
const ll INF = 1e18;

vector < pii > adj[maxn]; //{next node, cost}.
ll n,m,dp[maxn][4]; //0: cost, 1: count, 2: short, 3: long.

priority_queue< pair <ll,ll> , vector< pair <ll,ll> >, greater< pair <ll,ll> > > pq; //weight, node.

void init(){
    fore(i,0,n+1) dp[i][0]=INF;
}

void daikra(){
    dp[1][0]=0,dp[1][1]=1,dp[1][2]=0,dp[1][3]=0;
    pq.push({dp[1][0],1});
    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();
        ll w = p.fst;
        ll node = p.snd;
        if (dp[node][0] != w) continue;
        for(auto au : adj[node]){
            ll signode = au.fst;
            ll sigw = au.snd;
            if (dp[node][0] + sigw < dp[signode][0]){
                dp[signode][0] = dp[node][0] + sigw; //mincost
                dp[signode][1] = dp[node][1]; //count of paths.
                dp[signode][2] = dp[node][2] + 1; //smaller amount of edges traversed.
                dp[signode][3] = dp[node][3] + 1; //biggest amount of edges traversed. 
                pq.push({dp[signode][0],signode});
            }
            else if (dp[node][0] + sigw == dp[signode][0]){
                dp[signode][1] = (dp[signode][1] + dp[node][1])%mod;
                dp[signode][2] = min(dp[signode][2], dp[node][2] + 1);
                dp[signode][3] = max(dp[signode][3], dp[node][3] + 1);
            }
        }
    }
}


int main(){
    fast;
    cin>>n>>m;
    init();
    fore(i,0,m){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].pb({y,z});
    }
    daikra();
    fore(i,0,4) cout<<dp[n][i]<<" ";
    cout<<nl;
    return 0;
}