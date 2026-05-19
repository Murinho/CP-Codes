#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

ll g(ll x){
    return x*(x+1)/2ll;
}

int main(){
    fast;
    ll n;
    cin >> n;
    ll ans = 0;
    fore(i,1,n+1){
        ll x;
        cin >> x;

        ll y = g(n) - g(i-1) - g(n-i);
        ans += x*y;        
    }
    cout << ans << nl;
    return 0;
}