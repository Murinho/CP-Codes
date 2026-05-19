// Problem: H. Prehistoric Programs
// Contest: Codeforces - 2021 ICPC World Finals
// URL: https://codeforces.com/gym/104288/problem/H
// Memory Limit: 2048 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

ll n;

pii get_info(string &s){
	ll cur = 0;
	ll mn = 0;
	for(auto &au : s){
		if (au == '(') cur++;
		else{
			cur--;
			mn = min(mn,cur);
		}
	}
	return {cur,abs(mn)};
}

void solve(){
	cin>>n;
	vvi a,b;
	ll sum = 0;
	fore(i,1,n+1){
		string s;
		cin>>s;
		auto [ed,mn] = get_info(s);
		if (0 <= ed) a.pb({mn, ed, i});
		else b.pb({ed + mn, -ed, i});
		sum += ed;
	}
	
	if (sum != 0){
		cout<<"impossible"<<nl;
		return;
	}
	
	sort(ALL(a));
	sort(ALL(b));
	
	vi p;
	ll cd = 0; // current delta
	
	// first process all the strings that give non-negative end delta.
	fore(i,0,sz(a)){
		if (a[i][0] > cd){
			cout<<"impossible"<<nl;
			return;
		}
		cd += a[i][1];
		p.pb(a[i][2]);
	}
	
	vi p2;
	
	// then process all the strings that have negative end delta.
	fore(i,0,sz(b)){
		if (b[i][0] > cd){
			cout<<"impossible"<<nl;
			return;
		}
		cd += b[i][1];
		p2.pb(b[i][2]);
	}
	
	for(auto &au : p) cout<<au<<nl;
	reverse(ALL(p2));
	for(auto &au : p2) cout<<au<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}