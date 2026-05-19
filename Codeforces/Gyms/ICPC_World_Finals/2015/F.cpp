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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 55;
const int maxt = 1e4+10;
const int inf = 1e9+7;

char a[maxn][maxn];
int reach[maxn][maxn][4]; //{abajo, arriba, izquierda, derecha}.
int dp[maxn][maxn][maxt]; // [fila][col][posicion_en_texto]
int n,m;
string s;

void init(){
	fore(i,1,n+1){
		fore(j,1,m+1){
			fore(k,0,sz(s)+1) dp[i][j][k] = inf;
		}
	}
}

bool good(int x, int y){
	if (1 <= x && x <= n && 1 <= y && y <= m) return true;
	return false;
} 

void bfs(){
	queue < array <int,3 > > q;
	q.push({1,1,0});
	dp[1][1][0] = 0;
	
	while(sz(q)){
		auto [fil,col,layer] = q.front();
		int dis = dp[fil][col][layer];
		q.pop();
		
		//cout<<"Currstate: "<<fil<<" "<<col<<" "<<layer<<nl;
		
		if (a[fil][col] == s[layer] && dis+1 < dp[fil][col][layer+1]){ // "ok" button.
			dp[fil][col][layer+1] = dis+1;
			if (layer+1 < sz(s)){
				q.push({fil,col,layer+1});
			}
		}
		
		fore(i,0,4){ // moverse en las 4 direcciones.
			int x = fil;
			int y = col;
			if (i <= 1) x = reach[fil][col][i];
			else y = reach[fil][col][i];
			
			if (good(x,y) && dis+1 < dp[x][y][layer]){
				dp[x][y][layer] = dis+1;
				q.push({x,y,layer});
			} 
		}
	}
}

void comp_reach(){
	// Calcular hacia abajo:
	for(int i = 1; i<=m; i++){
		int las = n;
		for(int j = n; j>=1; j--){
			if (a[j][i] != a[j+1][i]) las = j;
			reach[j][i][0] = las + 1;
		}
	}
	
	// Calcular hacia arriba:
	for(int i = 1; i<=m; i++){
		int las = 1;
		for(int j = 1; j<=n; j++){
			if (a[j][i] != a[j-1][i]) las = j;
			reach[j][i][1] = las - 1;
		}
	}
	
	// Calcular hacia la izquierda:
	for(int i = 1; i<=n; i++){
		int las = 1;
		for(int j = 1; j<=m; j++){
			if (a[i][j] != a[i][j-1]) las = j;
			reach[i][j][2] = las - 1;
		}
	}
	
	// Calcular hacia la derecha:
	for(int i = 1; i<=n; i++){
		int las = m;
		for(int j = m; j>=1; j--){
			if (a[i][j] != a[i][j+1]) las = j;
			reach[i][j][3] = las + 1;
		}
	}
}

void solve(){
	cin >> n >> m;
	fore(i,1,n+1){
		fore(j,1,m+1) cin>> a[i][j];
	}
	
	cin >> s;
	s += "*";
	
	init();
	
	comp_reach();
	
	bfs();
	
	int ans = 1e9;
	fore(i,1,n+1){
		fore(j,1,m+1){
			if (a[i][j] == '*'){
				ans = min(ans,dp[i][j][sz(s)]);
			}
		}
	}
	cout<<ans<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}