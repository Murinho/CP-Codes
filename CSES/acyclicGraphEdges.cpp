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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 1e5+10;

vi g[maxn];
map <pii,ll> mp;
bool vis[maxn];
set <pii> st;
ll n,m;

void bfs(int stnode){
	vis[stnode] = true;
	queue <ll> q;
	q.push(stnode);
	
	while(sz(q)){
		ll node = q.front();
		q.pop();
		
		for(auto &signode : g[node]){
			if (!st.count({node,signode})){
				st.insert({node,signode});
				st.insert({signode,node});
				ll freq = mp[{node,signode}];
				fore(j,0,freq){
					cout << node << " " << signode << nl;
				}
			}
			if (!vis[signode]){
				vis[signode] = true;
				q.push(signode);
			}
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
    	g[y].pb(x);
    	mp[{x,y}]++;
    	mp[{y,x}]++;
    }
    
    fore(i,1,n+1){
    	if (!vis[i]) bfs(i);
    }
    
    return 0;
}