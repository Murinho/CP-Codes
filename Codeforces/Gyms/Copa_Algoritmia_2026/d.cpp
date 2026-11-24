#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define ld long double

using namespace std;


void doit(){
    ll b,d;
    cin >> b >> d;
    ll g = __gcd(b,d);
    ll mul = d/g;
    ll ans = b/mul;
    if (b%mul == 0) ans--;

    cout << ans << nl;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        doit();
    }

    return 0;
}