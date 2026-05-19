#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define ld long double
#define eb emplace_back
#define vi vector<ll>
#define sz(a) ((ll)a.size())
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)

using namespace std;

const ll maxn = 1e5+100;
const ll maxm = 65;
const ll mod = 1e9+7;
const ll asz = 26;

ll dp[maxn][maxm][2];
ll n,m;
char a[maxn],b[maxn];

int main(){
    fast;
    cin >> n >> m;
    fore(i,1,n+1) cin >> a[i];
    fore(i,1,m+1) cin >> b[i];

    if (n < m){
        cout << 0 << nl;
        return 0;
    }
    else if (n == m){
        ll ans = 1;
        fore(i,1,n+1) if (a[i] != b[i]) ans = 0;
        cout << ans << nl;
        return 0;
    }

    dp[0][0][0] = 1;

    fore(i,0,n){
        fore(j,0,m+1){
            fore(k,0,2){
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k])%mod;
            }
            
            if (j+1 <= m && a[i+1] != b[j+1]){
                dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][0])%mod;
            }
            else if (j+1 <= m){
                fore(k,0,2){
                    dp[i+1][j+1][k] = (dp[i+1][j+1][k] + dp[i][j][k])%mod;
                }
            }
            dp[i+1][j][1] = (dp[i+1][j][1] + ((dp[i][j][0] * (asz-1))))%mod;
        }
    }

    //cout << dp[n][m][0] << " " << dp[n][m][1] << nl;

    ll ans = dp[n][m][0];
    ans %= mod;

    ans += dp[n][m][1];
    ans %= mod;

    cout << ans << nl;
    return 0;
}