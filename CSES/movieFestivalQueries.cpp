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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e6+5;
const ll tope = 1e6+4;
const ll loga = 20;
const ll INF = 1e9+7;


ll a[maxn],b[maxn],up[maxn][loga],c[maxn];
ll n,q;

void init(){
	fore(i,0,maxn) c[i] = tope;
}

void binlift(){
	fore(i,1,loga){
		fore(j,1,maxn) up[j][i] = up[up[j][i-1]][i-1];
	}
	return;
}

int main(){
    fast;
    cin >> n >> q;
    init();
    fore(i,1,n+1){
    	cin >> a[i] >> b[i];
    	c[a[i]] = min(c[a[i]],b[i]);
    }
    
    // compute the best next for each position.
    rofe(i,maxn,1){
    	if (i+1 < maxn) c[i] = min(c[i],c[i+1]);
    	up[i][0] = c[i];
    	//if (up[i][0] >= maxn || up[i][0] <= 0) cout << "WARNING!! " << i << nl;
    } 
    
    // do binlift.
    binlift();
    
    while(q--){
    	ll pos,r;
    	cin >> pos >> r;
    	ll ans = 0;
    	rofe(i,loga,0){
    		if (up[pos][i] <= r){
    			ans += (1ll<<i);
    			//cout << pos << " -> " << up[pos][i] << nl;
    			pos = up[pos][i];
    		}
    	}
    	cout << ans << nl;
    }
    return 0;
}