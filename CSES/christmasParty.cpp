#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(i) __builtin_ffs(i)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 1e6 + 5;
const ll mod = 1e9+7;
const ll loga = 31;
ll n,f[maxn];
 
void precalc(){
    f[0] = 1;
    fore(i,1,maxn) f[i] = (f[i-1]*i)%mod;
}
 
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
    precalc();
    ll ans = f[n];
    ll bad=0;
    fore(i,1,n+1){
        ll aux = (nCk(n,i)*f[n-i])%mod;
        if (i%2) bad = (bad + aux + mod)%mod;
        else bad = (bad - aux)%mod;
    }
    ans = (ans - bad + mod)%mod;
    cout<<ans<<nl;
    return 0;
}