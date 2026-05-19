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

const ll mod = 1e9+7;
const ll maxn = 2e6+50;

ll n;
string s;
ll cnt=0,op=0;
ll f[maxn];

ll expo(ll x, ll pw){
	ll ret = 1;
	while(pw>0){
		if (pw&1) ret = (ret*x)%mod;
		x = (x*x)%mod;
		pw >>=1;
	}
	return ret;
}

bool valid(){
	if (n%2 == 1) return false;
	if (sz(s) > n) return false;
	
	for(auto &au : s){
		if (au == '(') cnt++, op++;
		else cnt--;
		
		if (cnt < 0) return false;
	}
	
	if (n-sz(s) < cnt) return false;
	
	return true;
}

void precalc(){
	f[0] = 1;
	fore(i,1,maxn) f[i] = (f[i-1] * i)%mod;
}

ll nck(ll a, ll b){
	ll x = (f[a-b]*f[b])%mod;
	return (f[a]*expo(x,mod-2))%mod;	
}

int main(){
    fast;
    precalc();
    cin >> n;
    cin >> s;
    
    if (!valid()){
    	cout << 0 << nl;
    }
    else{
    	ll ans = (nck(n - sz(s), n/2 - op) - nck(n - sz(s), n/2 - op - 1) + mod)%mod;
    	cout << ans << nl;
    }
    return 0;
}