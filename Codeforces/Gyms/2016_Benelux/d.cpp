#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define eb emplace_back
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 4050;
const ll maxt = 1801;
const ll inf = 1e18;

ll n,t[maxn],dp[maxn];


int main(){
    fast;
    cin >> n;

    fore(i,1,n+1){
    	cin >> t[i];
    	dp[i] = inf;
    }

    dp[0] = 0;
    fore(i,1,n+1){
    	fore(j,1,i+1){
    		dp[i] = min(dp[i], dp[i-j] + max(t[i] - t[i-j+1] - 1800 + 20, 20*j) + 120);
    	}
    }
    cout << dp[n] << nl;
    return 0;
} 