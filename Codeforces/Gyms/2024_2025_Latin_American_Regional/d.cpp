// Problem: D. Diverse T-Shirts
// Contest: Codeforces - 2024-2025 ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/105505/problem/D
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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

const ll maxn = 1005;

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

vvi cliques;
ll n;
char a[maxn][maxn];
bool vis[maxn][maxn];

int main(){
    fast;
   	cin >> n;
   	fore(i,1,n+1){
   		fore(j,1,n+1) cin >> a[i][j];
   	}
   	
   	// formar las cliques maximales:
   	fore(i,1,n+1){
   		fore(j,1,n+1){
   			if (a[i][j] == '1' && !vis[i][j]){
   				vi clique = {i,j};
   				fore(x,1,n+1){
   					if (i != x && j != x && a[i][x] == '1' && a[j][x] == '1' && !vis[i][x] && !vis[j][x]){
   						clique.pb(x);
   					}
   				}
   				// mark the used edges of the original input.
   				fore(ii,0,sz(clique)){
   					fore(jj,0,sz(clique)){
   						vis[clique[ii]][clique[jj]] = true;
   					}
   				}
   				// save the clique to list of cliques.
   				cliques.pb(clique);
   			}
   		}
   	}
   	
   	// --- build the bipartite graph of cliques ---
   	int C = (int)cliques.size();

   	// For each vertex (model) store the two clique indices it belongs to.
   	vector<array<int,2>> belong(n+1, array<int,2>{-1,-1});
   	vector<int> cnt(n+1, 0);

   	// Fill belong by scanning cliques
   	fore(cid,0,C){
   		for(int v : cliques[cid]){
   			if (cnt[v] < 2){
   				belong[v][cnt[v]] = cid;
   				cnt[v]++;
   			}
   		}
   	}

   	// Handle isolated models (degree 0 in conflict graph):
   	// they didn't appear in any clique; create two singleton cliques {v}.
   	fore(v,1,n+1){
   		if (cnt[v] == 0){
   			cliques.pb(vi{v});
   			int c1 = (int)cliques.size()-1;
   			cliques.pb(vi{v});
   			int c2 = (int)cliques.size()-1;
   			belong[v] = {c1,c2};
   			cnt[v] = 2;
   		} else if (cnt[v] == 1){
   			// Rare fallback: add a second singleton clique if only one found
   			cliques.pb(vi{v});
   			int c2 = (int)cliques.size()-1;
   			belong[v][1] = c2;
   			cnt[v] = 2;
   		}
   	}
   	C = (int)cliques.size();

   	// Build clique adjacency via shared models (to 2-color cliques)
   	vector<vector<int>> cadj(C);
   	fore(v,1,n+1){
   		int c0 = belong[v][0], c1 = belong[v][1];
   		if (c0 != -1 && c1 != -1 && c0 != c1){
   			cadj[c0].pb(c1);
   			cadj[c1].pb(c0);
   		}
   	}

   	// 2-color the clique graph (it is bipartite)
   	vector<int> side(C, -1);
   	fore(c,0,C){
   		if (side[c] != -1) continue;
   		queue<int> q; q.push(c); side[c] = 0;
   		while(!q.empty()){
   			int u = q.front(); q.pop();
   			for(int w : cadj[u]){
   				if (side[w] == -1){
   					side[w] = side[u]^1;
   					q.push(w);
   				}
   			}
   		}
   	}

   	// Map cliques into flow nodes
   	vector<int> idL(C, -1), idR(C, -1);
   	int L = 0, R = 0;
   	fore(c,0,C){
   		if (side[c] == 0) idL[c] = ++L;
   		else idR[c] = ++R;
   	}

   	// Build Dinic network: nodes = 1..L (left cliques), then L+1..L+R (right cliques)
   	// source = 0, sink = L+R+1
   	int SRC = 0, SNK = L + R + 1;
   	Dinic din(SNK + 1, SRC, SNK);

   	// Source to left cliques; right cliques to sink
   	fore(c,0,C){
   		if (side[c] == 0){
   			din.add_edge(SRC, idL[c], 1);
   		}else{
   			din.add_edge(L + idR[c], SNK, 1);
   		}
   	}

   	// For each model v, add one edge between its two clique nodes (from left side to right side)
   	fore(v,1,n+1){
   		int c0 = belong[v][0], c1 = belong[v][1];
   		if (c0 == -1 || c1 == -1) continue;
   		int u = c0, w = c1;
   		// ensure u on left, w on right
   		if (side[u] == 1) swap(u,w);
   		// If both somehow fell on same side (shouldn't happen), skip.
   		if (side[u] == side[w]) continue;
   		int U = (side[u]==0 ? idL[u] : L + idR[u]);
   		int W = (side[w]==0 ? idL[w] : L + idR[w]);
   		din.add_edge(U, W, 1);
   	}

   	// run Dinic's and obtain the max-matching
   	ll ans = din.flow();
   	cout << ans << nl;
   	
   	return 0;
}
