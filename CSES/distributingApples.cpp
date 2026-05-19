#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;
 
const ll mod = 1e9+7;
const ll loga = 31;
const ll maxn = 2e6+5;
ll f[maxn];
 
void precalc(){
    f[0]=1;
    fore(i,1,maxn) f[i] = (f[i-1]*i)%mod;
}
 
ll exponentiate(ll x, ll y){ //x^y
    ll expo = x;
    ll pot = 1;
    ll res = 1;
    fore(i,1,loga){
        if ((pot&y) == pot){
            res = (res*expo)%mod;
        }
        expo = (expo*expo)%mod;
        pot *= 2ll;
    }
    return res;
}
 
ll starsnbars(ll stars, ll bars){ //apples and people.
    ll res = f[stars+bars-1];
    ll denom = (f[stars]*f[bars-1])%mod;
    res = (res*exponentiate(denom,mod-2))%mod;
    return res;
}
 
int main(){
    fast;   
    precalc();
    ll x,y;
    cin>>x>>y; 
    cout<<starsnbars(y,x)<<nl;
    return 0;
}