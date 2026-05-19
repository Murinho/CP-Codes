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

const ll maxn = 105;

ll n,k,a[maxn];

void solve(){
	cin >> n >> k;
	if (k*k < n){
		cout << "IMPOSSIBLE" << nl;
		return;
	}
	int pos = 1;
	int l = 1;
	int r = n;
	
	// go fully up
	for(ll i = r-k+1; i<=r && pos <= n; i++) a[pos++] = i;
	r -= k;
	
	while(pos <= n){
		k--;
		// go fully down
		for(ll i = l+k-1; i>=l && pos <= n; i--) if (i <= r) a[pos++] = i;
		l += k;
		
		// go fully up
		for(ll i = r-k+1; i<=r && pos <= n; i++) if (l <= i) a[pos++] = i;
		r -= k;
	}
	
	fore(i,1,n+1) cout << a[i] << " ";
	cout << nl;
	return;
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}