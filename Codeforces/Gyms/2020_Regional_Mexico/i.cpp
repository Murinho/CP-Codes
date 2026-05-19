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

const ll mod = 1e9+7;
const ll maxn = 2005;

ll dp[maxn],deg[maxn];
ll n,k,cnt=0;
vi g[maxn];

void dfs(int node){
	if (node > k){
		cnt++;
		dp[node] = 1;
	}
	
	for(auto &signode : g[node]){
		if (dp[signode] == 0) dfs(signode);
		dp[node] += dp[signode];
		dp[node] %= mod;
	}
}


int main(){
    fast;
    cin >> n >> k;
    fore(i,1,k+1){
    	ll x;
    	cin >> x;
    	fore(j,0,x){
    		ll y;
    		cin >> y;
    		g[i].pb(y);
    	}
    }
    
    dfs(1);
    
    cout << dp[1] << " " << cnt << nl;
    
    return 0;
}