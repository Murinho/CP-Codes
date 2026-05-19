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

ld p,a,b,c,d;
ll n;

ld f(ld k){
	return p*((sin((a * k) + b)) + cos((c * k) + d) + 2);
}

void solve(){
	cin>>p>>a>>b>>c>>d>>n;
	vector <ld> stk; // largest at the bottom, smallest at the top.
	
	ld ans = 0.0;
	fore(i,1,n+1){
		ld ret = f(i);
		while(sz(stk) && stk.back() < ret) stk.ppb();
		stk.pb(ret);
		ans = max(ans,stk.front()-stk.back());
	}
	cout<<fixed<<setprecision(8)<<ans<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}