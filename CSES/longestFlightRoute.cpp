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

ll n,m,indeg[maxn],d[maxn],p[maxn],g[maxn];
vi adj[maxn];



int main(){
    fast;
	cin>>n>>m;
	while(m--){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		indeg[y]++;
	}
	if (!indeg[n]){
		cout<<"IMPOSSIBLE"<<nl;
		return 0;
	}
	
	queue <int> q;
	g[1] = 1;
	fore(i,1,n+1){
		if (!indeg[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto au : adj[node]){
			indeg[au]--;
			if (g[node]){
				g[au] = 1;
				if (d[node] + 1 > d[au]){
					d[au] = d[node] + 1;
					p[au] = node;
				}
			}
			if (indeg[au] == 0){
				q.push(au);
			}
		}
	}
	if (!g[n]) cout<<"IMPOSSIBLE"<<nl;
	else{
		vi path;
		int pos = n;
		while(pos != 1){
			path.pb(pos);
			pos = p[pos];
		}
		path.pb(1);
		reverse(ALL(path));
		cout<<sz(path)<<nl;
		for(auto au : path) cout<<au<<" ";
		cout<<nl;
	}
	return 0;
}