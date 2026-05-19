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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e5+50;
const ll INF = 1e18;

vector <ll> adj[maxn];
ll color[maxn],par[maxn];
bool flag;
ll n,m;

void dfs_cycle(int u, int p){
    if (color[u] == 2) return;
    if (color[u] == 1) {
    	if (!flag){
    		vector<ll> v;
	        int cur = p;
	        v.push_back(cur);
	 
	        while (cur != u){
	            cur = par[cur];
	            v.push_back(cur);
	        }
	        reverse(ALL(v));
	        cout<<sz(v) + 1<<nl;
	       	for(auto au : v) cout<<au<<" ";
	       	cout<<v.front()<<nl;
	       	flag = true;
    	}
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : adj[u]) {
        dfs_cycle(v, u);
    }
    color[u] = 2;
}

int main(){
    fast;
	cin>>n>>m;
	while(m--){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
	}
	fore(i,1,n+1) if (!color[i]) dfs_cycle(i,0);
	if (!flag) cout<<"IMPOSSIBLE"<<nl;
	return 0;
}