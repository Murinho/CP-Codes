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

const ll maxn = 1e5+100;

ll n,m;
bool vis[maxn];
vi g[maxn],gg[maxn];
set <pii> st;
ll low[maxn],disc[maxn],inStack[maxn];
ll sccnt = 0,foundat=1;

void tarjan(int node, int antnode = -1){
	static stack <int> stk;
	low[node] = disc[node] = foundat;
	stk.push(node);
	inStack[node] = 1;
	foundat++;
	for (auto signode : gg[node]){
		if(disc[signode] == 0){
			tarjan(signode, node);
			low[node] = min(low[node], low[signode]);
		}
		else if (inStack[signode] == 1){
			low[node] = min(low[node], disc[signode]);
		} 
	}
	if (low[node] == disc[node]){ // for SCC's
		sccnt++;
		while (true){
			ll topic = stk.top();
			stk.pop();
			inStack[topic] = 0;
			if (node == topic) break;
		}
	}
}

void dfs(int node){
	vis[node] = true;
	
	for(auto &signode : g[node]){
		if (!st.count({node,signode})){
			st.insert({node,signode});
			st.insert({signode,node});
			gg[node].pb(signode);
		}
		if (!vis[signode]) dfs(signode);
	}
}

int main(){
    fast;
   	cin >> n >> m;
   	fore(i,0,m){
   		ll x,y;
   		cin >> x >> y;
   		g[x].pb(y);
   		g[y].pb(x);
   	}
   	
   	ll cnt = 0;
   	fore(i,1,n+1){
   		if (!vis[i]){
   			cnt++;
   			dfs(i);
   		}
   	}
   	
   	if (cnt >= 2){
   		cout << "IMPOSSIBLE" << nl;
   	}
   	else{
   		// run tarjan
	   	tarjan(1);
	   	
	   	if (sccnt == 1){
	   		fore(i,1,n+1){
	   			for(auto &elm : gg[i]) cout << i << " " << elm << nl;
	   		}
	   	} 
	   	else{
	   		cout << "IMPOSSIBLE" << nl;
	   	}
   	}
   	return 0;
}