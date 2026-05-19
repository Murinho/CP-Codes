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

const ll maxn = 2e5+100;

ll n,a[maxn],p[maxn],s[maxn],b[maxn];

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1) cin>>a[i];

    p[1] = a[1];
    fore(i,2,n+1){
        if (a[i-1] <= a[i]) p[i] = p[i-1];
        else p[i] = a[i], b[i]=1;
    }
    s[n] = a[n];
    for(int i = n-1; i>=1; i--){
        if (a[i+1] <= a[i]) s[i] = s[i+1];
        else s[i] = a[i], b[i]=1;
    }
    ll x=0;
    fore(i,1,n+1){
        if (!b[i]) x = max(x,min(a[i]-p[i],a[i]-s[i]));
    }
    cout<<x<<nl;
    return 0;
}