// Problem: K. Krystalova's Trivial Problem
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/K
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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 1e5+100;
const ll mod = 1e9+7;
ll n,q,a[maxn],res;

void solve(){
	cin >> n >> q;
	fore(i,1,n+1){
		cin >> a[i];
	}
	while(q--){
		char c;
		ll l,r,x;
		cin >> c;
		if (c == 'u'){
			cin >> l >> r >> x;
			if (x != 0){
				fore(i,l,r+1) a[i] = (a[i] + x)%mod;
			}
			
		}
		else{
			cin >> l >> r;
			res = 0;
			fore(i,l,r+1) res = (res + (a[i]*a[i])%mod)%mod;
			cout << res << nl;
		}
	}
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}