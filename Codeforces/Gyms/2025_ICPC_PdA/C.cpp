// Problem: C. Coatless in Yakutsk
// Contest: Codeforces - The 2025 ICPC Latin America Championship
// URL: https://codeforces.com/gym/105789/problem/C
// Memory Limit: 1024 MB
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

ll n,k;
vi a;

bool check(ll tope){
	int cnt = 0;
	fore(i,0,n){
		if (a[i] >= tope){ // if the temp is equal or higher.
			cnt = 0;
		}
		else{
			cnt++;
			if (cnt > k) return false;
		}
		//cout<<i<<": "<<cnt<<nl;
	}
	return true;
}

int main(){
    fast;
    cin>>k>>n;
	a.resize(n);
    fore(i,0,n) cin>>a[i];
    
    vi b = a;
    sort(ALL(b));
    b.erase(unique(ALL(b)),b.end());
    int l = 0;
    int r = sz(b)-1;
    
    //for(auto &au : b) cout<<au<<" ";
    //cout<<nl;
    
    while(l < r){
    	ll mid = (l+r+1)/2;
    	if (check(b[mid])) l = mid;
    	else r = mid-1;
    }
    cout<<b[l]<<nl;
    return 0;
}