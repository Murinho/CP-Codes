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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll mod = 1e9+7;
const ll maxn = 1e6+5;

ll f[maxn];

void precalc(){
	f[0] = 1;
	fore(i,1,maxn){
		f[i] = (f[i-1]*i)%mod;
	}
	return;
}

ll bp(ll x, ll pw){
	ll ret = 1;
	while(pw>0){
		if (pw&1) ret = (ret*x)%mod;
		x = (x*x)%mod;
		
		pw >>= 1;
	}
	
	return ret;
}

ll nck(ll n, ll k){
	if (n < k) return 0;
	ll denom = (f[n-k]*f[k])%mod;
	ll inve = bp(denom,mod-2);
	return (f[n]*inve)%mod;
}

void solve(){
	ll n;
	cin >> n;
	if (n <= 2){
		cout << 0 << nl;
		return;
	}
	ll odds = (n/2) + (n%2);
	ll evens = (n/2);
	
	ll ans = nck(evens,3);
	ans += nck(odds,2)*evens;
	ans %= mod;
	cout << ans << nl;
}

int main(){
    fast;
    ll tc;
    precalc();
    cin >> tc;
    while(tc--){
    	solve();
    }
}