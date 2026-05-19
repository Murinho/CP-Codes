// Problem: F. Cold day at the beach
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/F
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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
ll n,h,w,tx,ty;
ll ans;

struct Disc{
	ll x,y,t;
};

ll dist(Disc d){
	ll dx = abs(d.x-tx);
	ll dy = abs(d.y-ty);
	return (dx*dx) + (dy*dy);
}

vector <Disc> a;

int main(){
    fast;
    cin>>n;
    cin>>h>>w>>tx>>ty;
    ll c0 = inf;
    ll c1 = inf;
    Disc d;
    d.t = 0;
    fore(i,0,n){
    	cin>>d.x>>d.y;
    	a.pb(d);
    	c0 = min(c0,dist(d));
    }
    d.t = 1;
    fore(i,0,n){
    	cin>>d.x>>d.y;
    	a.pb(d);
    	c1 = min(c1,dist(d));
    }
    
    if (c0 < c1) cout<<"A ";
    else cout<<"R ";
    
    for(auto &d : a){
    	if (c0 < c1){
    		if (d.t == 0 && dist(d) < c1) ans++;
    	}
    	else{
    		if (d.t == 1 && dist(d) < c0) ans++;
    	}
    }
    cout<<ans<<nl;
    return 0;
}