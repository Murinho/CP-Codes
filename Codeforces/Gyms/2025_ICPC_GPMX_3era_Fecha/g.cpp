#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define ld long double

using namespace std;

ll h1,h2,b;

ld expo(ld x, ll pw){
    ld res = 1.0;
    while(pw){
        if (pw&1) res = (res*x);

        x = (x*x);
        pw >>= 1;
    }
    return res;
}

void solve(){
    cin >> h1 >> h2 >> b;

    ld x = (ld)(b-1)/(ld)b;

    ll l = 1;
    ll r = 6e6 + 1;
    while(l < r){
        ll mid = (l+r)/2;

        ld res = expo(x,mid) * (ld)h1;

        if (res <= (ld)h2) r = mid;
        else l = mid+1;
    }

    cout << l << nl;
    return;
}

int main(){
    fast;
    ll tc;
    cin>> tc;
    while(tc--){
        solve();
    }
}