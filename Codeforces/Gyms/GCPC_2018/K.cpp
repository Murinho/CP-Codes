#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())
#define ld long double

using namespace std;

const ll maxg = 1005;
const ll maxn = 65;

int dp[maxg][maxn];
ll a[maxn];
ll n,g;
ld ans = 0.0;
bool ok = false;

int main(){
    fast;
    cin >> n >> g;

    fore(i,1,n+1) cin >> a[i], a[i] -= 10;

    // Calcular la dp.
    dp[0][0] = 1;
    fore(i,1,n+1){
        for(int j = g-a[i]; j>=0; j--){ // cuanta longitud llevo.
            for(int k = i-1; k>=0; k--){ // cuantos cables llevo.
                if (dp[j][k] == 0) continue;

                dp[j + a[i]][k+1] = 1;
            }
        }
    }

    for(int i = 1; i<=g; i++){ // longitud.
        for(int j = 1; j<=n; j++){ // cuantos cables.
            if (dp[i][j] == 0) continue;

            ll falta = g-i;
            ld overlap = 10.0 - ((ld)falta)/(ld)(j+1);
            if (overlap >= 0.0 && overlap <= 5.0){
                ok = true;
                // cout << "overlap: " << fixed << setprecision(13) << overlap << nl;
                ans = max(ans,overlap);
            }
        }
    }
    if (!ok) cout << "impossible" << nl;
    else cout << fixed << setprecision(10) << ans << nl;
    return 0;
} 