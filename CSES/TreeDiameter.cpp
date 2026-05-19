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
ll n,d[maxn][2];
vi adj[maxn];

void dfs(int anode, int node, int de, int x){
	d[node][x] = de;
	for(auto au : adj[node]){
		if (anode != au) dfs(node,au,de+1,x);
	}
}

int main(){
    fast;
	cin>>n;
	fore(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,1,0,0);
	ll pos = 1;
	ll best = 0;
	fore(i,1,n+1){
		if (d[i][0] >= best){
			best = d[i][0];
			pos = i;
		}
	}
	dfs(pos,pos,0,1);
	best = 0;
	fore(i,1,n+1) best = max(best,d[i][1]);
	cout<<best<<nl;
	return 0;
}