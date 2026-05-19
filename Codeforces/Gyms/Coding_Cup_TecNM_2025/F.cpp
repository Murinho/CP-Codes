// Problem: F. Flujo mínimo
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const ll maxn = 510;
const ll inf = 1e9;

char a[maxn][maxn];
ll d[maxn][maxn];
ll n,m;
ll mov[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void init(){
	fore(i,0,maxn) fore(j,0,maxn) d[i][j] = inf;
}

bool good(ll x, ll y){
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}

void daikra(){
	// priority_queue < pii, vector <pii>, greater <pii> > pq;
	priority_queue <array<ll,3>, vector < array<ll,3> >, greater < array<ll,3> > > pq;
	d[0][0] = 0;
	pq.push({0ll,0ll,0ll});
	while(sz(pq)){
		auto [w,row,col] = pq.top();
		
		pq.pop();
		
		if (d[row][col] != w) continue;
		
		// cout << row << " " << col << " " << w << nl;
		
		fore(i,0,4){
			ll sr = row + mov[i][0];
			ll sc = col + mov[i][1];
			if (good(sr,sc)){
				ll cost = 1;
				if (i == 0 && a[row][col] == '>') cost = 0;
				else if (i == 1 && a[row][col] == '<') cost = 0;
				else if (i == 2 && a[row][col] == 'v') cost = 0;
				else if (i == 3 && a[row][col] == '^') cost = 0;
				
				if (w + cost < d[sr][sc]){
					d[sr][sc] = w + cost;
					pq.push({w + cost, sr, sc});
				}
			}
		}
	}
}

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,0,n){
    	fore(j,0,m){
    		cin >> a[i][j];
    	}
    }
    
    daikra();
//     
    // fore(i,0,n){
    	// fore(j,0,m){
    		// cout << d[i][j] << " ";
    	// }
    	// cout << nl;
    // }
    
    cout << d[n-1][m-1] << nl;
    
    return 0;
}