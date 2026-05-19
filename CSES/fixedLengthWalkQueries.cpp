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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 2505;
const ll inf = 1e9;

ll d[maxn][maxn*2][2];
ll n,m,q;
vi g[maxn];

void init(){
	fore(i,0,maxn){
		fore(j,0,maxn*2){
			fore(k,0,2) d[i][j][k] = inf;
		}
	}
}

void bfs(ll &stnode){
	d[stnode][stnode][0] = 0;
	queue <pii> q;
	q.push({stnode,0});
	while(sz(q)){
		auto [u,pa] = q.front();
		q.pop();
		
		for(auto &v : g[u]){
			if (d[stnode][v][1-pa] == inf){
				d[stnode][v][1-pa] = d[stnode][u][pa] + 1;
				q.push({v,1-pa});
			}
		}
	}
}

int main(){
    fast;
	cin >> n >> m >> q;
	init();
	fore(i,0,m){
		ll x,y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	fore(i,1,n+1) bfs(i);
	
	while(q--){
		ll a,b,x;
		cin >> a >> b >> x;
		if (x%2 == 0 && d[a][b][0] <= x) cout << "YES" << nl;
		else if (x%2 == 1 && d[a][b][1] <= x) cout << "YES" << nl;
		else cout << "NO" << nl;
	}
}