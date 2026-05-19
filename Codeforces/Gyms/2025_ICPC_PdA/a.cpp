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
#define ALL(u) u.begin(),u.e	nd()
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


const ll maxn = 5010;
ll n,m;
vector < pair <int,char> > g[maxn],rg[maxn];
bool vis[maxn][maxn];
ll ans = 0;

void dfs(int l, int r){
	if (vis[l][r]) return;
	vis[l][r]=true;
	
	if (l != r) ans++;
	
	for(auto &sl : g[l]){
		for(auto &sr : rg[r]){
			if (sl.snd == sr.snd) dfs(sl.fst,sr.fst);
		}
	}
}

int main(){
    fast;
    cin>>n>>m;
    fore(i,0,m){
    	int x,y;
    	char c;
    	cin>>x>>y;
    	cin>>c;
    	g[x].pb({y,c});
    	rg[y].pb({x,c});
    }
    
    // start dfs from a node:
    fore(i,1,n+1) dfs(i,i);
    
    // start dfs from an edge.
    fore(i,1,n+1){
    	for(auto &sr : rg[i]){
    		if (!vis[i][sr.fst]) dfs(i,sr.fst);
    	}
    }
    
    cout<<ans<<nl;
    return 0;
}