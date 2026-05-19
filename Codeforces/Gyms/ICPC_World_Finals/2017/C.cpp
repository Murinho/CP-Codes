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
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 105;

struct FlowEdge {
	int v, u;
	ll cap, flow = 0;
	FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
	const ll flow_inf = 1e18;
	vector<FlowEdge> edges;
	vvi adj;
	int n, m = 0;
	int s, t;
	vi level, ptr;
	queue<int> q;
	Dinic(int n, int s, int t) : n(n), s(s), t(t){
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}
	void add_edge(int v, int u, ll cap){ // v -> u
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}
	bool bfs(){
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap - edges[id].flow < 1) continue;
				if (level[edges[id].u] != -1) continue;

				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}
	ll dfs(int v, ll pushed) {
		if (pushed == 0) return 0;
		if (v == t) return pushed;
		for (ll& cid = ptr[v]; cid < sz(adj[v]); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;

			ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0) continue;
			
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}
	ll flow(){ // run the algorithm.
		ll f = 0;
		while (true) {
			fill(ALL(level), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs()) break;
			fill(ALL(ptr), 0);
			while (ll pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
}; // initialize dinic(size,source_index,sink_index).

ll a[maxn][maxn],n,m,ans=0,rmx[maxn],cmx[maxn],used_cells=0;
map <ll,ll> fr,fc;

void solve(){
	cin>>n>>m;
	
	set <ll> st;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			rmx[i] = max(rmx[i],a[i][j]);
			cmx[j] = max(cmx[j],a[i][j]);
			if (a[i][j] > 0){
				st.insert(a[i][j]);
				used_cells++;
				ans += a[i][j];
			}
		}
	}
	
	int source = 0;
	int sink = 1;
	
	for(auto &val : st){
		int nr = 0;
		int nc = 0;
		Dinic dinic(n+m+2,source,sink);
		vi rows,cols;
		fore(i,0,n){
			if (rmx[i] == val){
				dinic.add_edge(source,i + 2,1);
				nr++;
				rows.pb(i);
			}
		}
		fore(i,0,m){
			if (cmx[i] == val){
				dinic.add_edge(n + i + 2,sink,1);
				nc++;
				cols.pb(i);
			}
		}
		for(auto &r : rows){
			for(auto &c : cols){
				if (a[r][c] > 0){
					dinic.add_edge(r + 2, n + c + 2,1);
				}
			}
		}		
		
		
		ll use = nr + nc - dinic.flow();
		used_cells -= use;
		ans -= use * val;
	}
	
	ans -= used_cells;
	cout<<ans<<nl;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}