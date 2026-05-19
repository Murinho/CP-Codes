// Problem: A. Alfajores
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/A
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

ll n,q;
vi d;
vi a;

void init(){
	a.resize(q);
	d.resize(n);
}

int main(){
    fast;
    cin>>n>>q;
    init();
    fore(i,0,n) cin>>d[i];
    fore(i,0,q) cin>>a[i];
    
    ll las = 0;
    fore(i,1,q){
    	if (a[i] >= a[las]) a[i] = -1;
    	else las = i;
    }
    vi b;
    fore(i,0,q) if (a[i] > 0) b.pb(a[i]);
    
    reverse(ALL(b)); // increasing order now.
    
    //for(auto &elm : b) cout<<elm<<" ";
    //cout<<nl;
    
    fore(i,0,n){
    	ll x = d[i];
    	while(b.front() <= x){
    		if (b.back() <= x) x %= b.back();
    		else{ //binary search
    			ll pos = upper_bound(ALL(b),x) - b.begin();
    			pos--;
    			x %= b[pos];
    		}
    	}
    	cout<<x<<" ";
    }
    cout<<nl;
    return 0;
}