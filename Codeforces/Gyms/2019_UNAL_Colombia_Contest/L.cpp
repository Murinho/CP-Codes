// Problem: L. Liquid X
// Contest: Codeforces - 2019 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/102307/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const ll maxn = 1e6;

ll n,a[maxn+10],dp[maxn+10],mp[maxn+10],p[maxn+10],pre[maxn+10];

string getResponse(ll tar){
	vi b(105,0);
	int now = mp[tar];
	while(now){
		b[p[now - pre[now]]]++;
		now = pre[now];
	}
	cout<<1<<nl;
	fore(i,1,n+1) cout<<b[i]<<" ";
	cout<<nl;
	cout.flush();
	string res;
	cin>>res;
	return res;
}

int main(){
    fast;
	cin>>n;
	fore(i,1,n+1) cin>>a[i];
	
	dp[0] = 1;
	fore(i,1,n+1){
		for(int j = maxn-a[i]; j>=0; j--){
			if (dp[j]) dp[j+a[i]]=1, pre[j+a[i]] = j;
		}
	}
	int cnt = 0;
	fore(i,1,maxn+1) mp[++cnt] = i;
	
	fore(i,1,n+1) p[a[i]] = i;
	
	ll l = 1;
	ll r = cnt;
	ll mid;
	ll ans = -1;
	string res = "";
	while(l <= r){
		mid = (l+r)/2;
		res = getResponse(mid);
		if (res == "yellow"){
			ans = mp[mid];
			break;
		}
		else if (res == "green") l = mid+1;
		else r = mid-1;
	}
	if (ans == -1){
		if (mp[mid] == 2 && res == "red") ans = 1;
		else if (mp[mid] == maxn-1 && res == "green") ans = maxn;
		else if (abs(mp[r]-mp[l]) == 2) ans = min(mp[l],mp[r]) + 1;
	}
	cout<<2<<nl;
	cout<<ans<<nl;
	cout.flush();
	return 0;
}