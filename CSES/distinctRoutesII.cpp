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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 1000;

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

ll n,source,sink;
vector <FlowEdge> fe[maxn];
vi paths[maxn];
vector <pii> comp_paths;

void bfs(){
	int cnt = 0;
	queue < pii > q; //{current node, path id}.
	for(auto &e : fe[0]){
		if (e.flow > 0 && e.u < n){
			e.flow--;
			paths[cnt] = {0,e.u};
			q.push({e.u,cnt});
			cnt++;
		}
	}
	while(sz(q)){
		auto [node,pid] = q.front();
		q.pop();
		if (node == n-1){
			comp_paths.pb({sz(paths[pid]),pid});
			continue;
		}
		for(auto &e : fe[node]){
			if (e.flow > 0 && e.u < n){
				e.flow--;
				paths[pid].pb(e.u);
				q.push({e.u,pid});
				break;
			}
		}
	}
}

void solve(){
	ll m,k;
	cin>>n>>m>>k;
	source = n;
	sink = n + 1;
	Dinic dinic(n + 2,source,sink);
	
	dinic.add_edge(source,0,n); //from source to the first node.
	
	dinic.add_edge(n-1,sink,n); //from the last node to the sink.
	
	fore(i,0,m){
		int x,y;
		cin>>x>>y;
		x--, y--;
		dinic.add_edge(x,y,1);
	}
	
	ll mf = dinic.flow();
	cout<<"MF: "<<mf<<nl;
	
	if (mf < k){
		cout<<-1<<nl;
		return;
	}
	
	// compute the after flow:
	for(FlowEdge &e : dinic.edges){
		if (e.flow > 0){
			fe[e.v].pb(e);
		}
	}
	
	bfs();
	sort(ALL(comp_paths));
	// TODO:
	ll ans = 0;
	fore(i,0,k) ans += comp_paths[i].fst - 1;
	cout<<ans<<nl;
	
	fore(i,0,k){
		cout<<comp_paths[i].fst<<nl;
		for(auto &elm : paths[comp_paths[i].snd]) cout<<elm+1<<" ";
		cout<<nl;
	}
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}