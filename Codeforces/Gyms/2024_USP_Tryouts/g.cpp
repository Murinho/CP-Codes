#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(), u.end()
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second;

using namespace std;

const ll INF = 1e18;
const ll maxn = 1005;
ll dp[maxn][maxn],n,a[maxn];

void init(){
    fore(i,0,maxn) fore(j,0,maxn) dp[i][j]=INF;
    dp[0][0] = 0;
    a[0]=0;
}

int main(){
    fast;
    cin>>n;
    init();
    fore(i,1,n+1) cin>>a[i];

    fore(i,0,n){
        fore(j,0,i+1){
            if (dp[i][j] == INF) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + abs(a[i]-a[i+1])); //no teleport.
            dp[i+1][i] = min(dp[i+1][i],dp[i][j] + abs(a[j]-a[i+1])); //new teleport.
        }
    }
    ll ans =INF;
    fore(i,0,n) ans = min(ans,dp[n][i]);
    cout<<ans<<nl;
    return 0;
}   