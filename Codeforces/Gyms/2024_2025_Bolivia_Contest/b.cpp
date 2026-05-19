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

const ll INF = 1e18;

ll n,k,mx,x;

int main(){
    fast;
    cin>>n;
    while(n--){
        cin>>k;
        vi a(k);
        fore(i,0,k) cin>>a[i];

        sort(ALL(a));

        ll ans = (1ll<<(a.back()-1));
        fore(i,0,sz(a)-1){
            ans += (1ll<<(a[i]-1));
        }
        cout<<ans<<nl;
    }
    return 0;
}