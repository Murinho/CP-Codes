#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a)  a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'

using namespace std;

const ll maxn = 1005;

ll n,a[maxn],ans=0;

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
        ll x;
        cin >> x;
        a[x]++;
    }

    fore(i,0,n+1){
        if (a[i] < i){
            ans += a[i];
        }
        else ans += a[i]-i;
    }
    cout << ans << nl;
    return 0;
}