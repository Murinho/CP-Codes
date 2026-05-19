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

// O(m*n) donde cada uno es el tamano de cada string
int editDist(string &s1, string &s2){
  int m = sz(s1), n = sz(s2);
  int dp[m+1][n+1];
  fore(i,0,m+1)
    fore(j,0,n+1){
    if (i==0) dp[i][j] = j;
    else if (j==0) dp[i][j] = i;
    else if (s1[i-1] == s2[j-1]) dp[i][j]=dp[i-1][j-1];
    else dp[i][j] = 1 + min({dp[i][j-1],  // Insert
                            dp[i-1][j],  // Remove
                            dp[i-1][j-1]}); // Replace
    }
  return dp[m][n];
}
int main(){
    fast;
    string s,t;
    cin >> s;
    cin >> t;
    cout << editDist(s,t) << nl;
    return 0;
}