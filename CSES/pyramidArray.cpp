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

const ll maxn = 2e5+10;

ll n,a[maxn],b[maxn];
vi v;

ordered_set oml,omr;

ll gk(ordered_set &ost, ll k){
	if (!sz(ost)) return 0;
	return ost.order_of_key(k);
}


int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
    	cin >> a[i];
    	v.pb(a[i]);
    }
    
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    
    fore(i,1,n+1){
    	a[i] = lower_bound(ALL(v),a[i]) - v.begin();
    	b[a[i]] = i;
    }
    
    // fore(i,1,n+1){
    	// cout << a[i] << " ";
    // }
    // cout << nl;
    
    int l = 1;
    int r = n;
    ll ans = 0;
    fore(i,0,n-1){
    	ll pos = b[i];
    	pos += sz(oml) - gk(oml,b[i]);
    	pos -= gk(omr,b[i]);
    	
    	// cout << i << ": " << pos << nl;
    	
    	// ir a la izquierda
    	if (pos-l <= r-pos){
    		ans += pos-l;
    		l++;
    		oml.insert(b[i]);
    		// cout << i << " went left" << nl;
    	}
    	else{
    		ans += r-pos;
    		r--;
    		omr.insert(b[i]);
    		// cout << i << " went right" << nl;
    	}
    }
    cout << ans << nl;
    return 0;
}