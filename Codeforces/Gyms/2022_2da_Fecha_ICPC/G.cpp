// Problem: G. Guadalajara trains
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/G
// Memory Limit: 256 MB
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

const ll maxn = 1e6 + 10;
ll a[maxn],b[maxn],t[maxn];
ll n;


void solve(){
	cin >> n;
	fore(i,1,n){
		cin >> a[i];
	}
	fore(i,1,n+1) cin >> t[i];
	
	ll l = 1;
	ll r = n;
	ll tl = 0;
	ll tr = 0;
	ll ans = 0;
	while(l <= r){
		if (l == r){
			ans = t[l] - (max(tl,tr) - min(tl,tr));
			break;
		}
		else if (l < n && tl + t[l] + a[l] < tr + t[r] + a[r-1]){
			tl += t[l] + a[l];
			l++;
		}
		else if (r > 1){
			tr += t[r] + a[r-1];
			r--;
		}
		else break;
	}
	ans = max(0ll,ans);
	cout << ans << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}