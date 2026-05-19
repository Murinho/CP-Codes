// Problem: C. Common Subsequence
// Contest: Codeforces - 2019 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/102307/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1010;
int dp[maxn][maxn];

int main(){
    fast;
	string s,t;
	cin>>s>>t;
	int n = sz(s);
	int m = min(1000,n);
	int ans = 0;
	fore(i,0,m+1){
		fore(j,0,m+1){
			while(i + dp[i][j] < n && j + dp[i][j] < n && s[i+dp[i][j]] == t[j+dp[i][j]]) dp[i][j]++;
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
			ans = max(ans,dp[i][j]);
		}
	}
	if (100*ans >= 99*n) cout<<"Long lost brothers D:"<<nl;
	else cout<<"Not brothers :("<<nl;
	return 0;
}