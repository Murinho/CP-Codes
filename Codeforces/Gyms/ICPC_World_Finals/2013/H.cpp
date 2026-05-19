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
 
using namespace std;

const ll maxn = 505;
const ll inf = 1e9+7;

ll n;
bool good[maxn][maxn]; // valid range to compute assembly from 1 to (r-l+1)

ll dp[maxn][maxn]; // minimum number of moves to assemble some number of groups of matryoshkas in [l][r]
ll single[maxn][maxn];
bool vis[maxn][maxn]; // single states visited.
ll a[maxn];

vector <pii> mm[maxn][maxn]; // where the min and max are.

void init(){
	fore(i,0,n+1) fore(j,0,n+1){
		dp[i][j] = inf;
		single[i][j] = inf;
		vis[i][j] = false;
	}
}

ll gimme_cost(int &l, int &k, int &r){
	ll ini = 0;
	ll fin = r-l;
	while(ini < fin){
		ll mid = (ini+fin+1)/2;
		if (mm[l][r][mid].snd <= k || k < mm[l][r][mid].fst) ini = mid;
		else fin = mid-1;
	}
	return (r-l+1) - (ini+1);
}

void dfs(int i, int j){
	if (vis[i][j]) return;
	vis[i][j] = true;
	if (i+1 >= j){
		if (i == j) single[i][j] = 0;
		else single[i][j] = 1;
		return;
	}
	
	for(int k = i; k<j; k++){
		ll cost = gimme_cost(i,k,j);
		//cout << "Cost: " << i << " " << k << " " << j << ": " << cost << nl;
		dfs(i,k);
		dfs(k+1,j);
		single[i][j] = min(single[i][j], single[i][k] + single[k+1][j] + cost);
	}
}

int main(){
    fast;
    cin >> n;
    init();
    fore(i,1,n+1) cin >> a[i];
    
    // compute the mexes:
    fore(i,1,n+1){
    	set <ll> st;
    	ll mex = 1;
    	for(int j = i; j<=n; j++){
    		if (st.count(a[j])) break;
    		st.insert(a[j]);
    		
    		while(st.count(mex)) mex++;
    		
    		if (mex == j-i+2) good[i][j] = true;
    	}
    }
    
    // compute the min max thing:
    fore(i,1,n+1){
    	vector < pii > v;
    	for(int j = i; j<=n; j++){
    		v.pb({a[j],j});
    		sort(ALL(v));
    			
			ll mn = inf;
			ll mx = -inf;
			for(auto &[x,pos] : v){
				mn = min(mn,pos);
				mx = max(mx,pos);
				mm[i][j].pb({mn,mx});
				//cout << mn << " " << mx << nl;
			}
    	}
    }
    
    for(int i = n; i>=1; i--){
    	for(int j = i; j<=n; j++){ // j belongs to the left part.
    		if (!good[i][j]) continue;
    		
    		dfs(i,j);
    		dp[i][j] = single[i][j];
    		dp[i][n] = min(dp[i][n], dp[i][j] + dp[j+1][n]);
    	}
    }
    
    /*
    fore(i,1,n+1){
    	fore(j,i,n+1) cout << (dp[i][j] >= inf ? -1 : dp[i][j]) << " ";
    	cout << nl;
    } */
    
    if (dp[1][n] >= inf) cout << "impossible" << nl;
    else cout << dp[1][n] << nl;
    return 0;
} 