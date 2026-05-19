// Problem: J. Just Send the Email
// Contest: Codeforces - 2021 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103274/problem/J
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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

const ll maxn = 1e5+100;
const ll mod = 998244353;
ll n,d[maxn],out[maxn];
vi g[maxn];

ll expo(ll x, ll pw){ 
    ll res = 1;
    while(pw > 0){
        if(pw&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        pw >>= 1;
    }
    return res;
}

void bfs(){
	queue <int> q;
	fore(i,1,n+1){
		if (!out[i]){
			q.push(i);
			d[i]=1;
		}
	}
	while(sz(q)){
		int node = q.front();
		q.pop();
		
		for(auto &signode :g[node]){
			if (d[signode] == 0){
				d[signode] = d[node] + 1;
				q.push(signode);
			}
		}
	}
}


void solve(){
	cin>>n;
	fore(i,2,n+1){
		int x;
		cin>>x;
		out[x]++;
		g[x].pb(i);
		g[i].pb(x);
	}
	
	bfs();
	
	ll num = 0;
	fore(i,1,n+1) num += d[i];
	
	ll inv = expo(n,mod-2);
	ll ans = (num*inv)%mod;
	cout<<ans<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}