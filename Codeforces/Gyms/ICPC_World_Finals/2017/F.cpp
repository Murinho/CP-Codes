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

const ll maxn = 260;
const ll inf = 1e15;
ll dp[maxn][maxn],a[maxn],lef[maxn][maxn],rig[maxn][maxn];
ll n,k;

void init(){
	fore(i,0,maxn){
		fore(j,0,maxn) dp[i][j] = inf;
	}
	dp[0][0] = 0;
}

void solve(){
	cin>>n>>k;
	fore(i,0,n){
		ll x,y;
		cin>>x>>y;
		a[x] += y;
	}
	init();
	// compute the left part from each intensity:
	fore(i,0,maxn){
		lef[i][i] = 0;
		rofe(j,i,0){
			lef[i][j] = lef[i][j+1] + (a[j]*(i-j)*(i-j));
		}
	}
	
	// compute the right part from each intensity:
	fore(i,0,maxn){
		rig[i][i] = 0;
		fore(j,i+1,maxn){
			rig[i][j] = rig[i][j-1] + (a[j]*(j-i)*(j-i));
		}
	}
	
	// compute the whole dp:
	
	// initialize dp[i][1]:
	fore(i,0,maxn){
		dp[i][1] = lef[i][0];
	}
	
	// continue with the rest:
	fore(i,1,maxn){ // current intensity:
		fore(j,2,k+1){
			rofe(x,i,0){
				ll mid = (x+i)/2;
				dp[i][j] = min(dp[i][j], dp[x][j-1] + rig[x][mid] + lef[i][mid+1]);
			}
		}
	}
	
	ll ans = inf;
	fore(i,1,maxn) ans = min(ans,dp[i][k] + rig[i][maxn-1]);
	
	cout<<ans<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}