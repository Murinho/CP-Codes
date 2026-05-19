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
 
const ll maxn = 2e5+100;
const ll maxk = 2e5+100;
const ll loga = 18;
 
vi g[maxn+5];
ll subt[maxn][loga],dep[maxn][loga],cenpar[maxn],cnt[maxk];
bool vis[maxn]; 
ll n,centroids_root,k,ans=0;
 
static inline ll dfs_explore(ll anode, ll node, ll prof, ll &layer, vi &elms){
	dep[node][layer] = prof;
	subt[node][layer] = 1;
	elms.eb(node);
	for(auto &signode : g[node]){
		if (anode == signode || vis[signode]) continue;
		subt[node][layer] += dfs_explore(node,signode,prof+1,layer,elms);
	}
	return subt[node][layer];
}
 
static inline bool is_centroid(ll node, ll &layer, ll tam){ // check if a node is a centroid of the given layer
	ll sum = 1;
	for(auto &signode : g[node]){
		if (dep[signode][layer] > dep[node][layer]){
			sum += subt[signode][layer];
			if (subt[signode][layer] > tam/2) return false;
		}
	}
	if (tam-sum <= tam/2) return true;
	return false;
}
 
static inline void update_counts(int anode, int node, int prof, bool add_counts){
	if (add_counts) cnt[prof]++;
	else cnt[prof]--;
	
	for(auto &signode : g[node]){
		if (anode == signode || vis[signode]) continue;
		update_counts(node,signode,prof+1,add_counts);
	}
}
 
static inline void count_paths(int anode, int node, int prof, ll &layer_ans){
	if (prof > k) return;
	layer_ans += cnt[k-prof];
	
	for(auto &signode : g[node]){
		if (anode == signode || vis[signode]) continue;
		count_paths(node,signode,prof+1,layer_ans);
	}
}
 
static inline void centroid_build(ll centroid_parent, ll node, ll layer){
	vi subtree;
	ll tam = dfs_explore(node,node,1,layer,subtree);
	
	ll new_centroid = -1;
	
	for(auto &child : subtree){
		if (is_centroid(child,layer,tam)){
			vis[child]=true;
			new_centroid = child;
			cenpar[child] = centroid_parent;
			break;
		}
	}
	
	if (new_centroid == -1) return; //if reached a leaf.
	
	ll layer_ans = 0;
	update_counts(centroid_parent,new_centroid,0,1);
	layer_ans += cnt[k]; // paths of size k that start on the centroid
	
	for(auto &child : g[new_centroid]){
		if (vis[child]) continue;
		update_counts(new_centroid,child,1,0); // add the counts of each layer.
		count_paths(new_centroid,child,1,layer_ans);
		update_counts(new_centroid,child,1,1); // remove the counts of each layer.
	}
	ans += layer_ans/2;
	update_counts(centroid_parent,new_centroid,0,0);
	
	// Keep exploring the centroid tree
	for(auto &child : g[new_centroid]){
		if (vis[child]) continue;
		centroid_build(new_centroid,child,layer+1);
	}
}
 
int main(){
  fast;
  cin>>n>>k;
  fore(i,1,n){
    ll x,y;
    cin>>x>>y;
    g[x].eb(y);
    g[y].eb(x);
  } 
	
	centroid_build(-1,1,0);
	
	cout<<ans<<nl;
	return 0;
}