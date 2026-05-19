// Problem: A. Acing the contest
// Contest: Codeforces - 2020 ICPC Gran Premio de Mexico 3ra Fecha
// URL: https://codeforces.com/gym/102890/problem/A
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

const ll maxb = 1050;
int dp[maxb][105][105]; //dp[mask][current problem][energy].
int e[15],d[105],s[105];
int n,m,ans=0;

vector<int> bt[15];

void bits_buckets(){
	fore(i,0,(1<<n)){
		int cnt = __builtin_popcount(i);
		bt[cnt].pb(i);
	}
}

void init(){
	fore(i,0,(1<<n)){
		fore(j,0,m){
			fore(k,0,101) dp[i][j][k] = -1;
		}
	}
	dp[0][0][0] = 0;
}

void solve(){
	cin>>n>>m;
	
	fore(i,0,n) cin>>e[i];
	fore(i,0,m) cin>>d[i];
	fore(i,0,m) cin>>s[i];
	
	init();
	bits_buckets();
	
	// go from number with small amount of bits to bigger amount of bits.
	fore(i,0,n+1){ //amount of bits.
		for(auto &mask : bt[i]){
			fore(j,0,m){ // current problem.
				for(int k = 100; k>=0; k--){
					int &cur = dp[mask][j][k];
					if (cur == -1) continue;

					// solve problem:
					if (k >= d[j]){
						dp[mask][j+1][k - d[j]] = max(dp[mask][j+1][k - d[j]], cur + s[j]);
						ans = max(ans,dp[mask][j+1][k - d[j]]);
					}
					
					// skip problem:
					dp[mask][j+1][k] = max(dp[mask][j+1][k], cur);
					ans = max(ans,dp[mask][j+1][k]);
					
					// pass to next member:
					int imask = (1<<n) - mask - 1;
					while(imask > 0){
						int bms = lsb(imask);
						int who = lsbpos(imask) - 1;
						dp[mask + bms][j][e[who]] = max(dp[mask + bms][j][e[who]], cur);
						ans = max(ans, dp[mask + bms][j][e[who]]);
						imask -= bms;
					}
				}
			}
		}
	}
	cout<<ans<<nl;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}