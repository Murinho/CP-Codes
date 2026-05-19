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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t

using namespace std;

const ll inf = 1e18+7;
const ll maxn = 105;

struct FlowGraph {
 
    struct Edge {
        ll to, flow, cap, cost;
        Edge *res;
 
        Edge () : to(0), flow(0), cap(0), cost(0), res(0) {}
        Edge (ll to, ll flow, ll cap, ll cost) : to(to), flow(flow), cap(cap), cost(cost), res(0) {}
    
        void addFlow (ll f) {
            flow += f;
            res->flow -= f;
        }
    };
 
 	ll n;
    vector<vector<Edge*>> adj;
    vi dis, pos;
    
 
    FlowGraph (int n) : n(n), adj(n), dis(n), pos(n) {} 
 
    void add (int u, int v, ll cap, ll cost) {
        Edge *x = new Edge(v, 0, cap, cost);
        Edge *y = new Edge(u, cap, cap, -cost);
        x->res = y;
        y->res = x;
        adj[u].pb(x);
        adj[v].pb(y);
    }
 
    pii mcmf(int s, int t, ll tope) {
        vector<bool> inq(n);
        vi dis(n), cap(n);
        vector<Edge*> par(n);
        ll maxFlow = 0, minCost = 0;
 
        while (maxFlow < tope) { //  compute MCF: maxflow < tope, compute MCMF maxflow < inf 
            fill(ALL(dis), inf);
            fill(ALL(par), nullptr);
            fill(ALL(cap), 0);
            dis[s] = 0;
            cap[s] = inf;
            queue<int> q;
            q.push(s);
 
            while (sz(q)) {
                int u = q.front();
                q.pop();
                inq[u] = 0;
 
                for (Edge *v : adj[u]) {
                    if (v->cap > v->flow && dis[v->to] > dis[u] + v->cost) {
                        dis[v->to] = dis[u] + v->cost;
                        par[v->to] = v;
                        cap[v->to] = min(cap[u], v->cap - v->flow);
                        
                        if (!inq[v->to]) {
                            q.push(v->to);
                            inq[v->to] = 1;
                        }
                    }
                }
            }
 
            if (!par[t]) break;
 
            maxFlow += cap[t];
            minCost += cap[t] * dis[t];
            for (int u = t; u != s; u = par[u]->res->to)
                par[u]->addFlow(cap[t]);
        }
 
        return {maxFlow, minCost};
    }
};

ll n,k;
ll cost[maxn][maxn];

void doit(){
    // define src and sink.
    // edges src to node, and node to sink have cost 0.
    // to compute flow matches (e.g assignment problems), run dfs over the flow graph, keep the path and substract one unit of flow every time.
}

void solve(){
	cin >> n >> k;
	fore(i,1,n+1){
		for(int j = 1; j<=n-i+1; j++){
			cin >> cost[i][i + j];
		}
	}
	
	FlowGraph flow(2*n + 2);
	int source = 0;
	int sink = 1;
	
	// connect the source with all left side.
	for(int i = 2; i<=n+1; i++){
		flow.add(source,i,1,0);
	}
	
	// connect all right side with the sink.
	
	flow.add(n + 2,sink,k,0); // the company.
	
	for(int i = 2; i<=n; i++){
		flow.add(n+1+i,sink,1,0);
	}
	
	// connect with nodes in between.
	for(int i = 2; i<=n+1; i++){
		for(int j = 1; j<i; j++){
			flow.add(i,n+1+j,1,cost[j][i]);
		}
	}
	
	pii res = flow.mcmf(source,sink,inf);
	
	cout << res.snd << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}