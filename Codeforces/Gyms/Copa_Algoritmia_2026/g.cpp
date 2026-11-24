#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <utility>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#include <queue>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define f first
#define s second

using namespace std;

const ll maxn = 5000;

ll n,m,a[maxn][maxn],row[maxn],col[maxn];

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

int main(){
    fast;
    cin >> n >> m;
	int ones = 0;
    fore(i,0,n) {
        fore(j,0,m) {
            cin >> a[i][j];
			ones += a[i][j];
        }
    }

	int sumrow = 0, sumcol = 0;
    fore(i,0,n) cin >> row[i];
    fore(i,0,m) cin >> col[i];

	// check if the sum of row and columns ones are equal
	sumrow = accumulate(row, row+n, 0ll);
	sumcol = accumulate(col, col+m, 0ll);
	if (sumrow != sumcol) {
		cout << -1 << nl;
		return 0;
	}

	// build the flow graph
    int src = n + m;
    int sink = src + 1;
    FlowGraph g(sink + 1);

    fore(i,0,n) g.add(src, i, row[i], 0); // row

    fore(i,0,m) g.add(n + i, sink, col[i], 0); // column

    fore(i,0,n) { // interconect row and column with cost
        fore(j,0,m) {
            g.add(i, n + j, 1, 1-a[i][j]);
        }
    }

    auto [flow,cost] = g.mcmf(src, sink, inf);
    // cout << flow << " " << cost << nl;
	if (flow != accumulate(col, col+m, 0ll)) cout << -1 << nl;
	else{
		cout << ones - sumrow + (2*cost) << nl;
	}
    return 0;
}