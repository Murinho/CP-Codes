#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

const ll inf = 1e18;

map <string,ll> mp;
map <string,ll> side;
ll ans = inf;

string l = " left";
string r = " right";
string ay = " any";

int main(){
    fast;
    ll n;
    ll sum = 0;
    cin >> n;
    fore(i,0,n){
        string a,b;
        cin >> a >> b;
        ll k;
        cin >> k;
        mp[a] += k;
        string c = a;
        c += " ";
        c += b;
        side[c] += k;
    }

    // intentar cada material
    bool ok = false;
    for(auto [s,val] : mp){
        ll res = sum - val;
        ll mx = -1;

        string si = s + l; 
        string sr = s + r;
        string sa = s + ay;
        if (side[si] > 0 && side[sr] + side[sa] > 0){
            ok = true;
        }
        if (side[sr] > 0 && side[si] + side[sa] > 0){
            ok = true;
        }
        if (side[sa] >= 2){
            ok = true;
        }

        sum += max({side[si],side[sr],1ll});
    }

    if (ok) cout << sum+1 << nl;
    else cout << "impossible" << nl;

    return 0;
}