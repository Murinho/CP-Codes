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
ll n,m,k;
vector < pair <ll,ll> > adj[maxn];
ll d[maxn][11],cnt[maxn];

void init(){
	fore(i,0,n+1) fore(j,0,k+1) d[i][j] = INF;
}


void daikra(){
	priority_queue < pii, vector < pii >, greater < pii > > pq;
	pq.push({0,1}); //{weight, node};
	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();
		ll we = p.fst;
		ll node = p.snd;
		if (cnt[node] >= k) continue;
		d[node][cnt[node]] = we;
		for(auto au : adj[node]){
			ll sgnode = au.fst;
			ll sigw = au.snd;
			if (d[sgnode][k-1] > d[node][cnt[node]]){
				pq.push({d[node][cnt[node]] + sigw,sgnode});
			}
		}
		cnt[node]++;
	}
}

int main(){
    fast;
	cin>>n>>m>>k;
	init();
	while(m--){
		ll x,y,z;
		cin>>x>>y>>z;
		adj[x].pb({y,z});
	}
	daikra();
	fore(i,0,k) cout<<d[n][i]<<" ";
	cout<<nl;
	return 0;
}