#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

vi v;
ll n;

void init(){
    v.clear(), v.resize(n+1);
}

ll solve(vi a){
    ll cy = 0;
    init();
    fore(i,1,n+1){
        if (!v[i]){
            cy++;
            int pos = i;
            while(!v[pos]){
                v[pos]=1;
                pos = a[pos];
            }
        }
    }
    return (n-cy);
}

int main(){
    fast;
    
    cin>>n;
    vi a(n+1), b(n+1);

    fore(i,1,n+1) cin>>a[i];
    fore(i,1,n+1) cin>>b[i];

    cout<<solve(a) + solve(b)<<nl;
    return 0;
}