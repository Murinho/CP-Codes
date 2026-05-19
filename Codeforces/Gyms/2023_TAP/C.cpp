// Problem: C. Chromatic
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/C
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll inf = 1e18;
const ll maxn = 1e5+100;
ll mn,mx;
ll n;
vi a,b;

void init(){
	mn = inf;
	mx = -inf;
	a.clear(), a.resize(n);
	b.clear(), b.resize(n);
}

ll test(){
	mn = inf;
	mx = -inf;
	fore(i,0,n){
		ll sum = a[i] + b[i];
		mx = max(sum,mx);
		mn = min(sum,mn);
	}
	
	return mx-mn;
}

int main(){
    fast;
   	cin>>n;
   	init();
   	fore(i,0,n) cin>>a[i];
   	fore(i,0,n) cin>>b[i];
   	
   	sort(ALL(a));
   	sort(ALL(b));
   	
   	reverse(ALL(a));
   	
   	ll ans = test();
   	reverse(ALL(a));
   	reverse(ALL(b));
   	
   	ans = min(ans,test());
   	
   	cout<<ans<<nl;
}