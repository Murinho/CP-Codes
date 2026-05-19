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
#define fore(i,a,b) for(int i=a;i<b;++i)
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

static const ll maxn = 105;
static const ll offs = 10001;
static const ll maxt = 20005;
static const ll mod = 1e9+7;

ll dp[2][maxn][maxt];
ll n,ans=0,mp;
int a[maxn];

int main(){
    fast;
   	cin >> n >> mp;

   	fore(i,1,n+1) cin >> a[i];
   	
   	sort(a+1,a+n+1);
   	
   	dp[0][0][offs] = 1;
   	
   	// do the dp:
   	fore(i,1,n+1){
   		int cur = i&1;
   		int prev = cur^1;
   		// clean current state.
   		fore(j,0,i){
   			fore(k,0,maxt){
   				dp[cur][j][k] = 0;
   			}
   		}
   		
   		// compute dp:
   		fore(j,0,i){
   			fore(k,0,maxt){
   				// one single element segment:
   				dp[cur][j][k] += dp[prev][j][k];
   				dp[cur][j][k] %= mod;
   				
   				// insert current element in any of the j opened elements.
   				dp[cur][j][k] += (dp[prev][j][k]*j);
   				dp[cur][j][k] %= mod;
   				
   				// add new segment
   				if (k - a[i] >= 0){
   					dp[cur][j+1][k-a[i]] += dp[prev][j][k];
   					dp[cur][j+1][k-a[i]] %= mod;
   				}
   				
   				// remove segment
   				if (j > 0 && k + a[i] < maxt){
   					dp[cur][j-1][k+a[i]] += dp[prev][j][k]*j;
   					dp[cur][j-1][k+a[i]] %= mod;
   				}
   			}
   		}
   	}
   	
   	int cur = (n&1);
   	fore(i,0,mp+1){
   		ans = (ans + dp[cur][0][i+offs])%mod;
   	}
   	cout << ans << nl;
   	return 0;
}