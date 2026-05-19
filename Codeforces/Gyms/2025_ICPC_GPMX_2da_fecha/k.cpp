#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>

using namespace std;

vi a,b;
ll n,k;

void init(){
    a.resize(n);
    b.resize(n);
}

int main(){
    fast;
    cin >> n >> k;
    init();
    fore(i,0,n) cin >> a[i];
    fore(i,0,n) cin >> b[i];

    sort(ALL(a));
    sort(ALL(b));

    int ans = 0;
    ll cur = 0;
    fore(i,0,n){
        if (a[i] + b[i] + cur <= k){
            cur += a[i];
            cur += b[i];
            ans++;
        }
        else break;
    }
    cout << ans << nl;
    return 0;
}