#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fst first
#define snd second
#define nl '\n'

using namespace std;

const ll maxn = 280;
const ll inf = 1e18;
const ll loga = 16;

ll n,m;
ll a[maxn][maxn],d[maxn];
ll dp[(1ll<<loga)][maxn];
ll ans;

void init(){
    ans = inf;
}

// very few amount of vendors.
void solve_by_vendor(){ // choose a subset of vendors with masking.
    fore(mk,1,(1ll<<m)){
        ll cost = 0;
        vi bc(n,inf);
        fore(j,0,m){
            if ((1ll<<j)&mk){
                cost += d[j];
                // iterate through the cost of each chemical
                fore(c,0,n){
                    bc[c] = min(bc[c],a[c][j]);
                }
            }
        }

        for(auto &elm : bc){
            cost += elm;
            if (cost > ans) break;
        }

        ans = min(ans,cost);
    }
}

// very few amount of chemicals.
void solve_by_chemicals(){ // given the first i vendors mask the already bought chemicals.
    fore(i,0,m){
        fore(mk,0,(1ll<<n)){
            fore(j,0,n){
                if ((1ll<<j)&mk){ // bit prendido.
                    // go from dp[i][mk] -> dp[i][mk + bit]
                    if (i > 0 || mk - (1ll<<j) > 0){
                        dp[mk][i] = min(dp[mk][i], dp[mk - (1ll<<j)][i] + a[j][i]);
                    }
                    // go from dp[i-1][mk] -> dp[i][mk + bit]
                    if (i > 0){
                        dp[mk][i] = min(dp[mk][i], dp[mk - (1ll<<j)][i-1] + d[i] + a[j][i]);
                    }
                }
            }
        }
        if (i > 0){
            fore(mk,0,(1ll<<n)){
                dp[mk][i] = min(dp[mk][i],dp[mk][i-1]);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    init();
    fore(i,0,n){
        fore(j,0,m) cin >> a[i][j];
    }

    fore(i,0,m){
        cin >> d[i];
    }

    if (m <= n){
        solve_by_vendor();
    }
    else{ // n < m
        // init dp.
        fore(i,0,(1ll<<n)){
            fore(j,0,m) dp[i][j] = inf;
        }
        dp[0][0] = 0;
        fore(i,0,n){
            dp[(1ll<<i)][0] = d[0] + a[i][0];
        }

        solve_by_chemicals();

        ans = dp[(1ll<<n) - 1][m-1];
    }

    cout << ans << nl;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}