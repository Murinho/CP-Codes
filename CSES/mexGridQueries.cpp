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

const ll maxn = 8;
const ll start = 1073741824;
const ll start2 = 4;

set <ll> stf[maxn],stc[maxn];
ll a[maxn][maxn];

// void build(){
	// fore(i,1,maxn){
		// fore(j,1,maxn){
			// fore(k,0,maxn){
				// if (!stf[i].count(k) && !stc[j].count(k)){
					// a[i][j] = k;
					// stf[i].insert(k);
					// stc[j].insert(k);
					// break;
				// }
			// }
		// }
	// }
// }

// void print(){
	// fore(i,1,maxn){
		// fore(j,1,maxn){
			// cout << a[i][j] << " ";
		// }
		// cout << nl;
	// }
// }
// 
// ll area(ll x, ll x2, ll y, ll y2){
	// return (x2-x+1)*(y2-y+1);
// }

int main(){
    fast;
    ll n,m;
    cin >> n >> m;
    n--, m--;
 
    ll ans = 0;
    ll cur = start;
    ll x = 0;
    ll x2 = start-1;
    ll y = 0;
    ll y2 = start-1;
    while(cur > 0){
    	ll mx = (x+x2)/2;
    	ll my = (y+y2)/2;
    	
    	// cout << x << " " << y << " " << x2 << " " << y2 << nl;
    	
    	// checar si estoy en cuadrante 3
    	if (mx < n && my < m){
    		x = mx+1;
    		y = my+1;
    	}
    	// checar si estoy en cuadrante 2
    	else if (mx < n && m <= my){
    		x = mx+1;
    		y2 = my;
    		ans += cur/2;
    	}
    	// checar si estoy en cuadrante 4
    	else if (n <= mx && my < m){
    		x2 = mx;
    		y = my+1;
    		ans += cur/2;
    	}
    	// checar si estoy en cuadrante 1
    	else{
    		x2 = mx;
    		y2 = my;
    	}
    	cur /= 2ll;
    }
    
    cout << ans << nl;
    return 0;
}