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

// Do Eulerian path
ll n,m,vis[maxn],odd[maxn];
ll timer=1;
ostringstream ost;
vi g[maxn];
vector <pii> res;

void dfs(int anode, int node){
	vis[node] = timer++;
	for(auto &signode : g[node]){
		if (anode == signode) continue;
		
		if (!vis[signode]){
			dfs(node,signode);
			if (odd[signode]){
				res.pb({signode,node});
				odd[signode] = 0;
			}
			else{
				res.pb({node,signode});
				odd[node] ^= 1;
			}
		}
		else if (vis[node] > vis[signode]){
			res.pb({node,signode});
			odd[node] ^= 1;
		}
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
   	
   	fore(i,1,n+1) if (!vis[i]) dfs(i,i);
   	
   	if (accumulate(odd+1,odd+n,0)) cout << "IMPOSSIBLE" << nl;
   	else{
	   		for(auto &[x,y] : res) cout << x << " " << y << nl;
   	}
   	return 0;
}