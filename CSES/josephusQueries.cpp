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

ll n,k;
ll pt,rem;
vi v;

void print(){
	for(int i = rem; i<=n; i += pt){
		v.pb(i);
	}
}

void solve(){
	cin >> n >> k;
	
	bool f = false;
	
	if (k == n){
		f = true;
	}
	
	if (n == 1){
		cout << 1 << nl;
		return;
	}
	
	v.clear();
	
	pt = 2;
	rem = 2;
	while(1){
		ll cnt = ((n-rem)/pt)+1;
		if (cnt >= k){
			ll ans = rem + ((k-1)*pt);
			if (f){
				cout << ans%(pt/2) << nl;
			}
			else{
				cout << ans << nl;
			}
			break;
		}
		
		// print();
		
		k -= cnt;
		
		ll las = rem + ((cnt-1)*pt);
		// cout << pt << " " << rem << " (las): " << las << nl;
		
		rem %= pt;
		
		ll op1 = (rem+(pt/2));
		ll op2 = (op1 + pt);
		op1 %= (pt*2);
		op2 %= (pt*2);
		if (op1 > op2) swap(op1,op2);
		
		// cout << pt << " " << rem << " (las): " << las << " (op1): " << op1 << " (op2): " << op2 << nl;
		
		if (las + (pt/2) <= n){ // la siguiente ronda arranca en el modulo chico
			rem = op1;
		}
		else{ // la siguiente ronda arranca en el modulo grande
			rem = op2;
		}
		
		pt *= 2ll;
	}
	
	// for(auto &elm : v) cout << elm << " ";
	// cout << nl;
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}