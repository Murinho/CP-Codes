// Problem: G. Going for Gold
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/G
// Memory Limit: 512 MB
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

const ll maxn = 105;

ll n,a[maxn],b[maxn],hs;
vi res;

void solve(){
	cin>>n;
	fore(i,1,n+1) cin>>a[i];
	fore(i,1,n+1) cin>>b[i];
	
	vi v;
	fore(i,2,n+1) v.pb(i);
	
	sort(ALL(v));
	
	hs = a[1]*b[1];
	res.pb(1);
	
	fore(i,2,n+1){
		int l = 0;
		int r = sz(v)-1;
		while(l < r){
			int mid = (l+r)/2;
			if (a[i]*b[i]*v[mid] >= hs) r = mid;
			else l = mid+1;
		}
		if (a[i]*b[i]*v[l] < hs){
			cout<<"impossible"<<nl;
			return;
		}
		res.pb(v[l]);
		vi v2;
		fore(j,0,l) v2.pb(v[j]);
		fore(j,l+1,sz(v)) v2.pb(v[j]);
		v = v2;
	}
	for(auto &au : res) cout<<au<<" ";
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