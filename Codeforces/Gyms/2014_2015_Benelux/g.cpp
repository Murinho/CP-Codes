#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ld long double

using namespace std;

const ll inf = 1e18+100;
const ll maxr = 1e7+50;
const ld eps = 1e-6;
ll a,b,c;

ld f(ld r){
    ld ret = (-a*(r*r)) + (b*r) + c;
    return ret;
}

ll ts(){
    ld l = 0;
    ld r = maxr;
    while(r - l > eps){
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = f(m1);
        ld f2 = f(m2);

        if (f1 < f2) l = m1;
        else r = m2;
    }

    return f(l);
}

void solve(){
    ll n;
    cin >> n;
    ld best = 0;
    ll who = -1;
    fore(i,1,n+1){
        cin >> a >> b >> c;
        ld res = ts();
        if (res > best){
            best = res;
            who = i;
        }
        //cout << i << ": " << res << nl;
    }
    //cout << fixed << setprecision(9) << best << nl;
    cout << who << nl;
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