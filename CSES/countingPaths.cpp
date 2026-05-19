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

ll n,m,d[maxn],up[maxn][loga],sum[maxn],sub[maxn],indeg[maxn];
vi adj[maxn]; 

void dfs(int anode, int node, int dep){
	d[node] = dep;
	up[node][0] = anode;
	for(auto au : adj[node]){
		if (au != anode){
			dfs(node,au,dep+1);
			indeg[node]++;
		}
	}
}

void bl(){
	fore(i,1,loga){
		fore(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
	}
}	

ll lca(ll x, ll y){
    if (x == y) return x;
    if (d[x] > d[y]) swap(x,y); //'y' is deeper.
    ll dif = d[y] - d[x];
    for (ll i = loga-1; i>=0; i--){
        ll pot = (1ll<<i);
        if (pot <= dif){
            dif -= pot;
            y = up[y][i];
        }
    }
    if (x == y) return x;
    for (ll i = loga-1; i>=0; i--){
        if (up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}

void bfs(){
	queue <int> q;
	fore(i,2,n+1) if (!indeg[i]) q.push(i);

	while(!q.empty()){
		int node = q.front();
		q.pop();
		//cout<<"v: "<<node<<" --> "<<sum[node]<<nl;
		int dad = up[node][0];
		sum[dad] += (sum[node]-sub[node]);
		indeg[dad]--;
		if (!indeg[dad]) q.push(dad);
	}
}

int main(){
    fast;
	cin>>n>>m;
	fore(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		//cout<<"t: "<<x<<" "<<y<<nl;
	}
	dfs(0,1,1);
	bl();
	while(m--){
		ll x,y,lcan;
		cin>>x>>y;
		if (x == y){
			sum[x]++;
			sub[x]++;
		}
		else{
			lcan = lca(x,y);
			//cout<<x<<" "<<y<<" "<<lcan<<nl;
			if (x == lcan){
				sum[y]++;
				sub[lcan]++;
			}
			else if (y == lcan){
				sum[x]++;
				sub[lcan]++;
			}
			else{ //up-down.
				sum[x]++;
				sum[y]++;
				sum[lcan]--;
				sub[lcan]++;
			}
		}
	}
	bfs();
	fore(i,1,n+1) cout<<sum[i]<<" ";
	cout<<nl;
	return 0;
}