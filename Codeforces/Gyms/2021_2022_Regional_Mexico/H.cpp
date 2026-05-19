// Problem: H. Hamilton - The Musical
// Contest: Codeforces - 2021-2022 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103640/problem/H
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 515;
const ll inf = 1e18+7;

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

ll n,a[maxn][maxn];

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
    	fore(j,1,n+1) cin >> a[i][j];
    }
    
    ll fn = (n/2) + (n%2); // left side of the matching (odd nodes)
    
    int src = 0;
    int sink = (2*fn) + 1;
    FlowGraph g(sink + 1);
    
    fore(i,1,fn+1){
    	g.add(src,i,1,0); // add from source to nodes.
    	//cout << src << "--> " << i << " c: " << 0 << nl;
    }
    
    fore(i,fn+1,(2*fn) + 1){
    	 g.add(i,sink,1,0); // add from nodes to sink.
    	 //cout << i << "--> " << sink << " c: " << sink << nl;
    }
    
    // add between nodes.
    fore(i,1,fn+1){
    	ll id = ((i-1)*2)+1;
    	fore(j,fn+1,(2*fn)+1){
    		ll sig = (j-fn)*2;
    		ll pv = sig-2;
    		
    		ll cost = a[pv][id] + a[id][sig];
    		g.add(i,j,1,cost);
    	}
    }
    
    pii res = g.mcmf(src,sink,inf);
    
    cout << res.snd << nl;
    return 0;
}