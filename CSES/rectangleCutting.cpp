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

const ll maxn = 502;
const ll INF = 1e9+7;

ll dp[maxn][maxn];

void init(){
	fore(i,0,maxn){
		fore(j,0,maxn) dp[i][j] = INF;
		dp[i][i] = 0;
	}
}

void computeDp(ll x, ll y){
	if (x == y) return;
	//Do a vertical cut:
	fore(i,1,x){
		if (dp[i][y] == INF) computeDp(i,y);
		if (dp[x-i][y] == INF) computeDp(x-i,y);
		dp[x][y] = min(dp[x][y], dp[i][y] + dp[x-i][y] + 1);
	}
	//Do a horizontal cut:
	fore(i,1,y){
		if (dp[x][i] == INF) computeDp(x,i);
		if (dp[x][y-i] == INF) computeDp(x,y-i);
		dp[x][y] = min(dp[x][y], dp[x][i] + dp[x][y-i] + 1);
	}
	return;
}

int main(){
    fast;
	ll x,y;
	cin>>x>>y;
	init();
	computeDp(x,y);
	cout<<dp[x][y]<<nl;
	return 0;
}