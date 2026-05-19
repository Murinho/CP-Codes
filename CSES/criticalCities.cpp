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

static const ll maxn = 1e5+100;

ll n,m;
vi g[maxn],rg[maxn];
vi path;
bool vis[maxn],onpath[maxn];
ll d[maxn],pad[maxn];
bool flag = true;
ll te;

void dfs(ll node, ll dep){
	vis[node] = true;
	path.pb(node);
	
	d[node] = dep;
	
	if (node == n){
		flag = false;
		return;
	}
	
	for(auto &signode : g[node]){
		if (vis[signode]) continue;
		if (!flag) break;
		dfs(signode,dep+1);
	}
	
	if (flag){
		path.ppb();
	}
	return;
}

void explore(ll &root, ll node){
	if (vis[node]) return;
	
	if (onpath[node]){
		te = min(te,d[node]);
		if (root != node){
			return;
		}
	}
	
	vis[node] = true;
	for(auto &signode : rg[node]){
		if (signode == pad[node]) continue;
		explore(root,signode);
	}
} 


int main(){
	fast;
	cin >> n >> m;
	te = n+1;
	fore(i,0,m){
		ll x,y;
		cin >> x >> y;
		g[x].eb(y);
		rg[y].eb(x);
	}
	
	dfs(1,0);

	// mark the visited path:
	fore(i,0,sz(path)){
		onpath[path[i]] = true;
		if (i > 0) pad[path[i]] = path[i-1];
	}
	
	// cout << "Path: " << nl;
	// for(auto &elm : path) cout << elm << " ";
	// cout << nl;
	
	// unvisit all:
	fore(i,0,n+1) vis[i] = false;
	
	vi res;
	rofe(i,sz(path),0){
		if (te >= d[path[i]]) res.eb(path[i]);
		
		explore(path[i],path[i]);
		vis[path[i]] = true;
		
		// cout << path[i] << " " << d[path[i]] << " curte: " << te << nl;
	}
	
	sort(ALL(res));
	cout << sz(res) << nl;
	for(auto &elm : res) cout << elm << " ";
	cout << nl;
	return 0;
}