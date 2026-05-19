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

const ll maxn = 2e5+100;
ll n,a[maxn],pref = 0,ans = 0;
map <ll,ll> mp;

ll getMod(ll x){
	return ((x%n) + n)%n;
}

int main(){
    fast;
	cin>>n;
	mp[0] = 1;
	fore(i,0,n){
		cin>>a[i];
		pref = getMod(pref + a[i]);
		ans += mp[pref];
		mp[pref]++;
	}
	cout<<ans<<nl;
	return 0;
}