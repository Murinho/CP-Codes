// Problem: A. Advanced Player Setup
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/A
// Memory Limit: 1024 MB
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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

const ll maxn = 1e5+50;
const ll maxk = 1010;
const ll mod = 1e9+7;

ll n,m,k,d[maxn],dp[maxk],deg[maxn];
vector < pii > g[maxn];

void cost_comp(){
	queue <ll> q;
	d[1] = 1;
	q.push(1);
	
	while(sz(q)){
		ll node = q.front();
		
		q.pop();
		
		for(auto &[signode, sigw] : g[node]){
			deg[signode]--;
			d[signode] += (d[node] + sigw);
			d[signode] = min(d[signode], k+1);
			if (deg[signode] == 0){
				q.push(signode);
			}
		}
	}
}

void solve(){
	cin >> n >> m >> k;

	fore(i,0,m){
		ll x,y,z;
		cin >> x >> y >> z;
		g[x].pb({y,z});
		deg[y]++;
	}
	
	cost_comp();
	
	//cout << "Costos: "<<nl;
	//fore(i,1,n+1) cout << d[i] << " ";
	//cout << nl ;
	
	// calculate dp:
	
	dp[0] = 1;
	for(int i = 1; i<=n; i++){
		if (d[i] > k || d[i] == 0) continue;
		for(ll j = k - d[i]; j>=0; j--){
			if (dp[j] == 0) continue;
			for(ll x = d[i]; j + x <= k; x += d[i]){
				dp[j + x] = (dp[j + x] + dp[j])%mod;
			}
		}
	}
	
	ll ans = 0;
	fore(i,1,k+1) ans = (ans + dp[i])%mod;
	
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