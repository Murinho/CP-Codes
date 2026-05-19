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

const ll maxn = 1e18;
ll n,k;
vi a;

void init(){
	a.clear(), a.resize(n);
}

bool check(ll tar){
	ll amou = 0;
	fore(i,0,n){
		amou += (tar/a[i]);
		if (amou >= k) return true;
	}
	return amou >= k;
}

int main(){
    fast;
	cin>>n>>k;
	init();
	fore(i,0,n) cin>>a[i];
	
	ll l = 1;
	ll r = maxn;
	while(l < r){
		ll mid = (l+r)/2ll;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	cout<<l<<nl;
	return 0;
}