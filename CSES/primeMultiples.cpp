#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const ll INF = 2e18+5;
ll n,k,a[25],ans=0;

ll getNum(ll x){
    ll num=1;
    fore(i,0,k){
        if (((1ll<<i)&x) == (1ll<<i)){
            if (num <= INF/a[i]) num *= a[i];
            else{
                num = INF;
                break;
            }
        }
    }
    return num;
}

ll getBits(ll x){
    ll res=0;
    fore(i,0,k){
        if (((1ll<<i)&x) == (1ll<<i)) res++;
    }
    return res;
}

int main(){
    cin>>n>>k;
    fore(i,0,k) cin>>a[i];

    fore(i,1,(1ll<<k)){
        ll cnt= getBits(i);
        ll num = getNum(i);
        if (cnt%2) ans += (n/num);
        else ans -= (n/num);
    }
    cout<<ans<<nl;
    return 0;
}