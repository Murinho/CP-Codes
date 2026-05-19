#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

const ll mod = 123456789;

int main(){
    fast;

    ll s,l;
    cin>>l>>s;

    vector<ll> dp(l+1,0), pref(l+1,0);

    dp[0] = 1;
    pref[0] = 1;

    for(int i=1; i<=l; i++){
        ll left = max(0LL, i-s);
        dp[i] = (pref[i-1] - (left>0 ? pref[left-1] : 0) + mod) % mod;
        pref[i] = (pref[i-1] + dp[i]) % mod;
    }

    ll ans=0;
    for(int h=1; h<=s; h++){
        ans = (ans + dp[l-h]*h) % mod;
    }

    cout<<ans<<"\n";

    return 0;
}
