#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(), u.end()
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second;

using namespace std;


int main(){
    fast;
    ll n;
    cin>>n;
    vi a(n);
    fore(i,0,n) cin>>a[i];

    sort(ALL(a));
    reverse(ALL(a));
    ll ans=0,ps;
    fore(i,0,n){
        if (a[i]*(i+1) > ans){
            ans = a[i]*(i+1);
            ps = a[i];
        }
    }
    cout<<ps<<" "<<ans<<nl;
    return 0;
}