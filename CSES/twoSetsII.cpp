#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace __gnu_pbds;
using namespace std;

const ll mod = 1e9+7;
const ll maxn = 62680;
const ll loga = 31;

ll dp[maxn],g,n,tar;

ll inverse(ll b, ll pw){
    ll expo = b;
    ll pot = 1;
    ll res = 1;
    for (int i = 1; i<=loga; i++){
        if ((pot | pw) == pw){
            res = (res*expo)%mod;
        }
        expo = (expo*expo)%mod;
        pot *= 2;
    }
    return res;
}

int main(){
    fast;
	cin>>n;
	g = (n*(n+1))/2;
	dp[0] = 1;
	if (g%2){
		cout<<0<<nl;
		return 0;
	}
	tar = g/2;
	fore(i,1,n+1){
		for(int j = tar-i; j>=0; j--){
			if (dp[j]) dp[j+i] = (dp[j+i] + dp[j])%mod;
		}
	}
	cout<<(dp[tar]*inverse(2ll,mod-2))%mod<<nl;
	return 0;
}