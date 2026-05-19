#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

ll tc,n,k;

void solve(){
    cin>>n>>k;
    if (k == 1){
        cout<<n<<nl;
        return;
    }
    k--;
    if (n>=k) n = k;
    
    ll root = sqrt(k);
    ll ans = 0;
    fore(i,1,root+1){
        if (k%i == 0 && i <= n){
            ans++;
            if (i*i != k && (k/i) <= n) ans++;
        }
    }
    cout<<ans<<nl;
    return;
}


int main(){
    fast;
    cin>>tc;
    while(tc--){
        solve();
    }
}