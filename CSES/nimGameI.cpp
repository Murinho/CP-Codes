#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

ll tc,n,x,xo;

int main(){
    fast;
    cin>>tc;
    while(tc--){
        cin>>n;
        xo=0;
        fore(i,0,n){
            cin>>x;
            xo ^= x;
        }
        if (xo) cout<<"first"<<nl;
        else cout<<"second"<<nl;
    }
    return 0;
}