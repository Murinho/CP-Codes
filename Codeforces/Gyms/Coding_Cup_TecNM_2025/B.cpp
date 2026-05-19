// Problem: B. La campaña de Bob
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/B
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

const ll maxn = 1e5+100;
const ll inf = 1e18;

ll n;
ll vis[maxn][3];
vi g[maxn];
ll m;

void init(){
	fore(i,0,n+1){
		fore(j,0,3) vis[i][j] = inf;
	}
}	

ll bfs(int par){
	if (par > n) return inf;
	queue <ll> q;
	q.push(par);
	vis[par][par] = 1;
	ll timer=1;
	ll cur=par;
	
	while(sz(q)){
		ll node = q.front();
		
		q.pop();
		
		if (timer < vis[node][par]){
			cur += 2;
			timer++;
			if (vis[cur][par] > timer){
				vis[cur][par] = timer;
				q.push(cur);
			}
		}
		
		for(auto &signode : g[node]){
			if (vis[signode][par] > vis[node][par] + 1){
				q.push(signode);
				vis[signode][par] = vis[node][par] + 1;
			}
		}
	}
	
	ll ret=0;
	fore(i,1,n+1) ret = max(ret,vis[i][par]);
	return ret;
}

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,0,m){
    	ll x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    
   	ll ans = bfs(1);
   	ll ans2 = bfs(2);
    
    if (min(ans,ans2) == inf) cout << -1 << nl;
    else cout << min(ans,ans2) << nl;
    
    return 0;
}