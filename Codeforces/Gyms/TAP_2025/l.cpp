#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ppb pop_back
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define vi vector<ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+10;
const ll maxb = 450;

ll n,k;
ll dp[maxn][maxb],a[maxn],p[maxn],ans=0;

void init(){
    fore(i,0,n+1){
        fore(j,0,maxb) dp[i][j] = -1;
    }
    dp[0][0] = 0;
    p[0] = 0;
}

int main(){
    fast;
    cin >> n >> k;
    init();
    fore(i,1,n+1){
        cin >> a[i];
        p[i] = p[i-1] + a[i];
    }

    // fore(i,1,n+1) cout << p[i] << " ";
    // cout << nl;

    fore(i,0,n){
        fore(j,0,maxb){
            if (dp[i][j] == -1) continue;

            // no pongo nada en lo que sigue.
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            ans = max(ans,dp[i+1][j]);

            // pongo un barco de tamanio j+1
            if (i + j + 1 <= n){
                dp[i+j+1][j+1] = max(dp[i+j+1][j+1], dp[i][j] - (p[i+j+1] - p[i]) + k);
                ans = max(ans,dp[i+j+1][j+1]);
            }
        }
    }

    cout << ans << nl;
    return 0;
}