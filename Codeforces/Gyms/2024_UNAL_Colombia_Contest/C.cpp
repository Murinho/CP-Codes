// Problem: C. s-parkour
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/C
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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 1e6+100;
ll a[maxn],n,ans,d[maxn];

map <ll,ll> mp;

int main(){
    fast;
	cin>>n;
	fore(i,1,n+1) cin>>a[i];
	
	ll cnt = 0;
	fore(i,2,n+1){
		if (a[i-1] > a[i]) cnt--;
		else cnt++;
		d[i] = cnt;
		mp[cnt]++;
	}
	cnt = 0;
	fore(i,1,n){
		ans += mp[cnt*(-1)];
		mp[d[i+1]]--;
		if (a[i] > a[i+1]) cnt++;
		else cnt--;
	}
	cout<<ans + n<<nl;
}