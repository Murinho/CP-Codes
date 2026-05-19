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

const ll maxn = 2e5+10;
ll n,x,y,m,foundat=1;
ll low[maxn],disc[maxn],isArt[maxn],inStack[maxn];
vector <ll> adj[maxn];
vector < vector <ll> > scc;
vector < pair <ll,ll> > brid;
 
void dfs(int node, int antnode) {
    static stack <int> stk;
    low[node] = disc[node] = foundat;
    stk.push(node);
    inStack[node] = 1;
    foundat++;
    int children = 0;
    for (auto signode : adj[node]){
        if(!disc[signode]){
            children++;
            dfs(signode, node);
            if (low[signode] > disc[node]){
                brid.pb({node,signode});
            }
            low[node] = min(low[node], low[signode]);
            if (antnode == -1 && children > 1) isArt[node] = 1;
            if (antnode != -1 && low[signode] >= disc[node]) isArt[node] = 1;
        }
        else if (antnode != signode){
            low[node] = min(low[node], disc[signode]);
        } 
    }
}

int main(){
    fast;
    cin>>n>>m;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);    
    }
    fore(i,1,n+1) if (!disc[i]) dfs(i,-1);

    vi arts;
    fore(i,1,n+1) if (isArt[i]) arts.pb(i);

    cout<<sz(arts)<<nl;
    for(auto au : arts) cout<<au<<" ";
    cout<<nl;
    return 0;
}