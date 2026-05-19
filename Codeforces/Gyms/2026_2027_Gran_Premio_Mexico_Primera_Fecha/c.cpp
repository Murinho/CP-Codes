// Problem: C. Cactus Simple Path Queries
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+10;
const ll loga = 18;
const ll inf = 1e18;

struct Edge{
	ll to,w;	
};

vector < Edge > g[maxn];
ll n,m,q,color[maxn],pc[maxn],cycle_cnt=0;
bool has_cycle[maxn];
vi cycle_belong[maxn];
ll cycle_entry[maxn];
map <ll,ll> relabel[maxn]; // in the cycle what is the index of each node [0,1,2, ..., sz(cycle)-1]
map <pii,ll> edge_cost; // [a,b] = cost;
vi pref[maxn]; // prefix sum
bool ve[maxn],vc[maxn];
ll up[maxn][loga],vup[maxn][loga]; // for binary lifting
pii par_entry[maxn];
vvi cycles;
ll dep[maxn];
ll pw[maxn];

void precalc(){
	pw[0] = 1;
	fore(i,1,loga){
		pw[i] = (pw[i-1] * 2ll);
	}
}

void dfs_cycle(int u, int p){
	if (color[u] == 2) return;
	if (color[u] == 1){
		vi v;
		int cur = p;
		int incycle_id = 0;
		has_cycle[cur] = true;
		cycle_belong[cur].eb(cycle_cnt);
		relabel[cycle_cnt][cur] = incycle_id++;
		v.eb(cur);
		while(cur != u){
			// build the prefix sum
			pref[cycle_cnt].eb((sz(pref[cycle_cnt]) > 0 ? pref[cycle_cnt].back() : 0ll) + edge_cost[{cur,pc[cur]}]);
			cur = pc[cur];
			has_cycle[cur] = true;
			cycle_belong[cur].eb(cycle_cnt);
			relabel[cycle_cnt][cur] = incycle_id++;
			v.eb(cur);
		}
		pref[cycle_cnt].eb((sz(pref[cycle_cnt]) > 0 ? pref[cycle_cnt].back() : 0ll) + edge_cost[{cur,p}]);
		cycles.eb(v);
		cycle_cnt++;
		return;
	}
	pc[u] = p;
	color[u] = 1;
	for(auto &[v,w] : g[u]){
		if (v == pc[u]) continue;
		dfs_cycle(v,u);
	}
	color[u] = 2;
}

void dfs_entries(int u, int p, ll w){
	if (ve[u]) return;
	
	par_entry[u] = {p,w};
	
	ve[u] = true;
	
	for(auto &cycle_id : cycle_belong[u]){
		if (cycle_entry[cycle_id] == 0){
			cycle_entry[cycle_id] = u;
		}
	}
	
	// propagate
	for(auto &[v,w] : g[u]){
		if (!ve[v]){
			dfs_entries(v,u,w);
		}
	}
}

ll compute_cost(ll cycle_id, ll x, ll y){
	if (!relabel[cycle_id].count(x) || !relabel[cycle_id].count(y)){ // asert this doesn't happen
		return inf;
	}
	
	if (x == y) return 0;
	
	ll rx = relabel[cycle_id][x];
	ll ry = relabel[cycle_id][y];
	
	if (rx > ry) swap(rx,ry);
	
	// keep the minimum;
	
	ll aux = pref[cycle_id][ry-1];
	if (rx > 0) aux -= pref[cycle_id][rx-1];
	
	ll ret = min(pref[cycle_id].back() - aux, aux);
	return ret;
}

void build_cg(){
	vc[0] = true;
	queue <ll> q;
	q.push(0);
	up[0][0] = vup[0][0] = dep[0] = 0;
	
	while(sz(q)){
		ll cn = q.front();
		q.pop();
		
		// first check the cycle itself and cycle belongs:
		for(auto &cynode : cycles[cn]){
			for(auto &cycle_id : cycle_belong[cynode]){
				if (!vc[cycle_id]){
					ll weight = compute_cost(cn,cycle_entry[cn],cynode);
					if (weight == inf){
						cout << "warning inf: " << cn << " " << cycle_entry[cn] << " " << cynode << nl;
					}
					q.push(cycle_id);
					vc[cycle_id] = true;
					up[cycle_id][0] = cn;
					vup[cycle_id][0] = weight;
					dep[cycle_id] = dep[cn] + 1;
				}
			}
		}
		
		// second check if any adjacent nodes from current cycle belong to unseen cn_nodes
		for(auto &cynode : cycles[cn]){
			for(auto &signode : g[cynode]){
				for(auto &cycle_id : cycle_belong[signode]){
					if (!vc[cycle_id]){
						ll weight = compute_cost(cn,cycle_entry[cn],par_entry[signode].first) + par_entry[signode].second;
						if (weight == inf){
							cout << "warning inf: " << cn << " " << cycle_entry[cn] << " " << cynode << nl;
						}
						q.push(cycle_id);
						vc[cycle_id] = true;
						up[cycle_id][0] = cn;
						vup[cycle_id][0] = weight;
						dep[cycle_id] = dep[cn] + 1;
					}
				}
			}
		}
	}
}

void binary_lifting(){
	fore(i,1,loga){
		fore(j,0,cycle_cnt){
			up[j][i] = up[up[j][i-1]][i-1];
			vup[j][i] = vup[j][i-1] + vup[up[j][i-1]][i-1];
		}
	}
}

ll lca(ll x, ll y){
	if (x == y){
		return 0;
	}
	
	ll ret = 0;
	
	if (dep[x] > dep[y]) swap(x,y); // x will be the shallowest, so move y
	
	ll dif = dep[y] - dep[x] - 1;
	rofe(i,loga,0){
		if (dif <= pw[i]){
			dif -= pw[i];
			ret += vup[y][i];
			y = up[y][i];
		}
	}
	
	if (up[y][0] == x){
		return ret;
	}
	
	rofe(i,loga,0){
		if (up[x][i] != up[y][i]){
			ret += vup[x][i];
			ret += vup[y][i];
			x = up[x][i];
			y = up[y][i];
		}
	}
	
	// 
}

int main(){
    fast;
    precalc();
    cin >> n >> m >> q;
    fore(i,0,m){
    		ll x,y,w;
    		cin >> x >> y >> w;
    		g[x].pb({y,w});
    		g[y].pb({x,w});
    		edge_cost[{x,y}] = w;
    		edge_cost[{y,x}] = w;
    }
    
    // obtain the cycles
    fore(i,1,n+1){
    		if (color[i] == 0){
    			dfs_cycle(i,i);
    		}
    }
    
    // check which nodes do not belong to any cycle:
    fore(i,1,n+1){
    		if (!has_cycle[i]){
    			cycle_belong[i].pb(cycle_cnt);
    			pref[cycle_cnt].pb(0);
    			relabel[cycle_cnt][i] = 0;
    			has_cycle[i] = true;
    			
    			cycle_cnt++;
    		}
    }
    
    // print the prefix sums:
    fore(i,0,cycle_cnt){
    		cout << i << ": ";
    		for(auto &elm : pref[i]) cout << elm << " ";
    		cout << nl;
    }
    
    // calculate the entry points of each component
    dfs_entries(1,1);
    
    cout << "Entry points: " << nl;
    fore(i,0,cycle_cnt){
    		cout << i << ": " << cycle_entry[i] << nl;
    }
    
    // build the condensed graph 
    build_cg();
    
    // build the binary lifting with values 
	binary_lifting();
    		// -> also build the logic for lca
    		
    	// answer the queries
    	while(q--){
    		ll 
    	}
    	
   	
    
    return 0;
}