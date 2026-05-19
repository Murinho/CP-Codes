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
ll n,vis[maxn],ans=0;
vi adj[maxn];

void dfs(int anode, int node){
	for(auto signode : adj[node]){
		if (signode != anode){
			dfs(node,signode);
			if (!vis[node] && !vis[signode]) ans++, vis[node] = vis[signode] = 1;
		}
	}
}

int main(){
    fast;
	cin>>n;
	if (n == 1){
		cout<<0<<nl;
		return 0;
	}
	fore(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,1);
	cout<<ans<<nl;
	return 0;
}