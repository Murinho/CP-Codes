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

const ll maxn = 5010;
const ll mod = 1e9+7;

ll dp[maxn][maxn];

ll solve(ll i, ll j){
	if (j <= 0 || i < 0) return 0;
	if (i == 0) return 1;
	if (j == 1) return 1;
	if (dp[i][j] != -1) return dp[i][j];
	ll ret = 0;
	ret = (ret + solve(i-j, j))%mod;
	ret = (ret + (2* solve(i, j-1)))%mod;
	ret = (ret - solve(i, j-2) + mod)%mod;
	return dp[i][j] = ret;
}

int main(){
    fast;
    ll s,b;
    cin >> s >> b;
    memset(dp, -1, sizeof(dp));
    cout << solve(b - s, s) << nl;
    return 0;
}