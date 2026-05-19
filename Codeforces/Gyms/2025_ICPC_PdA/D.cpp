// Problem: D. Dangerous City
// Contest: Codeforces - The 2025 ICPC Latin America Championship
// URL: https://codeforces.com/gym/105789/problem/D
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
 
using namespace std;

const ll maxn = 3e5+100;
ll n,m,res[maxn],d[maxn];
vi g[maxn];

struct Edge{
	ll u,v,w;
};

vector <Edge> edges;

struct UF{
	ll pad,ran,tam;
};

UF uf[maxn];

void init(){
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].ran = 0;
		uf[i].tam = 1;
	}
}

bool cmp(Edge e1, Edge e2){
	return e1.w < e2.w;
}

ll bus(ll u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

void join(int u, int v, ll w){
	u = bus(u);
	v = bus(v);
	if (u == v) return;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	res[u] += (w * uf[v].tam);
	res[v] += (w * uf[u].tam) - res[u];

	g[u].pb(v);

	uf[v].pad = u;
	uf[u].tam += uf[v].tam;
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	return;
}

void dfs(ll node){
	for(auto &signode : g[node]){
		res[signode] += res[node];
		dfs(signode);
	}
}

int main(){
    fast;
  	cin>>n>>m;
  	init();
  	fore(i,1,n+1) cin>>d[i];
  	
  	fore(i,0,m){
  		Edge e;
  		cin>>e.u>>e.v;
  		e.w = max(d[e.u],d[e.v]);
  		edges.pb(e);
  	}
  	
  	sort(ALL(edges),cmp);
  	
  	for(auto &e : edges){
		join(e.u,e.v,e.w);
  	}
  	
  	ll root = bus(uf[1].pad);
  	
  	dfs(root);
  	
  	fore(i,1,n+1) cout<<res[i] + d[i]<<" ";
  	cout<<nl;
  	return 0;
}