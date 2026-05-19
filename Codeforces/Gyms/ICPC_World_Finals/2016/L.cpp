#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

vector<pii> a,b;

bool cmp(pii &p1, pii &p2){
	if (p1.snd == p2.snd) return p1.fst > p2.fst;
	return p1.snd > p2.snd;
}

bool check(ll free){
	for(auto &[x,y] : a){
		if (x > free) return false;
		free += y-x;
	}
	for(auto &[x,y] : b){
		if (x > free) return false;
		free += y-x; // will substract.
	}
	return true;
}

void solve(){
	ll n,x,y;
	cin>>n;
	fore(i,0,n){
		cin>>x>>y;
		if (x <= y) a.pb({x,y});
		else b.pb({x,y});
	}
	
	sort(ALL(a)); // Sorted in increasing order before reformatting.
	sort(ALL(b),cmp); // Sorted in decreasing order after reformatting.
	
	ll l = 1;
	ll r = 1e15;
	while(l < r){
		ll mid = (l+r)/2ll;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	cout<<l<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}