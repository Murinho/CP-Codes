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

const ll maxn = 2e5+10;
ll n,x,y,m,timer=0;
ll low[maxn],disc[maxn],inStack[maxn];
vi g[maxn];
ll color[maxn],ccnt=0;
stack <int> stk; // to find SCCs (directed graphs)

void dfs(int node, int antnode = -1){
	low[node] = disc[node] = ++timer;
	stk.push(node);
	inStack[node] = 1;
	for (auto &signode : g[node]){
		if(disc[signode] == 0){
			dfs(signode, node);
			low[node] = min(low[node], low[signode]);
		}
		// To find SCC's (directed graphs):
		else if (inStack[signode] == 1){
			low[node] = min(low[node], disc[signode]);
		} 
	}
	if (low[node] == disc[node]){ // To find SCC's (directed graphs)
		ccnt++;
		while (true){
			ll topic = stk.top();
			stk.pop();
			inStack[topic] = 0;
			color[topic]=ccnt;
			if (node == topic) break;
		}
	}
}

int main(){
    fast;
	cin >> n >> m;
	fore(i,0,m){
		ll x,y;
		cin >> x >> y;
		g[x].pb(y);
	}
	
	fore(i,1,n+1){
		if (disc[i]==0) dfs(i);
	}
	
	cout << ccnt << nl;
	fore(i,1,n+1) cout << color[i] << " ";
	cout << nl;
	
	return 0;
} 