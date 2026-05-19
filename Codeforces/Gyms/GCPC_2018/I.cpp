#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

const ll maxn = 2000;

ll n,a[maxn],b[maxn];

int main(){
    fast;
    cin>>n;
    fore(i,0,n) cin>>a[i];
    fore(i,0,n) cin>>b[i];


    if (a[0] > b[0]){
        cout << 0 << nl;
        return 0;
    }

    ll dif = b[0] - a[0];

    bool ok = true;
    fore(i,0,n){
        a[i] += dif;
        if (a[i] > b[i]){
            cout << dif << nl;
            return 0;
        }
        else if (a[i] < b[i]){
            ok = false;
            break;
        }
    }
    if (ok) cout << dif << nl;
    else cout << dif + 1 << nl;
    return 0;
}