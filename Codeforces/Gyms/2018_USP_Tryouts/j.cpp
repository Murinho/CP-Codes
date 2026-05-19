// Tested with: https://www.spoj.com/problems/DQUERY/
#include <bits/stdc++.h>
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
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const int maxn = 1e6+5;
string dp[27];

void init(){
    fore(i,0,27) dp[i]="";
    dp[0]='a';
}

char conv(int x){
    return (char)(x+'a');
}

void dfs(int cur){
    if (sz(dp[cur])) return;
    dfs(cur-1);
    dp[cur] += dp[cur-1];
    dp[cur] += conv(cur);
    dp[cur] += dp[cur-1];
    return;
}


int main(){
    fast;     
    init();
    dfs(10);
    ll n;
    cin>>n;
    cout<<dp[10][n-1]<<nl;
    return 0;
}