// Problem: K. Maraton de Peliculas
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const ll maxn = 3e3+100;

struct Movie{
	ll y;
	string dir;
	ll p;
};

ll n,dp[maxn],ans=0;
ll in[maxn];
Movie mov[maxn];
vi g[maxn];

void topobfs(){
	queue <ll> q;
	fore(i,0,n) if (in[i] == 0){
		dp[i] = 1;
		q.push(i);
	}
	
	while(sz(q)){
		ll node = q.front();
		
		q.pop();
		
		for(auto &signode : g[node]){
			in[signode]--;
			dp[signode] = max(dp[signode], dp[node] + 1);
			if (in[signode] == 0){
				q.push(signode);
			}
		}
	}
}

int main(){
    fast;
    cin >> n;
    fore(i,0,n){
    	cin >> mov[i].y >> mov[i].dir >> mov[i].p;
    }
    
    fore(i,0,n){
    	fore(j,0,n){
    		if (i == j) continue;
    		
    		if (mov[i].y <= mov[j].y && mov[i].dir != mov[j].dir && mov[i].p < mov[j].p){
    			g[i].pb(j);
    			in[j]++;
    		}
    	}
    }
    
    topobfs();
    
    fore(i,0,n) ans = max(ans,dp[i]);
    
     cout << ans << nl;
     
     return 0;
}