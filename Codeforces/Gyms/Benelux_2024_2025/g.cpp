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
#define sz(a) ((ll) a.size())
#define ALL(a) a.begin(),a.end()
#define ppb pop_back

using namespace std;

const ll inf = 1e9;
const double eps = 1e-6;
ll n,ans=0;
vi a[5];

void solve_rest(ll id){
    while(sz(a[id]) > id-2){ // 3 is 1, 4 is 2.
        ll sum = 0;
        fore(i,0,id-1){
            sum += a[id].back();
            a[id].ppb();
        }
        ans += (sum-(id-2)); //mod 1
    }

    while(sz(a[id])){
        ans += a[id].back();
        a[id].ppb();
    }
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n){
        ll x,y;
        char c;
        cin>>x>>c>>y;
        x *= 100;
        x += y;
        //cout<<x<<" ";
        ll md = x%5;
        a[md].pb(x);
    }
    //cout<<nl;

    /*
    cout<<"sizes: "<<nl;
    fore(i,0,5){
        cout<<i<<": "<<sz(a[i])<<nl;
    } */

    // add to answer the values with mod%5 <= 2.
    fore(i,0,3){
        for(auto &elm : a[i]) ans += (elm-i);
    }

    // handle case of 3's and 4's.
    while(sz(a[3]) && sz(a[4])){
        ll sum = a[3].back() + a[4].back();
        ans += (sum-2); // mod 2
        a[3].ppb(), a[4].ppb();
    }

    solve_rest(3);
    solve_rest(4);

    double dans = (double)ans/100.0;
    cout<<fixed<<setprecision(2)<<dans<<nl;
    return 0;
}