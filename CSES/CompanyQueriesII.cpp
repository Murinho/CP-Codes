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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+100;
const ll loga = 24;
ll up[maxn][loga],n,q,d[maxn];
vi adj[maxn];

ll lca(ll x, ll y){
	if (d[x] < d[y]) swap(x,y);
	
	int dif = d[x]-d[y];
	for(int i = loga-1; i>=0; i--){
		ll pot = (1ll<<i);
		if (pot <= dif){
			x = up[x][i];
			dif -= pot;
		}
	}
	if (x == y) return x;
	for(int i = loga-1; i>=0; i--){
		if (up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
	}
	return up[x][0];
}

void dfs(int node, int dep){
	d[node] = dep;
	for(auto au : adj[node]){
		dfs(au,dep+1);
	}
}

void binLift(){
	fore(i,1,loga){
		fore(j,1,n+1){
			up[j][i] = up[up[j][i-1]][i-1];
		}
	}
}

int main(){
    fast;
	cin>>n>>q;
	fore(i,2,n+1){
		ll x;
		cin>>x;
		up[i][0] = x;
		adj[x].pb(i);
	}
	dfs(1,1);
	binLift();
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<nl;
	}
	return 0;
}