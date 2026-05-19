// Problem: B. Binahuatls Prophecy
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 2e9+7;
const ll tope = (1ll<<15);
set <ll> st;
vi p;

ll get_num(string &s, bool keep){
	ll add = 0;
	if (keep) add = 1;
	ll pw = 1;
	ll num = 0;
	string t = "";
	fore(i,0,sz(s)){
		if (s[i] == '1') num += pw;
		pw *= 2ll;
		t += s[i];
	}
	for(int i = sz(s)-1-add; i >= 0; i--){
		if (s[i] == '1') num += pw;
		pw *= 2ll;
		t += s[i];
	}
	return num;
}

void dfs(string &s){
	if (sz(s) > 16) return;
	if (sz(s) && s.front() == '1'){
		ll num = get_num(s,true); // odd length pali.
		ll num2 = get_num(s,false); // even length pali
		//cout << num << nl;
		//cout << num2 << nl;
		st.insert(num);
		st.insert(num2);
		if (num > maxn) return;
	}
	s += "1";
	dfs(s);
	s.ppb();
	s += "0";
	dfs(s);
	s.ppb();
}

void precalc(){
	string s = "";
	dfs(s);
	for(auto &elm : st){
		p.pb(elm);
	}
}

void solve(){
	ll l,r;
	cin >> l >> r;
	ll posl = lower_bound(ALL(p),l) - p.begin();
	ll posr = upper_bound(ALL(p),r) - p.begin();
	cout << posr - posl << nl;
}

int main(){
    fast;
    precalc();
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}