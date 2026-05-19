#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define nl '\n'
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)

using namespace std;

const ll maxn = 1e5+100;
const ll loga = 18;
ll a[maxn],n,sp[maxn][loga];

ll query(ll l, ll tar){
    rofe(i,loga,0){
        if (l + (1ll<<i) - 1 <= n && __gcd(tar,sp[l][i]) == tar){
            l += (1ll<<i);
        }
    }
    return l;
}

void build(){
    fore(i,1,n+1) sp[i][0] = a[i];
    fore(i,1,loga){
        fore(j,1,n+1){
            if (j + (1ll<<i) - 1 <= n){
                sp[j][i] = __gcd(sp[j][i-1], sp[j + (1ll<<(i-1))][i-1]);
            }
        }
    }
}

void solve(){
    cin >> n;
    fore(i,1,n+1) cin >> a[i];

    build();

    ll ans = 1;
    fore(i,1,n+1){
        ll pos = i;
        ll cur = a[i];
        while(pos <= n){
            pos = query(pos,cur);
            //cout << i << " --> " << pos << nl;
            ans = max(ans,(pos-i)*cur);
            if (pos <= n) cur = __gcd(cur,a[pos]);
        }
    }

    cout << ans << nl;
    return;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}