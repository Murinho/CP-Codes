#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define PI 3.1415926535
#define lsb(x) ((x)&(-x))
    
using namespace std;
 
const ll maxn = 510;
const ll INF = 1e9+7;
const ll mod = 1e9+7;
const ll loga = 31;
 
ll dp[maxn][maxn],n,p[maxn][maxn];
string s;
 
void precalc(){
	p[0][0]=1;
	fore(i,1,maxn){
		p[i][0]=1;
		p[i][i]=1;
		fore(j,1,i) p[i][j] = (p[i-1][j-1] + p[i-1][j])%mod;
	}
}
 
ll nck(ll a, ll b){
	if (a < b) return 0;
    return p[a][b];
}
 
int main(){
	fast;
	cin>>s;
	n = s.size();
	precalc();
	if (n%2){
		cout<<0<<nl;
		return 0;
	}
	fore(i,0,n+1) dp[i+1][i]=1;
 
	//starts:
	for(ll i = n-1; i>=0; i--){ //starting position of range.
		for(ll j = i+1; j<n; j += 2){ //size of the range.
			for(ll k = i+1; k<=j; k += 2){ //cut point.
				if (s[i] == s[k]){
					ll dpmul = (dp[i+1][k-1]*dp[k+1][j])%mod;
					ll add = (dpmul*nck((j-i+1)/2,(k-i+1)/2))%mod;
					dp[i][j] = (dp[i][j] + add)%mod;
				}
			}
		}
	}
 
	cout<<dp[0][n-1]<<nl;
	return 0;
}