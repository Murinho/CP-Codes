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

const ll maxn = 1e6+5;
const ll mod = 1e9+7;

ll good[maxn],alle[maxn];
ll nume = 1;
ll denom = 1;

ll bp(ll x, ll pw){ 
	ll res = 1;
	while(pw > 0){
		if(pw&1) res = (res*x)%mod;
		x = (x*x)%mod;
		pw >>= 1;
	}
	return res;
}

void precalc(){
	fore(i,3,maxn){
		// obtain good
		good[i] = (good[i-1] + ((i-1)/2ll))%mod;
		
		// obtain alle
		alle[i] = (alle[i-1] + (i-2))%mod;
	}
}

void solve(){
	ll n;
	cin >> n;
	nume = (nume*good[n])%mod;
	denom = (denom*alle[n])%mod;
	
	ll ret = (nume*bp(denom,mod-2))%mod;
	
	cout << ret << nl;
	return;
}

int main(){
    fast;
    precalc();
    ll tc;
    cin >> tc;
    while(tc--){
    	solve();
    }
}