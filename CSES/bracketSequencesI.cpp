#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
 
using namespace std;

ll n;
const ll maxn = 1e6 + 5;
const ll mod = 1e9+7;
const ll loga = 31;
ll f[maxn];

 
ll exponentiate(ll b, ll pw){
    ll expo = b;
    ll pot = 1;
    ll res = 1;
    for (int i = 1; i<=loga; i++){
        if ((pot | pw) == pw){
            res = (res*expo)%mod;
        }
        expo = (expo*expo)%mod;
        pot *= 2;
    }
    return res;
}

ll nCk(ll a, ll b){
    b = (f[b]*f[a-b])%mod;
    ll inverse = exponentiate(b,mod-2);
    ll res = (f[a]*inverse)%mod;
    return res;
}


int main(){
    fast;
    cin>>n;
    f[0] = 1;
    fore(i,1,maxn) f[i] = (f[i-1]*i)%mod;
    if (n%2){
        cout<<0<<nl;
        return 0;
    }
    n /= 2;
    ll t1 = nCk(2*n,n);
    ll t2 = exponentiate(n+1,mod-2);
    ll ans = (t1*t2)%mod;
    cout<<ans<<nl;
    return 0;
}