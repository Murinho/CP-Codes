#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace std;

const ll maxn = 1e5+100;
const ll inf = 1e9+7;

ll n,d[maxn],m;
bool vis[maxn];
vector <pii> g[maxn],rg[maxn];
vi gg[maxn];

void init(){
	memset(d, inf, sizeof(d));
}

void daikra(){
	priority_queue < pii, vector <pii>, greater <pii> > pq;
	d[1] = 0;
	pq.push({d[1],1});
	while(sz(pq)){
		auto [dist,node] = pq.top();
		pq.pop();
		
		if (d[node] != dist) continue;
		
		for(auto &[signode, nd] : g[node]){
			if (d[signode] > d[node] + nd){
				d[signode] = d[node] + nd;
				pq.push({d[signode],signode});
			}
		}
	}
}

void bfs(){
	queue <ll> q;
	q.push(n);
	vis[n] = true;
	while(sz(q)){
		ll node = q.front();
		q.pop();
		for(auto &[signode, nd] : rg[node]){
			if (d[node] == d[signode] + nd){
				if (!vis[signode]){
					vis[signode] = true;
					q.push(signode);
				}
				gg[node].pb(signode);
				gg[signode].pb(node);
			}
		}
	}
}


ll foundat = 1;
ll low[maxn],disc[maxn],isArt[maxn],inStack[maxn];
 
void tarjan(int node, int antnode = -1){ //first call antnode should be = -1.
	static stack <int> stk;
	low[node] = disc[node] = foundat;
	stk.push(node);
	inStack[node] = 1;
	foundat++;
	int children = 0;
	for (auto signode : gg[node]){
		if(disc[signode] == 0){
			children++;
			tarjan(signode, node);
			low[node] = min(low[node], low[signode]);
			if (antnode == -1 && children > 1) isArt[node] = 1;
			if (antnode != -1 && low[signode] >= disc[node]) isArt[node] = 1;
		}
		//When wanting to find bridges or articulation points: 
		else if (antnode != signode){
			low[node] = min(low[node], disc[signode]);
		}
	}
}

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,0,m){
    	ll x,y,z;
    	cin >> x >> y >> z;
    	g[x].pb({y,z});
    	rg[y].pb({x,z});
    }
    
    daikra();
    
    bfs();
    
    tarjan(1);
    
    vi v = {1,n};
    fore(i,2,n) if (isArt[i]) v.pb(i);
    
    sort(ALL(v));
    
    cout << sz(v) << nl;
    for(auto &elm : v) cout << elm << " ";
    cout << nl;
    return 0;
}