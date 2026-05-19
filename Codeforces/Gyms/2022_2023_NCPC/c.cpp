#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector <Vi>
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
    string s;
    cin>>n;
    ll x=0;
    cin>>s;
    fore(i,0,n){
        if (s[i] == '1') x++;
        else if (i>0 && s[i-1] == '1') x++;
        else if (i>1 && s[i-2] == '1') x++;
    }
    cout<<x<<nl;
    return 0;
}