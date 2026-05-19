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

const ll maxn = 1e6+100;


ll n,m,foundat;
vi low,disc,tams,vis,ng;
vector <bool> isart;
vvi g;

void init(){
	low.clear(), low.resize(n+1,0);
	disc.clear(), disc.resize(n+1,0);
	isart.clear(), isart.resize(n+1,false);
	g.clear(), g.resize(n+1);
	vis.clear(), vis.resize(n+1,false);
	ng.clear(), ng.resize(n+1,0);
	tams.clear(), tams.resize(n+1,0);
	foundat = 1;
} 

void tarjan(int node, int antnode){
	low[node] = disc[node] = foundat++;
	
	int children = 0;
	for(auto &signode : g[node]){
		if (!disc[signode]){
			children++;
			tarjan(signode,node);
			low[node] = min(low[node], low[signode]);
			if (antnode == -1 && children > 1) isart[node] = true;
			if (antnode != -1 && low[signode] >= disc[node]) isart[node] = true;
			
		}
		
		else if (antnode != signode){
			low[node] = min(low[node], disc[signode]);
		}
	}
}

void dfs(ll node, ll &ccid, set <ll> &touch){
	vis[node] = ccid;
	tams[ccid]++;

	for(auto &signode : g[node]){
		if (isart[signode]) touch.insert(signode);
		else if (!vis[signode]){
			dfs(signode,ccid,touch);
		}
	}
}

void solve(int &tc){
	n = 0;
	vector <pii> e(m);
	fore(i,0,m){
		cin >> e[i].fst >> e[i].snd;
		n = max({n,e[i].fst,e[i].snd});
	}
	
	init();
	
	for(auto &[x,y] : e){
		g[x].pb(y);
		g[y].pb(x);
	}
	
	fore(i,1,n+1) if (!disc[i]) tarjan(i, -1);

	ll artcnt = 0;
	fore(i,1,n+1) if (isart[i]){
		//cout << "art: " << i << nl;
		artcnt++;
	}
	
	if (artcnt == 0){
		cout << "Case " << tc << ": " << 2 << " " << n*(n-1)/2ll << nl;
		return;
	}
	
	ll ccid = 0;
	ll amou = 0, ways = 1;
	fore(i,1,n+1){
		if (!vis[i] && !isart[i]){
			ccid++;
			set <ll> touch;
			dfs(i,ccid,touch);
			
			if (sz(touch) <= 1){
				amou++;
				ways *= tams[ccid];
			}
		}
	}
	
	cout << "Case " << tc << ": " << amou << " " << ways << nl;
	return;
}

int main(){
    fast;
    for(int tc = 1;;tc++){
    	cin >> m;
    	if (m == 0) break;
    	solve(tc);
    }
    
    return 0;
}