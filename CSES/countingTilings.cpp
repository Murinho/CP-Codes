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

const ll maxn = 2050;
const ll mod = 1e9+7;

ll n,m,dp[maxn][maxn];

void generate_next_masks(int curmk, int i, int nextmk, vi &v){
	if (i == n+1){
		v.pb(nextmk);
		return;
	}
	
	if ((1<<i)&curmk){
		generate_next_masks(curmk,i+1,nextmk,v);
	}
	
	if (i < n){
		if (((curmk&(1ll<<i)) == 0) && ((curmk&(1<<(i+1))) == 0)){
			generate_next_masks(curmk,i+2,nextmk,v);
		}
	}
	
	if (((1<<i)&curmk) == 0){
		generate_next_masks(curmk,i+1,nextmk + (1ll<<i), v);
	}
}

ll dfs(int col, int mk){
	if (col == m+1){
		if (mk == 0) return 1;
		return 0;
	}
	
	if (dp[col][mk] != -1){ return dp[col][mk]; }
	
	vi next_masks;
	generate_next_masks(mk,1,0,next_masks);
	
	dp[col][mk] = 0;
	for(auto nmk : next_masks){
		dp[col][mk] += dfs(col+1,nmk);
		dp[col][mk] %= mod;
	}
	return dp[col][mk];
}

int main(){
    fast;
    cin >> n >> m;
    
    memset(dp,-1,sizeof(dp));
    
    dfs(1,0);
    
    cout << dp[1][0] << nl;
    return 0;
}