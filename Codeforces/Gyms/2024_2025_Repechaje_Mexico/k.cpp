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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll k;
string s;

void solve2(){
	string s1 = s;
	string s2 = s;
	ll ans1 = 0;
	ll ans2 = 0;
	
	// start with 0
	fore(i,0,sz(s1)){
		if (i%2 == 0){
			if (s1[i] == '1'){
				ans1++;
				s1[i] = '0';
			}
		}
		else{
			if (s1[i] == '0'){
				ans1++;
				s1[i] = '1';
			}
		}
	}
	
	// start with 1
	fore(i,0,sz(s2)){
		if (i%2 == 0){
			if (s2[i] == '0'){
				ans2++;
				s2[i] = '1';
			}
		}
		else{
			if (s2[i] == '1'){
				ans2++;
				s2[i] = '0';
			}
		}
	}
	
	if (ans1 < ans2) cout << ans1 << " " << s1 << nl;
	else cout << ans2 << " " << s2 << nl;
}

void solve3(){
	ll ans = 0;
	ll stk = 1;
	fore(i,1,sz(s)){
		if (s[i-1] != s[i]){
			stk = 1;
		}
		else{
			stk++;
			if (stk == k){
				ans++;
				if (s[i-1] == '0') s[i] = '1';
				else s[i] = '0';
				
				if (i+1 < sz(s) && s[i] == s[i+1]) swap(s[i-1],s[i]);
				stk = 1;
			}
		}
	}
	
	cout << ans << " " << s << nl;
	return;
}

int main(){
    fast;
  	cin >> k;
  	cin >> s;
  	if (k == 2){
  		solve2();
  	}
  	else{
  		solve3();
  	}
}