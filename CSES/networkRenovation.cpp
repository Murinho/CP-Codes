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

ll n,m;
vi g[maxn];
bool vis[maxn];
vi leaves;

void dfs(int anode, int node){
	if (sz(g[node]) == 1){
		leaves.pb(node);
	}
	else{
		for(auto &signode : g[node]) if (anode != signode) dfs(node,signode);
 	}
}

int main(){
    fast;
    cin >> n;
    fore(i,1,n){
    	ll x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    
    fore(i,1,n+1){
    	if (sz(g[i]) > 1){
    		dfs(i,i);
    		break;
    	}
    }
    
    cout << sz(leaves)/2 + (sz(leaves)%2) << nl;
    ll mid = sz(leaves)/2;
    fore(i,0,mid){
    	cout << leaves[i] << " " << leaves[mid+i] << nl;
    }
    
    if (sz(leaves)%2) cout << leaves.front() << " " << leaves.back() << nl;
    
    return 0;
}