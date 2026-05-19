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

ll n;
vi a;
bool check(){
    fore(i,0,n) if (a[i]%2) return false;
    return true;
}

int main(){
    fast;
    cin>>n;
    a.resize(n);
    fore(i,0,n) cin>>a[i];

    sort(ALL(a));

    if (a.back() == 1) cout<<1<<nl;
    else if (check()) cout<<1<<nl;
    else cout<<2<<nl;
    return 0;
}