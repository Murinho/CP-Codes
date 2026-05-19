#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>

using namespace std;

const ll mod = 998244353;
const ll maxn = 3e6+100;

ll a[maxn],b[maxn],dp[maxn],n,las[maxn];

int main(){
    fast;
    cin >> n;
    dp[0] = 1;
    fore(i,1,n+1){
        cin >> a[i];

        if (las[a[i]] > 0){
            dp[i] = (dp[i-1] + dp[las[a[i]]])%mod;
        }
        else{
            dp[i] = dp[i-1];
        }
        las[a[i]] = i;
    }

    cout << dp[n] << nl;
    return 0;
}