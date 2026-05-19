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

struct UF{
	ll pad,ran;
};

UF uf[maxn];
ll n,m,k;
vector <pii> e,em;
set <pii> st;

int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

int join(int u, int v){
	u = bus(u);
	v = bus(v);
	if (u == v) return false;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	uf[v].pad = u;
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	return true;
}

void init(){
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].ran = 0;
	}
	e.resize(m);
	em.resize(k);
}

int main(){
    fast;
    cin >> n >> m >> k;
    init();
    for(auto &[x,y] : e) cin >> x >> y;
    
    for(auto &[x,y] : em){
    	cin >> x >> y;
    	st.insert({x,y});
    	st.insert({y,x});
    }
    
    // join the initial edges
    for(auto &[x,y] : e){
    	if (!st.count({x,y})) join(x,y);
    }
    
    ll ans = 0;
    set <ll> pads;
    fore(i,1,n+1){
		ll pad = uf[bus(i)].pad;
		pads.insert(pad);    	
    }
    
    ans = sz(pads);
    
    reverse(ALL(em));
   	vi res;
   	res.reserve(k);
    for(auto &[x,y] : em){
    	res.pb(ans);
    	if (join(x,y)) ans--;
    }
    reverse(ALL(res));
    
    for(auto &elm : res) cout << elm << " ";
    cout << nl;
    return 0;
}