// Problem: G. Game of Pieces
// Contest: Codeforces - The 2025 ICPC Latin America Championship
// URL: https://codeforces.com/gym/105789/problem/G
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

const ll inf = 1e18;
set < pii > st; //{l,height}

void merge(ll new_l, ll new_h){
	auto it = st.find({new_l,new_h});
	while(st.begin() != it && (*prev(it)).snd == (*it).snd) it--;
	
	// remove from left to right, where the only surviving interval is the leftmost one.
	auto it2 = it;
	it2++;
	while(it2 != st.end() && (*it2).snd == (*it).snd){ 
		auto it3 = it2;
		it3++;
		st.erase(it2);
		it2 = it3;
	}
} 

bool ins(ll l, ll r, ll h){
	auto it = st.upper_bound({l,inf});
	it--;
	auto it2 = st.upper_bound({r,inf});
	it2--;
	if (it != it2) return false;
	
	// create the new intervals:
	ll curl = (*it).fst;
	ll curh = (*it).snd;
	it++;
	ll curr = (*it).fst - 1;
	
	if (curl == l) st.erase({curl,curh}); // remove left part of the old interval if the new interval starts there.
	st.insert({l,curh + h}); // insert middle part.
	
	// curl <= l && r <= curr
	if (r < curr){
		st.insert({r+1,curh}); // insert the right part of the old interval if the new interval doesn't end there.
	}
	
	// merge the intervals with same height:
	merge(l,curh + h);
	return true;
}

int main(){
    fast;
    ll n;
   	st.insert({0ll,0ll});
   	st.insert({inf+1,-1}); // mock interval.
   	cin>>n;
   	fore(i,0,n){
   		char c;
   		ll len,l;
   		cin>>c>>len>>l;
   		
   		if (c == '-'){
   			ll r = l + len - 1;
   			if (ins(l,r,1)) cout<<"S";
   			else cout<<"U";
   		}
   		else{
   			if (ins(l,l,len)) cout<<"S";
   			else cout<<"U";
   		}
   	}
   	cout<<nl;
   	return 0;
}