// Problem: E. Finding progressions
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/E
// Memory Limit: 1024 MB
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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll k,tsum,ans=0,sl,sr;

bool bs_left(ll &falta, ll l, ll r, ll tope, vi &v){
	if (l > r) return false;
	while(l < r){
		ll mid = (l+r)/2;
		ll msum = v[tope-1] - (mid>0 ? v[mid-1] : 0);
		if (msum < falta) r = mid-1;
		else if (msum > falta) l = mid+1;
		else return true;
	}
	ll msum = v[tope-1] - (l>0 ? v[l-1] : 0);
	return msum == falta;
}

bool bs_right(ll &falta, ll l, ll r, ll tope, vi &v){
	if (l > r) return false;
	while(l < r){
		ll mid = (l+r)/2;
		ll msum = v[mid] - v[tope];
		if (msum < falta) l = mid+1;
		else if (msum > falta) r = mid-1;
		else return true;
	}
	ll msum = v[l] - v[tope];
	return msum == falta;
}

int main(){
    fast;
    cin>>k>>tsum>>sl>>sr;
    ll ss = (sr-sl+1); //espacio de busqueda.
    if (k == tsum){
    	cout<<1<<nl;
    	return 0;
    }
    fore(i,1,ss+1){
    	vi v;
    	ll x = k - i;
    	while(sl <= x) v.pb(x), x -= i;
    	reverse(ALL(v));
    	
    	v.pb(k);
    	
    	ll l = sz(v)-1;
    	ll r = sz(v)-1;
    	
    	x = k+i;
    	while(x <= sr) v.pb(x), x += i;
    	
    	//cout<<i<<": ";
    	//for(auto &au : v) cout<<au<<" ";
    	//cout<<nl;
    	
    	fore(j,1,sz(v)) v[j] += v[j-1]; // suma acumulada
    	
    	while(l >= 0 && r < sz(v)){
    		ll sum = v[r]-(l>0 ? v[l-1] : 0);
    		if (sum > tsum) break;
    		else if (sum == tsum){
    			ans++;
    			break;
    		}
    		else{ // binary search.
    			ll falta = tsum - sum;
    			if (bs_left(falta,0,l-1,l,v)) ans++;
    			if (bs_right(falta,r+1,sz(v)-1,r,v)) ans++;
    		}
    		
    		l--, r++;
    	}
    }
    cout<<ans<<nl;
    return 0;
}