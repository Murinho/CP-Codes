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
 
using namespace std;

const ll maxn = 2e5+10;
const ll loga = 18;
const ll neut = 1e9+7;
const ll inf = 1e9+7;

vi g[maxn];
ll n,q,qrys,label_cont;
ll up[maxn][loga],subt[maxn],dep[maxn];
ll labe[maxn],tp[maxn],revlabe[maxn],st[maxn*4],p[loga];
ll d[maxn],c[maxn],arr[maxn];

ll query(int l, int r, int node = 1, int ini = 1, int fin = n){
	if(fin < l || r < ini) return neut; // operation neutral
	if(l <= ini && fin <= r) return st[node];
	int mid =(ini+fin)/2;
	return min(query(l,r,2*node,ini,mid),query(l,r,2*node+1,mid+1,fin)); // operation
}

void build(int node = 1, int ini = 1, int fin = n){
	if (ini == fin){
		st[node] = arr[ini];
		return;
	}
	int mid = (ini+fin)/2;
	build(2*node,ini,mid);
	build(2*node + 1,mid+1,fin);
	st[node] = min(st[2*node],st[2*node + 1]);
}
 
void init(){
	label_cont = 1;
	p[0] = 1;
	fore(i,1,loga) p[i] = (p[i-1] * 2LL);
}
 
ll dfs_sz(int cur, int par) {
	subt[cur] = 1;
	for (auto &chi : g[cur]) {
		if (chi == par) continue;
		dep[chi] = dep[cur] + 1;
		up[chi][0] = cur;
		subt[cur] += dfs_sz(chi, cur);
	}
	return subt[cur];
}
 
void dfs_hld(int cur, int par, int top) {
	labe[cur] = label_cont++;
	tp[cur] = top;
	// if assigning value here do: arr[labe[cur]] = val and after doing Euler Tour build the SegTree
	arr[labe[cur]] = d[cur];
	// upd(labe[cur], d[cur]); //updating the STree using the labeling.
	int h_chi = -1, h_sz = -1;
	for (auto &chi : g[cur]) {
		if (chi == par) continue;
		if (subt[chi] > h_sz) {
			h_sz = subt[chi];
			h_chi = chi;
		}
	}
	if (h_chi == -1) return;
	dfs_hld(h_chi, cur, top); //exploring the heavy edge first.
	for (auto &chi : g[cur]) {
		if (chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi); //exploring the light edges.
	}
}
 
void binaryLift(){
	fore(i,1,loga){
		fore(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
	}
}
 
ll lca(ll x, ll y){
	if (x == y) return x;
	if (dep[x] > dep[y]) swap(x,y); //'y' is deeper.
	ll dif = dep[y] - dep[x];
	rofe(i,loga,0){
		if (p[i] <= dif){
			dif -= p[i];
			y = up[y][i];
		}
	}
	if (x == y) return x;
	rofe(i,loga,0){
		if (up[x][i] != up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}
 
ll pathQuery(ll chi, ll par) {
	ll ret = inf;
	while (chi != par) {
		if (tp[chi] == chi) { //querying for the top of the chain, no STree needed.
			ret = min(ret, query(labe[chi], labe[chi])); // or do max(ret, arr[chi]) if arr[chi] is kept updated.
			chi = up[chi][0];
		} else if (dep[tp[chi]] > dep[par]) { //queyring for the whole chain.
			ret = min(ret, query(labe[tp[chi]], labe[chi]));
			chi = up[tp[chi]][0];
		} else { //querying for a part of the chain
			ret = min(ret, query(labe[par] + 1, labe[chi]));
			break;
		}
	}
	return ret;
}

void bfs(){
	queue <ll> q;
	fore(i,1,n+1){
		if (c[i]){
			d[i]=0;
			q.push(i);
		}
		else d[i] = n+1;
	}
	
	while(sz(q)){
		ll u = q.front();
		q.pop();
		
		for(auto &v : g[u]){
			if (d[v] > d[u] + 1){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
    fast;
    cin >> n >> q;
    init();
    fore(i,1,n+1) cin >> c[i];
    
    fore(i,1,n){
    	ll x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    
    bfs();
    
    dfs_sz(1,1);
    dfs_hld(1,1,1);
    build();
	binaryLift();
	
	while(q--){
		ll x,y;
		cin >> x >> y;
		ll lcan = lca(x,y);
		ll ans = (dep[x]-dep[lcan] + dep[y]-dep[lcan]);
		ans += min({pathQuery(x,lcan),pathQuery(y,lcan),d[lcan]})*2;
		
		cout << ans << nl;
	}
	
	return 0;
}