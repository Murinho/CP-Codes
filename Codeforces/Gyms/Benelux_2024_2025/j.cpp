#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define fst first
#define snd second

using namespace std;


int main(){
    fast;
    ll n;
    cin>>n;
    ll px = 0;
    ll py = 0;
    bool ok=true;
    fore(i,0,n){
        ll x,y;
        cin>>x>>y;
        if (x < px) ok=false;
        if (y < py) ok=false;
        px = x;
        py = y;
    }   
    cout<<(ok ? "yes" : "no")<<nl;
    return 0;
}