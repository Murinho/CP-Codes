#include <bits/stdc++.h>
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
 
using namespace std;
 
static const ll inf = 2e18+1;
static const ll maxp = 19;
 
static ll pre[maxp],pw[maxp],nine[maxp];
ll n;
 
static inline void precalc(){
	ll pt = 1;
	pre[0] = 0;
	pre[1] = 1;
	pw[0] = 1;
	pw[1] = 2;
	nine[0] = 1;
	nine[1] = 9;
	fore(i,2,maxp){
		pt *= 10ll;
		pre[i] = (pre[i-1]*10) + pt;
		pw[i] = (pw[i-1]*2ll);
		nine[i] = (nine[i-1]*9ll);
	}
}
 
static inline pii gen_masks(ll k, ll &pones){
	ll ret = 0;
	ll ret2 = 0;
	fore(mk,0,pw[k]){
		ll ones = __builtin_popcountll(mk);
		ll mult = nine[k-ones];
		ret += (ones + pones) * mult;
		ret2 += (ones + pones + 1ll) * mult;
		ret = min(ret,inf);
		ret2 = min(ret2,inf);
	}
	return {ret,ret2};
}
 
static inline ll check(ll &tope){
	string s = to_string(tope);

	ll ret = 0;
	ll ones = 0;
	
	fore(i,0,sz(s)){
		ll val = s[i]-'0';
		if (val > 0){
			pii gmk = gen_masks(sz(s)-i-1, ones);

			ll cnto = (val-1 >= 1 ? 1 : 0);
			ll cntnorm = (val-1)-cnto + (i == 0 ? 0 : 1);
			if (cnto){
				ret += gmk.s;
				if (ret > n) return n+1;
				ret = min(ret,inf);
			}
			if (cntnorm){
				ret += gmk.f * cntnorm;
				if (ret > n) return n+1;
			}
		}
		
		if (val == 1) ones++;
	}
	ret += ones;
	
	return ret;
}

int main(){
	fast;
	precalc();
	cin >> n;
   	ll l = 1;
   	ll r = 524638270000000001;
 
   	while(l < r){
   		ll mid = (l+r+1)/2ll;
   		ll ret = check(mid);
   		ll pt = 1e18;
   		ll curpt = 18;
   		while(pt > mid) pt /= 10ll, curpt--;
   		
   		ret += pre[curpt];
   		ret = min(ret,inf);
   		
   		if (ret <= n) l = mid;
   		else r = mid-1;
   	}
   	
   	cout << l << nl;
    
	return 0;
}