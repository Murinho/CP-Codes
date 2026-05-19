#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 2e5+100;
const ll loga = 24;


ll n,q,d[maxn],up[maxn][loga];
vi adj[maxn];

void dfs(int anode, int node, int dep){
	d[node] = dep;
	up[node][0] = anode;
	for (auto au : adj[node]){
		if (anode != au){
			dfs(node,au,dep+1);
		}
	}
}

void binLift(){
	for(int i = 1; i<loga; i++){
		for(int j = 1; j<=n; j++){
			up[j][i] = up[up[j][i-1]][i-1];
		}
	}
}

ll lca(ll x, ll y){
	if (d[x] < d[y]) swap(x,y);
	
	int dif = d[x]-d[y];
	for(int i = loga-1; i>=0; i--){
		if ((1ll<<i) <= dif){
			dif -= (1ll<<i);
			x = up[x][i];
		}
	}
	if (x == y) return x;
	for(int i = loga-1; i>=0; i--){
		if (up[x][i] != up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int main(){
    fast;
	cin>>n>>q;
	fore(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,1,1);
	binLift();
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll lcan = lca(x,y);
		cout<<(d[x]-d[lcan]) + (d[y]-d[lcan])<<nl;
	}
	return 0;
}