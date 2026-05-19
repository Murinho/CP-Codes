// Problem: A. Azulejos
// Contest: Codeforces - 2019 ICPC World Finals
// URL: https://codeforces.com/gym/102511/problem/A
// Memory Limit: 256 MB
// Time Limit: 10000 ms
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
#define all(u) u.begin(),u.end()
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e6+100;
const ll inf = 1e9+7;

ll p[maxn][2],h[maxn][2];
ll n;
vi a,b;
vi ra,rb;
map <ll, vector <pii> > mpa,mpb;
set <ll> seena,seenb;
set < pii > msa,msb; // {height, id}.


void solve(){
	cin>>n;
	fore(i,0,n){
		cin>>p[i][0];
		a.pb(p[i][0]);
	}
	fore(i,0,n) {
		cin>>h[i][0];
		mpa[p[i][0]].pb({h[i][0], i+1});
	}
	fore(i,0,n){
		cin>>p[i][1];
		b.pb(p[i][1]);
	}
	fore(i,0,n){
		cin>>h[i][1];
		mpb[p[i][1]].pb({h[i][1], i+1});
	}
	
	sort(all(a));
	sort(all(b));
	a.pb(0), b.pb(0);
	
	/*
	cout<<"Heights A: "<<nl;
	for(auto &au : a) cout<<au<<" ";
	cout<<nl;
	cout<<"Heights B: "<<nl;
	for(auto &au : b) cout<<au<<" ";
	cout<<nl; */
	int pos = 0;
	while(pos < n){
		if (!seena.count(a[pos])){
			seena.insert(a[pos]);
			for(auto &au : mpa[a[pos]]) msa.insert(au); // insert all {height,id} to the multiset of a.
		}
		if (!seenb.count(b[pos])){
			seenb.insert(b[pos]);
			for(auto &au : mpb[b[pos]]) msb.insert({-au.fst,au.snd}); // pushing them as negatives.
		}
		
		if (a[pos] != a[pos+1]){ // stop here, focus on a.
			while(sz(msa)){
				auto [h,id] = *msa.begin();
				msa.erase({h,id});
				
				auto it = msb.upper_bound({-h,inf});
				if (it == msb.end()){
					cout<<"impossible"<<nl;
					return;
				}
				ll id2 = (*it).snd;
				
				ra.pb(id);
				rb.pb(id2);
				
				msb.erase(it);
			}
		}
		else if (b[pos] != b[pos+1]){ // stop here, focus on b.
			while(sz(msb)){
				auto [h,id] = *msb.begin();
				msb.erase({h,id});
				
				auto it = msa.upper_bound({-h, inf});
				if (it == msa.end()){
					cout<<"impossible"<<nl;
					return;
				}
				ll id2 = (*it).snd;
				rb.pb(id);
				ra.pb(id2);
				
				msa.erase(it);
			}
		}
		pos++;
	}
	
	for(auto &elm : ra) cout<<elm<<" ";
	cout<<nl;
	for(auto &elm : rb) cout<<elm<<" ";
	cout<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}