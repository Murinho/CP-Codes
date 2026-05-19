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

const ll maxn = 2e5+100;

map <array<ll,26>,ll>mp;
array<ll,26> a;
vi v;

int main(){
    fast;
   	string s;
   	cin >> s;
   	
   	string t = s;
   	sort(ALL(t));
   	t.erase(unique(ALL(t)),t.end());
   	
   	for(auto &elm : t){
   		int x = (int)(elm-'a');
   		v.pb(x);
   	}
   	
   	//	for(auto &elm : v) cout << elm << " ";


   	ll ans = 0;
   	mp[a]++;
   	for(auto &elm : s){
   		int x = (int)(elm-'a');
   		a[x]++;
   		
   		bool ok=true;
   		for(auto &au : v){
   			if (a[au] == 0){
   				ok = false;
   				break;
   			}
   		}
   		if (ok){
   			for(auto &au : v){
   				a[au]--;
   			}
   		}
   		
   		// for(auto &elm : a) cout << elm << " ";
   		// cout << nl;
   		
   		ans += mp[a];
   		mp[a]++;
   	}
   	cout << ans << nl;
   	return 0;
}