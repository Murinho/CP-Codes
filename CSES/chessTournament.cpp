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

const ll maxn = 1e5+100;

ll n,a[maxn],sum=0,mx=0;
set <pii> st;
ostringstream ost;

int main(){
    fast;
   	cin >> n;
   	fore(i,1,n+1){
   		cin >> a[i];
   		sum += a[i];
   		mx = max(mx,a[i]);
   	}
   	
   	if (sum%2 == 1 || mx*2 > sum || mx >= n){
   		cout << "IMPOSSIBLE" << nl;
   		return 0;
   	}
   	
   	ost << sum/2 << nl; // amount of games to play.
   	
   	fore(i,1,n+1) if (a[i] > 0) st.insert({a[i],i});
   	
   	while(sz(st)){
   		pii bg = *st.rbegin();
   		st.erase(bg);
   		
   		if (sz(st) < bg.fst){
   			cout << "IMPOSSIBLE" << nl;
   			return 0;
   		}
   		
   		ll cnt = 0;
   		vector <pii> v;
   		
   		while(cnt < bg.fst){
   			pii aux = *st.rbegin();
   			ost << bg.snd << " " << aux.snd << nl;
   			if (aux.fst > 1) v.pb({aux.fst - 1, aux.snd});
   			st.erase(aux);
   			
   			cnt++;
   		}
   		
   		for(auto &au : v) st.insert(au);
   	}
   	
   	cout << ost.str();
   	
   	return 0;
}