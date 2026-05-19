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

const ll mod = 1e9+7;
const ll maxn = 1e5+10;
const ll loga = 31;
ll n,a[maxn],b[maxn];

ll exponentiate(ll base, ll pow) {
	ll ans = 1;
	while (pow) {
		if (pow & 1) ans = ans * base % mod;
		base = base * base % mod;
		pow >>= 1;
	}
	return ans;
}

ll geometricSum(ll x, ll pw){
    ll numerator = (exponentiate(x,pw+1)-1+mod)%mod;
    ll denominatorInverse = exponentiate(x-1,mod-2);
    return (numerator*denominatorInverse)%mod;
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n) cin>>a[i]>>b[i];

    ll div_cnt=1,div_sum=1,div_prod=1,div_cnt2=1;
    fore(i,0,n){
        div_cnt = div_cnt * (b[i]+1)%mod;
        div_sum = (div_sum * geometricSum(a[i],b[i]))%mod;
        div_prod = (exponentiate(div_prod,b[i]+1)*exponentiate(exponentiate(a[i],(b[i]*(b[i]+1)/2ll)),div_cnt2))%mod;
        div_cnt2 = div_cnt2 * (b[i]+1)%(mod-1);
    }

    cout<<div_cnt<<" "<<div_sum<<" "<<div_prod<<nl;

    return 0;
}