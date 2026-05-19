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

const ll maxn = 1e5+10;
ll tc,n,m,par[maxn],color[maxn],indeg[maxn];
vi adj[maxn],ordd;
bool flag = true;

void dfs_cycle(int u, int p)
{
    if (color[u] == 2) {
        return;
    }
    if (color[u] == 1) {
        flag = false;
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : adj[u]) {
        dfs_cycle(v, u);
    }
    color[u] = 2;
    return;
}

void bfs(){
	queue <int> q;
	fore(i,1,n+1){
		if (!indeg[i]) q.push(i), ordd.pb(i);
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto au : adj[node]){
			indeg[au]--;
			if (!indeg[au]){
				q.push(au);
				ordd.pb(au);
			}
		}
	}
	return;
}



int main(){
    fast;
	cin>>n>>m;
	fore(i,0,m){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		indeg[y]++;
	}
	fore(i,1,n+1) if (!color[i] && !indeg[i]) dfs_cycle(i,0);
	fore(i,1,n+1) if (!color[i]){
		flag = false;
		break;	
	}
	if (!flag) cout<<"IMPOSSIBLE"<<nl;
	else{
		bfs();
		for(auto au : ordd) cout<<au<<" ";
		cout<<nl;
	}
	return 0;
}