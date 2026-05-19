#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;


int main(){
    fast;
    ll n;
    cin>>n;
    vi a;
    fore(i,2,n+1){
        while(n > 1 && n%i == 0){
            a.pb(i);
            n /= i;
        }
    }   
    fore(i,0,sz(a)){
        cout<<a[i];
        if (i+1<sz(a)) cout<<"x";
    }
    cout<<nl;
    return 0;
}