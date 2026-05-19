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

const ll maxans = 1e12+1;

ll n;

ll check(ll k){
    ll ret=0;
    fore(i,1,n+1){
        ret += min(k/i,n);
    }
    return ret;
}

int main(){
    fast;
    cin>>n;
    if (n == 1){
        cout<<1<<nl;
        return 0;
    }
    ll l = 1;
    ll r = maxans;
    while(l < r){
        ll mid = (l+r)/2;
        ll ret = check(mid);
        if (ret <= (n*n)/2ll) l = mid+1;
        else r = mid;
    }
    cout<<l<<nl;
    return 0;
}