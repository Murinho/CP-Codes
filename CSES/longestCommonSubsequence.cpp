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

const int maxn = 1005;
int dp[maxn][maxn];
int lcs(vi &s, vi &t){
	int n = sz(s), m = sz(t);
	fore(j,0,m+1) dp[0][j] = 0;
	fore(i,0,n+1) dp[i][0] = 0;
	fore(i,1,n+1){
		fore(j,1,m+1){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (s[i-1] == t[j-1]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
			}
		}
	}
	return dp[n][m];
}

int main(){
    fast;
    ll n,m;
    cin >> n >> m;
	vi a(n), b(m);
	for(auto &elm : a) cin >> elm;
	for(auto &elm : b) cin >> elm;
	
	cout << lcs(a,b) << nl;
}