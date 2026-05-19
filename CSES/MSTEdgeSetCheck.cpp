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

const ll maxn = 2e5+100;
const ll loga = 17;

struct Edge{
	ll u,v,w,id;
	
	bool operator<(const Edge &other) const {
		return (*this).w < other.w;
	}
};

struct UF{
	ll pad,ran;
};

UF uf[maxn];
ll n,m,q;
ll dep[maxn];
ll up[maxn][loga],vp[maxn][loga];
vector <pii> g[maxn];
vector <Edge> e;
bool res[maxn];
ll pw[loga];

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

void init(){
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].ran = 0; 
	}
	
	pw[0] = 1;
	fore(i,1,loga) pw[i] = (pw[i-1] * 2);
}

void dfs(int anode, int node, ll cost){
	up[node][0] = anode;
	vp[node][0] = cost;
	dep[node] = dep[anode] + 1;
	
	for(auto &[signode, sigcost] : g[node]){
		if (anode == signode) continue;
		
		dfs(node,signode,sigcost);
	}
}

void binlift(){
	fore(i,1,loga){
		fore(j,1,n+1){
			up[j][i] = up[up[j][i-1]][i-1];
			vp[j][i] = max(vp[j][i-1],vp[up[j][i-1]][i-1]);
		}
	}
}

ll wlca(ll u, ll v){
	ll ret = 0;
	if (dep[u] > dep[v]) swap(u,v);
	
	ll dif = dep[v] - dep[u];
	
	rofe(i,loga,0){
		if (pw[i] <= dif){
			dif -= pw[i];
			ret = max(ret,vp[v][i]);
			v = up[v][i];
		}
	}
	
	if (u == v) return ret;
	
	rofe(i,loga,0){
		if (up[u][i] != up[v][i]){
			ret = max(ret,vp[u][i]);
			ret = max(ret,vp[v][i]);
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	ret = max(ret,vp[u][0]);
	ret = max(ret,vp[v][0]);
	
	return ret;
}

int main(){
    fast;
  	cin >> n >> m >> q;
  	init();
  	fore(i,0,m){
  		Edge ed;
  		cin >> ed.u >> ed.v >> ed.w;
  		ed.id = i;
  		e.pb(ed);
  	}
  	
  	sort(ALL(e));
  	
  	int ecnt = 0;
  	for(int i = 0; i<m && ecnt<n-1; i++){
  		if (join(e[i].u,e[i].v)){
  			ecnt++;
  			g[e[i].u].pb({e[i].v,e[i].w});
  			g[e[i].v].pb({e[i].u,e[i].w});
  		}
  	}
  	
  	dfs(0,1,0);
  	
  	binlift();
  	
  	for(auto &ed : e){
  		ll mx = wlca(ed.u,ed.v);
  		
  		if (mx >= ed.w) res[ed.id] = true;
  	}
  	
  	fore(i,0,q){
  		ll k;
  		cin >> k;
  		bool flag = true;
  		fore(j,0,k){
  			ll x;
  			cin >> x;
  			x--;
  			flag &= res[x];
  		}
  		
  		cout << (flag ? "YES" : "NO") << nl;
  	} 
  	
  	return 0;
}