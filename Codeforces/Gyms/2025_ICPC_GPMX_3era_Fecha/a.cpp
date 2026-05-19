#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;


int main(){
    fast;
    ll n;
    cin >> n;
    ll a = 0;
    ll b = 0;
    fore(i,0,n){
        ll x;
        cin >> x;
        a += x;
    }

    ll ans = 0;
    while(n > 0){
        if (a%n == 0) break;
        ans++;
        n--;

    }
    cout << ans << nl;
    return 0;
}