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

const ll INF = 1e18;
const ll maxn = 5010;
ll n,a[maxn],dp[maxn][maxn],p[maxn];

void init(){
	//Init DP:
	fore(i,0,n+1) fore(j,0,n+1) dp[i][j] = -INF;
	
	//Prefix sum:
	p[0] = 0;
	fore(i,1,n+1) p[i] = a[i] + p[i-1];
}

ll getSum(int l, int r){
	return p[r] - p[l-1];
}

ll solve(int l, int r){
	if (dp[l][r] != -INF) return dp[l][r];
	if (l == r) return a[l];
	return dp[l][r] = getSum(l,r) - min(solve(l+1,r),solve(l,r-1));
}

int main(){
    fast;
	cin>>n;
	fore(i,1,n+1) cin>>a[i];
	
	init();
	cout<<solve(1,n)<<nl;
	return 0;
}