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
 
using namespace __gnu_pbds;
using namespace std;

const int maxn = 3005;
const ll offs = 9'000'001;

static ll n,a[maxn][maxn],k;
static ll dp[maxn][maxn],ans[26];


int main(){
	fast;
   	cin >> n >> k;
   	char c;
   	fore(i,1,n+1){
   		fore(j,1,n+1){
   			cin >> c;
   			a[i][j] = (c-'A');
   		}
   	} 
   	
   	// init dp:
   	fore(i,1,n+1){
   		dp[i][1] = dp[1][i] = 1;
   	}
   	
   	// compute the dp:
   	fore(i,2,n+1){
   		fore(j,2,n+1){
   			if (a[i][j] == a[i-1][j-1] && a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1]){
   				dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1;
   			}
   			else dp[i][j] = 1;
   		}
   	}
   	
   	// compute the answer:
   	fore(i,1,n+1){
   		fore(j,1,n+1){
   			ans[a[i][j]] += dp[i][j];
   		}
   	}
   	
   	fore(i,0,k) cout << ans[i] << nl;
   	
   	return 0;
}