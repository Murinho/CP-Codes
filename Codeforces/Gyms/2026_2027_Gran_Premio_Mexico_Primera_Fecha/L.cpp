// Problem: L. Legendary Sort
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/L
// Memory Limit: 256 MB
// Time Limit: 500 ms
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

const ll maxn = 2e5+50;

struct Fen{
	ll n;
	vi arr;
	Fen(int n): n(n), arr(n+1) {}
	
	void clean(){
		arr.clear();
		arr.resize(n+1,0);
	}
	
	void add(ll x, ll v){
		while(x <= n){
			arr[x] += v;
			x += lsb(x);
		}
	}
	
	ll get(ll x){
		ll fq = 0;
		while(x > 0){
			fq += arr[x];
			x -= lsb(x);
		}
		return fq;
	}
	
	ll query(ll l, ll r){
		if (l > r) return 0;
		
		ll ret = get(r);
		if (l > 1) ret -= get(l-1);
		return ret;
	}
};

ll gauss(ll x){
	return x*(x+1)/2ll;
}

ll pref[maxn],suf[maxn],a[maxn];

int main(){
    fast;
    ll n,q,tot=0;
    cin >> n >> q;

    fore(i,1,n+1) cin >> a[i];

	// obtener las inversiones prefijo
	Fen ft(n);
	fore(i,1,n+1){
		pref[i] = ft.query(a[i]+1,n);
		ft.add(a[i],+1);
		tot += pref[i];
	}
	
	// obtener las inversiones sufijo
	Fen ft2(n);
	rofe(i,n+1,1){
		suf[i] = ft2.query(1,a[i]-1);
		ft2.add(a[i],+1);
	}
    
    ft.clean();
    ft2.clean();
    
    // poner las inversiones prefijo
    fore(i,1,n+1){
    		ft.add(i,pref[i]);
    		// cout << pref[i] << " ";
    }
    // cout << nl;
    
    // poner las inversiones sufijo
    fore(i,1,n+1){
    		ft2.add(i,suf[i]);
    		// cout << suf[i] << " ";
    }
    // cout << nl;
    
    
    // cout << "tot: " << tot << nl;
    while(q--){
    		int t,k;
    		cin >> t >> k;
    		if (t == 2){ // answer
    			if (k == 0){
    				cout << tot << nl;
    			}
    			else{
    				ll all_lefts = ft.query(1,k);
    				ll all_rights = ft2.query(k+1,n);
    				
    				ll norm_lefts = gauss(k-1) - all_lefts;
    				ll norm_rights = gauss(n-k-1) - all_rights;
    				
    				ll norm_all = gauss(n-1) - tot;
    				
    				ll ans = all_lefts + all_rights + (norm_all - norm_lefts - norm_rights);
    				cout << ans << nl;
    			}
    		}
    		else{ // swap shit
    			if (a[k] < a[k+1]){ // create an inversion
    				tot++;
    				
    				// change prefixes tree
    				{
    					ll cur = ft.query(k,k);
    					ll sig = ft.query(k+1,k+1);
    					
    					ll new_cur = sig;
    					ll new_sig = cur + 1;
    					
    					ll difcur = new_cur - cur;
    					ll difsig = new_sig - sig;
    					
    					ft.add(k,difcur);
    					ft.add(k+1,difsig);
    				}
    				// change suffixes tree
    				{
    					ll cur = ft2.query(k,k);
    					ll sig = ft2.query(k+1,k+1);
    					
    					ll new_cur = sig + 1;
    					ll new_sig = cur;
    					
    					ll difcur = new_cur - cur;
    					ll difsig = new_sig - sig;
    					
    					ft2.add(k,difcur);
    					ft2.add(k+1,difsig);
    				}
    			}
    			else{ // delete an inversion
    				tot--;
    				
    				// change prefixes tree
    				{
    					ll cur = ft.query(k,k);
    					ll sig = ft.query(k+1,k+1);
    					
    					ll new_cur = sig - 1;
    					ll new_sig = cur;
    					
    					ll difcur = new_cur - cur;
    					ll difsig = new_sig - sig;
    					
    					ft.add(k,difcur);
    					ft.add(k+1,difsig);
    				}
    				// change suffixes tree
    				{
    					ll cur = ft2.query(k,k);
    					ll sig = ft2.query(k+1,k+1);
    					
    					ll new_cur = sig;
    					ll new_sig = cur - 1;
    					
    					ll difcur = new_cur - cur;
    					ll difsig = new_sig - sig;
    					
    					ft2.add(k,difcur);
    					ft2.add(k+1,difsig);
    				}
    			}
    			swap(a[k],a[k+1]);
    		}
    }
    
    return 0;
}