#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>

using namespace std;

const ll mod = 998244353;
const ll maxn = 1e6+10;

ll f[maxn];

void init(){
    f[0] = 1;
    fore(i,1,maxn){
        f[i] = (f[i-1]*i)%mod;
    }
}

ll expo(ll x, ll pw){
    ll res = 1;
    while(pw > 0){
        if (pw&1){
            res = (res*x)%mod;
        }
        x = (x*x)%mod;
        pw >>= 1;
    }
    return res;
}

ll nck(ll a, ll b){
    b = (f[b]*f[a-b])%mod;
    ll inverse = expo(b,mod-2);
    ll res= (f[a]*inverse)%mod;
    return res;
}

int main(){
    fast;
    ll q;
    init();
    cin >> q;
    while(q--){
        ll n,k;
        cin >> n >> k;
        ll ans = nck(n+1,k+1);

        cout << ans << nl;
    }
    return 0;
}