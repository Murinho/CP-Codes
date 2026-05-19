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

ll n,m,k;
bool has[maxn];
pii d[maxn][2]; // {distance, source}
vi g[maxn];

void init(){
	fore(i,0,n+1){
		fore(j,0,2) d[i][j].fst = d[i][j].snd = inf;
	}
}

void bfs(){
	queue <array<ll,3>> q; // {node, distance, source}
	fore(i,1,n+1){
		if (has[i]){
			d[i][0].fst = 0;
			d[i][0].snd = i;
			q.push({i,d[i][0].fst, d[i][0].snd});
		}
	}
	
	while(sz(q)){
		auto [node,dist,src] = q.front();
		
		q.pop();
		
		for(auto &signode : g[node]){
			if (d[signode][0].fst == inf){
				d[signode][0].fst = dist + 1;
				d[signode][0].snd = src;
				q.push({signode,d[signode][0].fst, d[signode][0].snd});
			}
			else if (d[signode][1].fst == inf && d[signode][0].snd != src){
				d[signode][1].fst = dist + 1;
				d[signode][1].snd = src;
				q.push({signode,d[signode][1].fst, d[signode][1].snd});
			}
		}
	}
}

int main(){
    fast;
   	cin >> n >> m >> k;
   	init();
   	fore(i,1,k+1){
   		ll x;
   		cin >> x;
   		has[x] = true;
   	}
   	
   	fore(i,1,m+1){
   		ll x,y;
   		cin >> x >> y;
   		g[x].pb(y);
   		g[y].pb(x);
   	}
   	
   	bfs();
   	
   	fore(i,1,n+1){
   		if (has[i]){
   			if (d[i][1].fst == inf) cout << -1 << " ";
   			else cout << d[i][1].fst << " ";
   		} 
   		else{
   			if (d[i][0].fst == inf) cout << -1 << " ";
   			else cout << d[i][0].fst << " ";
   		}
   	}
   	cout << nl;
   	return 0;
}