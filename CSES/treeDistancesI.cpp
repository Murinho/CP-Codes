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
ll n,b[maxn][2],res[maxn];
vi adj[maxn];

//Encontrar los mejores 2 hijos de cada nodo.
void dfs(int anode, int node){
	for(auto au : adj[node]){
		if (anode != au){
			dfs(node,au);
			if (b[au][0]+1 >= b[node][0]){ 
				b[node][1] = b[node][0];
				b[node][0] = b[au][0] + 1;
			}
			else if (b[au][0]+1 >= b[node][1]) b[node][1] = b[au][0] + 1;
		}
	}
}

//DP con rerooteo.
void rooting(int anode, int node, ll bestup){
	res[node] = max(b[node][0],bestup);
	for(auto au : adj[node]){
		if (anode != au){
			ll nbestup = bestup;
			//antes de explorar calcular el bestup.
			if (b[au][0] + 1 == b[node][0]){ //esta es la mejor rama.
				nbestup = max(nbestup,b[node][1]);
			}
			else nbestup = max(nbestup,b[node][0]);
			rooting(node,au,nbestup + 1);
		}
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
	dfs(1,1);
	rooting(1,1,0);
	fore(i,1,n+1) cout<<res[i]<<" ";
	cout<<nl;
	return 0;
}