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

using namespace std;


ll tc;
ll n;
void solve(){
    cin >> n;
    cout << (1ll << n) - 1 << nl;
    return;
}

int main(){
    fast;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}