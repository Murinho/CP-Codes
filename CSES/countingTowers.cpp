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
 
using namespace std;

const ll mod = 1e9+7;
const ll maxn = 1e6+100;
ll dp[maxn][2],tot;

void precalc(){
	dp[1][1] = dp[1][2] = 1;
	fore(i,2,maxn-5){
		dp[i][1] = (((dp[i-1][1]*4)%mod) + dp[i-1][2])%mod;
		dp[i][2] = (dp[i-1][1] + (dp[i-1][2]*2))%mod;
	}
	return;
}

int main(){
    fast;
	precalc();
	ll tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		cout<<(dp[n][1] + dp[n][2])%mod<<nl;
	}
	return 0;
}