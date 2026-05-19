#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 1e5+100;
const ll tope = 1e6+10;

vector < pii > a;
ll n,b[maxn];
map <ll,ll> mp;

void calc(){
    ll x = 2;
    ll y = 1;
    //int cnt = 0;
    while(min(x,y) < tope){
        //if (cnt < 10) cout << x << " " << y << nl;
       // cnt++;
        if (x < y){
            a.pb({x,y});
            x += y;
        }
        else { // y < x
            a.pb({y,x});
            y += x;
        }
    }
}

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
        cin >> b[i];
        mp[b[i]] = i;
    }

    // Check for the ones.
    int fir = -1, las = -1;

    fore(i,1,n+1){
        if (b[i] == 1){
            if (fir == -1) fir = i;
            las = i;
        }
    }

    if (fir != las){
        cout << fir << " " << las << nl;
        return 0;
    }

    calc();

    for(auto &[x,y] : a){
        if (mp.count(x) && mp.count(y)){
            cout << mp[x] << " " << mp[y] << nl;
            return 0;
        }
    }
    cout << "impossible" << nl;
    return 0;
}