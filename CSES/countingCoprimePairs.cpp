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
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 1e5+10;
const ll maxval = 1e6+10;

ll n,ans,f[maxval],mult[maxval],v[maxval],pa[maxval];

void criba(){
    fore(i,2,maxval){
        if (!v[i]){
            pa[i]++; //prime amount.
            for(int j = 2; i*j<maxval; j++){
                v[i*j]=1;
                pa[i*j]++;
                ll x = i*j;
                ll cnt=0;
                while(x%i == 0){
                    x /= i;
                    cnt++;
                }
                if (cnt > 1) mult[i*j]=1;
            }
        }
    }
}

ll gauss(ll x){
    return (x*(x+1))/2;
}

int main(){
    fast;
    cin>>n;
    criba();
    ans=gauss(n-1);
    fore(i,0,n){
        ll x;
        cin>>x;
        f[x]++;
    }
    fore(i,2,maxval){
        if (mult[i]) continue;
        ll cnt=0;
        for(int j = 1; i*j<maxval; j++){
            cnt += f[i*j];
        }
        ll g = gauss(cnt-1);
        if (pa[i]%2) ans -= g;
        else ans += g;
    }
    cout<<ans<<nl;
    return 0;
}