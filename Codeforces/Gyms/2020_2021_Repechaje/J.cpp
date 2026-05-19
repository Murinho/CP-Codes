// Problem: J. Just Turn the Wheels!
// Contest: Codeforces - 2020-2021 ICPC - Gran Premio de Mexico - Repechaje
// URL: https://codeforces.com/gym/102966/problem/J
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
 
using namespace std;


void solve(){
	ll c,f,b,s;
	cin>>c>>f>>b>>s;
	ll mcd = __gcd(f,b);
	ll t = 12ll / __gcd(mcd,12ll);
	ll d = t * c;
	ll ans = t * (ll)ceil((ld)s * 12.0 / d);
	cout<<ans<<nl;
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}