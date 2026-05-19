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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e5+100;

set <ll> st;
ll n,c[maxn];
vi p;
bool f=false;
ll a[maxn],b[maxn];

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1) cin >> a[i];
    fore(i,1,n+1) cin >> b[i];
    
    ll pref = max(0ll,n-8);

	fore(i,1,n+1) st.insert(i);
	
	fore(i,1,pref+1){
		vi v;
		while(*st.begin() == a[i] || *st.begin() == b[i]){
			v.pb(*st.begin());
			st.erase(st.begin());
		}
		c[i] = *st.begin();
		st.erase(st.begin());
		
		for(auto &elm : v) st.insert(elm);
	}
	
	for(auto &elm : st) p.pb(elm);
	
	sort(ALL(p));
	
	do{
		f = true;
		fore(j,pref+1,n+1){
			if (a[j] == p[j-pref-1] || b[j] == p[j-pref-1]){
				f = false;
				break;
			}
			c[j] = p[j-pref-1];
		}
		if (f) break;
		
	}while(next_permutation(ALL(p)));
	
	if (!f) cout << "IMPOSSIBLE" << nl;
	else{
		fore(i,1,n+1) cout << c[i] << " ";
		cout << nl;
	}
	
	return 0;
}