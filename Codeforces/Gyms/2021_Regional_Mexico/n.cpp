#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fst first
#define snd second
#define pii pair <ll,ll>
#define nl '\n'

using namespace std;

ll cur = 0;

ll read(){
    ll x,y;
    char c;
    cin >> c >> x >> c >> y;
    return y;
}


int main(){
    fast;

    ll n,ans= 0;
    cin >> n;
    cur = read();
    fore(i,0,n){
        ll x = read();
        cur += x;
        cur %= 100;
        if (cur > 0) ans++;
    }

    cout << ans << nl;
    return 0;
}