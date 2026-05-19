// Problem: D. 21188720-2ee7-481f-9503-3b768a1fd83b
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e5+10;
const ll inf = 1e18;
ll n,m;
ll c[maxn];
ll d[maxn][2]; // bfs distance, daikra distance.
vector < pii > g[maxn];

void init(){
	fore(i,0,n+1){
		fore(j,0,2) d[i][j] = inf;
	}
}

void prim(){
	priority_queue < pii, vector <pii>, greater <pii> > pq;
	
	pq.push({0,1}); // {distance, node}.
	
	d[1][1] = 0;
	
	while(sz(pq)){
		auto [dis,node] = pq.top();
		pq.pop();
		
		if (d[node][1] != dis) continue;
		
		for(auto &[signode, sigw] : g[node]){
			if (d[node][0] + 1 != d[signode][0]) continue; // tienen que ser parte de la siguiente capa de la bfs.
			
			ll cost = (sigw * d[signode][0]);
			if (cost < d[signode][1]){
				d[signode][1] = cost;
				pq.push({cost,signode});
			}
		}
	}
}

void bfs(){
	d[1][0] = 0;
	queue <ll> q;
	q.push(1);
	while(sz(q)){
		ll node = q.front();
		q.pop();
		
		for(auto &[signode, sigw] : g[node]){
			if (d[node][0] + 1 < d[signode][0]){
				d[signode][0] = d[node][0] + 1;
				q.push(signode);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	init();
	fore(i,0,m){
		ll x,y,z;
		cin >> x >> y >> z;
		g[x].pb({y,z});
		g[y].pb({x,z});
	}
	
	bfs();
	
	prim();
	
	ll ans = 0;
	fore(i,1,n+1) ans += d[i][1];
	
	cout << ans << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}