#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

vi a;
ll n;

int main(){
    fast;
    cin >> n;
    fore(i,0,n){
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(ALL(a));

    fore(i,2,n){
        if (a[i-2] + a[i-1] > a[i]){
            cout << "possible" << nl;
            return 0;
        }
    }
    cout << "impossible" << nl;
    return 0;
}