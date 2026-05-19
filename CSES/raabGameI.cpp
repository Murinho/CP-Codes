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

ll n,x,y;

void solve(){
	cin >> n >> x >> y;
	
	if (x+y > n || max(x,y) == n || (min(x,y) == 0 && max(x,y) > 0)){
		cout << "NO" << nl;
		return;
	}
	
	bool sw = false;
	if (x < y){
		sw = true;
		swap(x,y);
	}
	
	vi a(n),b(n);
	
	// build the answer
	fore(i,0,n) a[i] = n-i;
	
	fore(i,0,n-x-y){
		b[i] = n-i;
	}
	
	int val = x;
	fore(i,n-x-y,n-y){
		b[i] = val--;
	}
	
	val = n-(n-x-y);
	fore(i,n-y,n){
		b[i] = val--;
	}
	
	if (sw) swap(a,b);
	
	cout << "YES" << nl;
	for(auto &elm : a) cout << elm << " ";
	cout << nl;
	for(auto &elm : b) cout << elm << " ";
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