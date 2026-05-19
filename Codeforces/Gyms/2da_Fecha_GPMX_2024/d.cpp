#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll mod = 1e9+7;
const ll maxn = 801;

unordered_map <ll,ll> dp[maxn];

//dp[i][j]: longitud y suma de digitos.

void precalc(){
    fore(k,1,10) dp[1][k] = dp[1][-k] = (9-k);
    ll tope,aux;
    fore(i,1,maxn-1){ //longitud.
        tope = min(i,maxn-i)*9;
        fore(j,-tope,tope+1){ //diferencia de suma.
            if (!dp[i][j]) continue;
            fore(k,1,10){
                aux = (dp[i][j]*(10-k))%mod;
                dp[i+1][j-k] = (dp[i+1][j-k] + aux)%mod;
                dp[i+1][j+k] = (dp[i+1][j+k] + aux)%mod;
            } 
        }
    }
}

int main(){
    fast;
    precalc();
    ll tc,n;
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<dp[n][0]<<nl;
    }
    return 0;
}