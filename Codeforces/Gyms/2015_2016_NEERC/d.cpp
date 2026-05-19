#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

using namespace std;

const ll inf = 1e18;

ll getp3(ll x){
    ll ret = 1;
    fore(i,0,x){
        ret *= 3;
    }
    return ret;
}

int main(){
    fast;
    //freopen("concatenation.in", "r", stdin);  
    //freopen("concatenation.out", "w", stdout);
    
    ll n = 25;
    ll ans = 0;
    int l = 0;
    int r = n;
    while(r >= 0){
        ll p2 = (1ll<<l);
        ll p3 = getp3(r);
        ans += (p2*p3);
        l++, r--;
    }
    cout << ans << nl;
    return 0;
}