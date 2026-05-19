#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define RB(x) (x<n?r[x]:0)
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll n,k,gn;
const ll INF = 2e18;

ll g(ll x){
    return (x*(x+1))/2ll;
}

ll f(ll &x){
    ll mx = max(x,n-x);
    if (k < INF/mx){
        ll pos = g(x)+(k*x);
        ll neg = (gn - g(x))+(k*(n-x));
        return abs(pos-neg);
    }
    return INF;
}

ll ts(){
    ll l = 1;
    ll r = n;
    gn = g(n);
    while(l+2 < r){
        ll m1 = l + (r-l)/3;
        ll m2 = r - (r-l)/3;
        ll f1 = f(m1)*(-1);
        ll f2 = f(m2)*(-1);
        if (f1 < f2) l = m1;
        else r = m2;
    }
    ll ret = INF;
    fore(i,l,min(l+3,k+n)){
        ret = min(ret,f(i));
    }
    return ret;
}


int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        k--;
        cout<<ts()<<nl;
    }   
    return 0;
}