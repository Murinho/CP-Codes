#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
#pragma GCC target("popcnt")

using namespace std;

const ll maxn = 5e4+10;

ll n,m,foundat=1,q;
ll low[maxn],disc[maxn],inStack[maxn],indeg[maxn],color[maxn];
vi adj[maxn],nadj[maxn];
vvi scc;
bitset<maxn>ans[maxn];
 
void dfs(int node, int antnode) {
    static stack <int> stk;
    low[node] = disc[node] = foundat;
    stk.push(node);
    inStack[node] = 1;
    foundat++;
    int children = 0;
    for (auto signode : adj[node]){
        if(disc[signode] == 0){
            children++;
            dfs(signode, node);
            low[node] = min(low[node], low[signode]);
        }
        else if (inStack[signode] == 1){
            low[node] = min(low[node], disc[signode]);
        } 
    }
    if (low[node] == disc[node]){
        vi scctem;
        while (true){
            ll topic = stk.top();
            stk.pop();
            scctem.pb(topic);
            inStack[topic] = 0;
            if (node == topic) break;
        }
        scc.pb(scctem);
    }
}

void bfs(){
    queue <int> q;
    fore(i,1,n+1) if (!indeg[i]){
        ans[i].set(i);
        q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto signode : nadj[node]){
            ans[signode] |= ans[node];
            indeg[signode]--;
            if (!indeg[signode]){
                ans[signode].set(signode);
                q.push(signode);
            }
        }
    }
}

int main(){
    fast;
    cin>>n>>m>>q;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[y].pb(x);
        indeg[x]++;
    }
    fore(i,1,n+1){
        if (!indeg[i] && !disc[i]) dfs(i,-1);
    }
    fore(i,1,n+1) if (!disc[i]) dfs(i,-1);
    fore(i,0,sz(scc)){
        for(auto elm : scc[i]) color[elm]=i;
    }

    //create the new graph:
    fore(i,1,n+1) indeg[i]=0;
    fore(i,1,n+1){
        for(auto au : adj[i]){
            if (color[i] != color[au]){
                //cout<<"insert: "<<color[i]<<" -> "<<color[au]<<nl;
                nadj[color[i]].pb(color[au]);
                indeg[color[au]]++;
            }
        }
    }
    bfs();
    while(q--){
        ll x,y;
        cin>>x>>y;
        if (ans[color[x]][color[y]]) cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
    }
    return 0;
}