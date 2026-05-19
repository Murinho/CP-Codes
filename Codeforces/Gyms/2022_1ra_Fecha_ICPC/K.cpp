// Problem: K. Kilo Waste
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103708/problem/K
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

const ll maxn = 5e4 + 105;

ll q,n,a[maxn];
bool dp[maxn];


void solve(){
	cin >> q >> n;
	fore(i,0,n) cin >> a[i];
	
	dp[0] = true;
	fore(i,0,n){
		for(int j = maxn - a[i] - 1; j>=0; j--){
			if (!dp[j]) continue;
			for(int x = a[i]; j+x < maxn; x += a[i]){
				dp[j+x] = true;
			}
		}
	}
	
	while(q--){
		ll x;
		cin >> x;
		int ans = 0;
		while(!dp[x]) ans++, x++;
		
		cout << ans <<nl;
	}
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}