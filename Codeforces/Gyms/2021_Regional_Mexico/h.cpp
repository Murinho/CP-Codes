#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fst first
#define snd second
#define pii pair <ll,ll>
#define nl '\n'
#define eb emplace_back
#define ALL(a) a.begin(), a.end()

using namespace std;

const ll maxn = 1e4+100;
const ll inf = 2e4+10;

struct FlowEdge{
    int v,u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap): v(v), u(u), cap(cap) {}
};

struct Dinic{
    const ll flow_inf = 1e18;
    vector <FlowEdge> edges;
    vvi adj;
    int n, m = 0;
    int s,t;
    vi level,ptr;
    queue <int> q;
    Dinic (int n, int s, int t): n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int v, int u, ll cap){
        edges.eb(v,u,cap);
        edges.eb(u,v,0);
        adj[v].pb(m);
        adj[u].pb(m+1);
        m += 2;
    }
    bool bfs(){
        while(sz(q)){
            int v = q.front();
            q.pop();
            for(int id : adj[v]){
                if (edges[id].cap - edges[id].flow < 1) continue;

                if (level[edges[id].u] != -1) continue;

                level[edges[id].u] = level[v]+1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed){
        if (pushed == 0) return 0;
        if (v == t) return pushed;

        for(ll &cid = ptr[v]; cid < sz(adj[v]); cid++){
            int id = adj[v][cid];
            int u =edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;

            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));

            if (tr == 0) continue;

            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }

        return 0;
    }

    ll flow(){
        ll f = 0;
        while(true){
            fill(ALL(level),-1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ALL(ptr),0);
            while(ll pushed = dfs(s,flow_inf)){
                f += pushed;
            }
        }
        return f;
    }
};

ll n,c[maxn][maxn];

int main(){
    fast;

    cin >> n;
    fore(i,1,n+1){
        string s;
        cin >> s;
        if (s == "*"){
            ll x;
            cin >> x;
            c[i][x] = inf;
        }
        else{
            ll k = stoi(s);
            fore(j,0,k){
                ll x;
                cin >> x;
                c[i][x]++;
            }
        }
    }

    int src = 0;
    int sink = n+1;
    
    Dinic dinic(sink+1,src,sink);

    dinic.add_edge(src,1,inf);

    fore(i,1,n+1){
        fore(j,1,n+1){
            if (j == 1){
                if (c[i][j] > 0){
                    dinic.add_edge(i,sink,c[i][j]);
                }
            }
            else{
                if (i != j && c[i][j] > 0){
                    dinic.add_edge(i,j,c[i][j]);
                }
            }
        }
    }

    ll mf = dinic.flow();

    if (mf >= inf) cout << "*" << nl;
    else cout << mf + 1<< nl;
    return 0;
}