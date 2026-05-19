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
#define pii pair<int,int>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 3020;

int n;
pii pv[maxn][maxn]; // previous.
char a[maxn][maxn];
bool vis[maxn][maxn];

bool good(int x, int y){
	if (1 <= x && x <= n && 1 <= y && y <= n) return true;
	return false;
}

void solve(){
	queue <pii> q;
	
	vector <pii> layer;
	layer.pb({1,1});
	vis[1][1] = true;
	int cnt = 1;
	while(sz(layer)){
		vector <pii> v;
		char best = 'Z';
		for(auto &[x,y] : layer){
			if (good(x+1,y)){
				best = min(best,a[x+1][y]);
			}
			if (good(x,y+1)){
				best = min(best,a[x][y+1]);
			}
		}
		
		//cout << "Layer: " << cnt << ": " << best << nl;
		
		for(auto &[x,y] : layer){
			if (good(x+1,y) && a[x+1][y] == best && !vis[x+1][y]){
				v.pb({x+1,y});
				vis[x+1][y] = true;
				pv[x+1][y] = {x,y};
			}
			if (good(x,y+1) && a[x][y+1] == best && !vis[x][y+1]){
				v.pb({x,y+1});
				vis[x][y+1] = true;
				pv[x][y+1] = {x,y};
			}
		}
		swap(layer,v);
		cnt++;
	}
}

int main(){
    fast;
   	cin >> n;
   	fore(i,1,n+1){
   		fore(j,1,n+1){
   			cin >> a[i][j];
   		}
   	}
	
	solve();
	
	string s = "";
	int x = n;
	int y = n;
	while(min(x,y) > 0){
		s += a[x][y];
		int nx = pv[x][y].fst;
		int ny = pv[x][y].snd;
		x = nx, y = ny;
	}
	
	reverse(ALL(s));
	
	cout << s << nl;
	return 0;
}