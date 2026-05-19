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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+50;

set <ll> st;

ll n,a[maxn],sum;

int main(){
    fast;
    cin>>n;
    fore(i,0,n) cin>>a[i];

    if (n>=20){
        cout<<"S"<<nl;
        return 0;
    }
    //Do DP Bits:
    fore(i,0,(1ll<<n)){
        sum = 0;
        fore(j,0,n){
            if ((i&(1<<j)) == (1ll<<j)) sum += a[j];
        }
        if (st.count(sum)){
            cout<<"S"<<nl;
            return 0;
        }
        st.insert(sum);
    }
    cout<<"N"<<nl;
    return 0;
}