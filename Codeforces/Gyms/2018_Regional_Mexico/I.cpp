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

const ll maxn = 2e5+100;
const ll loga = 18;
const ll neut = 0;

struct UF{
	ll pad,ran;
};

struct Edge{
	ll x,y,c;
};

ll n,m,q;
UF uf[maxn];
vector <Edge> edges;
map <pii,ll> mp;
vi g[maxn];
ll up[maxn][loga],dep[maxn];
ll subt[maxn],labe[maxn],tp[maxn],revlabe[maxn],st[maxn*4],p[loga];
ll mst_cost, label_cont;

// UNION FIND & KRUSKAL

int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

bool join(int u, int v){
	u = bus(u);
	v = bus(v);
	
	if (u == v) return false;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	uf[v].pad = u;
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	return true;
}

bool cmp(Edge &e1, Edge &e2){
	return e1.c < e2.c;
}

void kruskal(){
	sort(ALL(edges),cmp);
	for(auto &[x,y,c] : edges){
		if (join(x,y)){
			mst_cost += c;
			g[x].pb(y);
			g[y].pb(x);
		}
	}
}


// HEAVY LIGHT DECOMPOSITION

void upd(int pos, int val, int node = 1, int ini = 1, int fin = n){
	if (ini == fin){
		st[node] = val;
		return;
	}
	int mid =(ini+fin)/2;
	if (pos <= mid) upd(pos,val,2*node,ini,mid);
	else upd(pos,val,2*node+1,mid+1,fin);
	st[node]=max(st[2*node],st[2*node+1]); // operation
}
int query(int l, int r, int node = 1, int ini = 1, int fin = n){
	if(fin < l || r < ini) return neut; // operation neutral
	if(l <= ini && fin <= r) return st[node];
	int mid =(ini+fin)/2;
	return max(query(l,r,2*node,ini,mid),query(l,r,2*node+1,mid+1,fin)); // operation
}

int dfs_sz(int cur, int par) {
	subt[cur] = 1;
	for (int chi : g[cur]) {
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
	// if assigning value here do: arr[labe[cur]] = val
	upd(labe[cur], mp[{par,cur}]); //updating the STree using the labeling.
	int h_chi = -1, h_sz = -1;
	for (int chi : g[cur]) {
		if (chi == par) continue;
		if (subt[chi] > h_sz) {
			h_sz = subt[chi];
			h_chi = chi;
		}
	}
	if (h_chi == -1) return;
	dfs_hld(h_chi, cur, top); //exploring the heavy edge first.
	for (int chi : g[cur]) {
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
 
int pathQuery(int chi, int par) {
	int ret = 0;
	while (chi != par) {
		if (tp[chi] == chi) { //querying for the top of the chain, no STree needed.
			ret = max(ret, query(labe[chi], labe[chi])); // or do max(ret, arr[chi]) if arr[chi] is kept updated.
			chi = up[chi][0];
		} else if (dep[tp[chi]] > dep[par]) { //queyring for the whole chain.
			ret = max(ret, query(labe[tp[chi]], labe[chi]));
			chi = up[tp[chi]][0];
		} else { //querying for a part of the chain
			ret = max(ret, query(labe[par] + 1, labe[chi]));
			break;
		}
	}
	return ret;
}

void init(){
	// INIT UNION FIND
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].ran = 0;
	}
	mst_cost = 0;
	
	// INIT HLD
	label_cont = 1;
	p[0] = 1;
	fore(i,1,loga) p[i] = (p[i-1] * 2ll);
}

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,0,m){
    	Edge edge;
    	cin >> edge.x >> edge.y >> edge.c;
    	edges.pb(edge);
    	mp[{edge.x,edge.y}] = edge.c;
    	mp[{edge.y,edge.x}] = edge.c;
    }
    
    kruskal(); // construir el MST
    
    //cout << "MST cost: " << mst_cost << nl;
    
   	dfs_sz(1,1);
   	dfs_hld(1,1,1);
   	binaryLift();

    cin >> q;
    while(q--){
    	ll x,y,cost;
    	cin >> x >> y;
    	cost = mp[{x,y}];
    	
    	ll lcan = lca(x,y);
	    ll qans = max(pathQuery(x,lcan),pathQuery(y,lcan));
	    cout << mst_cost - qans + cost << nl;  	
    }
    
    return 0;
}