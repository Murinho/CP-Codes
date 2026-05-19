#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ppb pop_back
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 2e5+100;

map <ll,ll> mp;
ll a[maxn],ans,d[maxn];
ll n;

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1) cin >> a[i];

    rofe(i,n+1,1){
        d[i] = a[i] - (n-i+1);
        mp[d[i]]++;
    }

    // cout << "Deltas: " << nl;
    // fore(i,1,n+1) cout << d[i] << " ";
    // cout << nl;

    int las = n;
    mp[d[n]]--;
    fore(i,1,n+1){
        ll delta = a[las]-1;
        ll vueltas = i-1;
        ans += mp[vueltas + delta]*2;

        mp[d[i]]--; // quitar el ultimo 
        mp[a[las]-1+vueltas]++; // agregar el actual

        if (las == n){
            las = 1;
        }
        else las++;
    }

    cout << ans + n << nl;
    return 0;
}