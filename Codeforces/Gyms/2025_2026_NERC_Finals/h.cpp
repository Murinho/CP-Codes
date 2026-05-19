#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define fst first
#define snd second
#define pii pair<ll,ll>
#define i128 __int128_t

using namespace std;

int main(){
    fast;
    ll w,h,d,n;
    cin >> w >> d >> h;
    cin >> n;

    ll aux = w*d;
    aux %= n;
    aux *= h;
    aux %= n;
    if (aux > 0){
        cout << -1 << nl;
        return 0;
    }

    ll x = __gcd(n,w);
    cout << x-1 << " ";
    n /= x;

    x = __gcd(n,d);
    cout << x-1 << " ";
    n /= x;

    x = __gcd(n,h);
    cout << x-1 << nl;
    return 0;
}