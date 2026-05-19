#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

int main(){
    fast;
    ll a,b,c;
    cin >> a >> b >> c;


    ll x = (a+1)*(b+1);
    ll y = c+1;

    cout << (x/y) - 1 << nl;
    return 0;
}