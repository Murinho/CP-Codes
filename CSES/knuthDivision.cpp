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

using namespace std;

const ll maxn = 5005;
const ll inf = 1e18;
ll n,dp[maxn][maxn],opt[maxn][maxn],sum[maxn],a[maxn];

ll C(int l, int r){
	return sum[r] - (l-1 >= 0 ? sum[l-1] : 0);
}

int main(){
    fast;
   	cin >> n;
   	fore(i,0,n){
   		cin >> a[i];
   		sum[i] = a[i];
   	}
   	
   	fore(i,0,n) sum[i] += sum[i-1];
   	
   	// init dp
   	fore(i,0,n){
   		opt[i][i] = i;
   		dp[i][i] = 0;
   	}
   	
   	
   	for(ll i = n-2; i>=0; i--){
   		for (ll j = i+1; j < n; j++) {
			ll mn = inf;
			ll cost = C(i, j);
			for (ll k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
				if (mn >= dp[i][k] + dp[k+1][j] + cost) {
					opt[i][j] = k; 
					mn = dp[i][k] + dp[k+1][j] + cost; 
				}
			}
			dp[i][j] = mn; 
		}
   	}
   	cout << dp[0][n-1] << nl;
   	return 0;
}