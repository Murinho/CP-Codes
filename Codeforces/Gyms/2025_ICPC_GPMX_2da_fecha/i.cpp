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

const ll maxn = 1000;
ll q,f[maxn];


int main(){
    fast;
    cin >> q;
    while(q--){
        ll x,k;
        cin >> x >> k;
        f[0] = x;
        f[1] = x;
        ll ans = 1;
        if (f[1] < k){
            fore(i,2,100){
                f[i] = f[i-1] + f[i-2];
                ans++;
                if (f[i] >= k){
                    break;
                }
            }
        }
        cout << ans << nl;
    }
    return 0;
}