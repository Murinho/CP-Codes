#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) a.size()
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

ll check(ll k){
    if (k <= 1) return 0;
    k /= 2;
    return (k*(k+1))*4;
}

void solve(){
    ll n;
    cin>>n;
    // find the number of completed layers:
    ll l = 1;
    ll r = 1e6+5;
    while(l < r){
        ll mid = (l+r+1)/2;
        if (check(mid) < n) l = mid;
        else r = mid-1;
    }
    // completed layers is l.
    ll comp_lays = (l+1)/2;
    //cout<<comp_lays<<nl;
    ll side_len = comp_lays*2;
    ll dif = n - check(l) - 1;
    ll pos = dif%side_len;
    //cout<<comp_lays<<": "<<side_len<<", "<<pos<<nl;

    ll x = ((comp_lays-1)*2) + 2;
    //cout<<x<<nl;

    ll mid = (side_len/2) - 1;
    ll dify = abs(pos-mid);
    ll y = 0;
    if (dify>=1) y = ((dify-1)*2) + 2;
    ll ans = (x*x) + (y*y);
    cout<<ans<<nl;
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){ solve();}
}