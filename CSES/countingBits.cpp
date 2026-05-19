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
 
const ll bitmax = 50;

ll n,ans=0;

int main(){
    fast;
    cin>>n;
    fore(i,0,bitmax){
        ll chunk = (1ll<<(i+1));
        ll full_chunks = n/chunk;
        ans += (full_chunks*(1ll<<i));
        //compute the remainder.
        ll rem = n%chunk;
        ans += max(0ll,rem-(1ll<<i)+1);
    }
    cout<<ans<<nl;
    return 0;
}