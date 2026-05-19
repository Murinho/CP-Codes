// Problem: K. Wireless is the New Fiber
// Contest: Codeforces - 2018 ACM-ICPC World Finals
// URL: https://codeforces.com/gym/102482/problem/K
// Memory Limit: 256 MB
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

const ll maxn = 1e4+100;

ll n,m;
vector <pii> edges;

int main(){
	fast;
	cin >> n >> m;
	vector <pii> v(n);
	fore(i,0,n) v[i].snd = i;
	fore(i,0,m){
		ll x,y;
		cin >> x >> y;
		v[x].fst++, v[y].fst++;
	}
	
	sort(ALL(v));
	
	ll bad_nodes = 0, tot = m*2;
    for (int i = sz(v)-1; tot > 2*n-2; i--) {
      ll amt = min(tot-(2*n-2), v[i].fst-1);
      tot -= amt;
      v[i].fst -= amt;
      bad_nodes++;
    }
    
    sort(ALL(v));
    
	cout << bad_nodes << nl;
	cout << n << " " << n-1 << nl;
	if (n == 2){
		cout << 0 << " " << 1 << nl;
		return 0;
	}
	
	vector <ll> st;
	ll i;
	for(i = 0; v[i].fst == 1; i++){
		st.pb(v[i].snd); //push the index.
	}
	
	for(; i<sz(v); i++){
		for(ll j = 0; j < v[i].fst - (i+1 < sz(v)); j++){
			cout << v[i].snd << " " << st.back() << nl;
			st.ppb();
		}
		st.pb(v[i].snd);
	}
	
	for(auto &[x,y] : edges) cout << x << " " << y << nl;
	return 0;
}