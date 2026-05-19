// Problem: E. Dead-End Detector
// Contest: Codeforces - 2019 ICPC World Finals
// URL: https://codeforces.com/gym/102511/problem/E
// Memory Limit: 512 MB
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
 
using namespace std;

const ll maxn = 1e6+5;

ll n,m;
ll foundat=1;
ll low[maxn],disc[maxn],who_scc[maxn],vis[maxn],f[maxn];
ll scc_cnt = 0;
vi g[maxn],ng[maxn];
vector <pii> deds;

void init(){
	fore(i,0,(n*2)+1){
		f[i] = -1;
	}
}

void tarjan(int node, int antnode){ //first call antnode should be = -1.
    static stack <int> stk;
    low[node] = disc[node] = foundat;
    stk.push(node);
    foundat++;
    for (auto signode : g[node]){
        if(disc[signode] == 0){
            tarjan(signode, node);
            low[node] = min(low[node], low[signode]);
        }
        //When wanting to find SCC's:
        else if (antnode != signode){
            low[node] = min(low[node], disc[signode]);
        }
    }
    if (low[node] == disc[node]){ // for SCC's
        vi v;
        while (true){
            ll topic = stk.top();
            stk.pop();
            v.pb(topic);
            if (node == topic) break;
        }
        if (sz(v) >= 3){
        	scc_cnt++;
        	//cout << "SCC: " << nl;
        	for(auto &elm : v){
        		//cout << elm << " ";
        		who_scc[elm] = scc_cnt;
        	}
        	//cout << nl;
        }
    }
}

void visit_dfs(int anode, int node){
	vis[node]++;
	for(auto &signode : g[node]){
		if (anode == signode || vis[signode] >= 2 || who_scc[signode] > 0) continue;
		visit_dfs(node,signode);
	}
}

void acum_dfs(int anode, int node){
	f[node] = 0;
	if (node > n) f[node]++;
	
	for(auto &signode : ng[node]){
		if (anode == signode) continue;
		acum_dfs(node,signode);
		f[node] += f[signode];
	}
	
	//cout << node << ": " << f[node] << nl;
	return;
}

void compute_dfs(int anode, int node, ll &root){
	for(auto &signode : ng[node]){
		if (anode == signode){
			if (f[root] == f[node]){
				deds.pb({node,signode});
			}
		}
		else{
			if (f[signode] == 0){
				deds.pb({node,signode});
			}
			else{
				compute_dfs(node,signode,root);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	init();
	fore(i,0,m){
		ll x,y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	fore(i,1,n+1){
		if (!disc[i]){
			tarjan(i,-1);
		}
	}
	
	fore(i,1,n+1){
		if (who_scc[i] == 0) continue;
		
		for(auto &signode : g[i]){
			if (vis[signode] >= 2 || who_scc[signode] > 0) continue;
			visit_dfs(i,signode);
		}
	}
	
	fore(i,1,n+1){
		if (who_scc[i] > 0) continue;
		
		if (vis[i] == 0){ // this is good.
			if (sz(g[i]) == 1){
				deds.pb({i,g[i][0]});
			}
		}
	}
	
	fore(i,1,n+1){
		for(auto &signode : g[i]){
			ll nid = (who_scc[i] > 0 ? n + who_scc[i] : i);
			ll nid2 = (who_scc[signode] > 0 ? n + who_scc[signode] : signode);
			if (nid != nid2) ng[nid].pb(nid2);
		}
	}
	
	/*
	fore(i,1,n+scc_cnt+1){
		for(auto &signode : ng[i]){
			cout << i << " --> " << signode << nl;
		}
	} */
	
	// Acumulate and compute.
	fore(i,1,n+scc_cnt+1){
		if (f[i] == -1){
			acum_dfs(i,i);
			if (f[i] > 0){
				compute_dfs(i,i,i);
			}
		}
	}
	
	sort(ALL(deds));
	
	cout << sz(deds) << nl;
	for(auto &[u,v] : deds) cout << u << " " << v << nl;

	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}