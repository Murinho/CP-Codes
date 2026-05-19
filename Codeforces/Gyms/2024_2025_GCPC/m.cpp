#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first 
#define snd second

using namespace std;

const ll INF = 1e18;
const ll maxn = 2e5+5;

ll n,a[maxn],sum[maxn],ans;
vi b;

int main(){
    fast;
    cin>>n;
    ans = INF;
    fore(i,0,n){
        cin>>a[i];
        b.pb(a[i]-i);
    }
    sort(ALL(b));
    //calculate sum:
    fore(i,0,n){
        sum[i] = b[i] + (i>0 ? sum[i-1] : 0);
    }
    fore(i,0,n){
        ll lft = (i>0 ? sum[i-1] : 0);
        ll lamou = i;
        ll rt = (i<n ? sum[n-1]-sum[i] : 0);
        ll ramou = n-i-1;
        ll aux = abs((lamou*b[i])-lft) + abs((ramou*b[i])-rt);
        ans = min(ans,aux);
    }
    cout<<ans<<nl;
    return 0;
}