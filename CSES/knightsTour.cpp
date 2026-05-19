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

const ll n = 8;
const ll m = 8;
const ll maxn = n*m;

int mov[8][2] = {{2,1},{-2,1},{-2,-1},{2,-1},{1,2},{1,-2},{-1,-2},{-1,2}};
vi g[maxn];
int a[8][8];


bool good(ll x, ll y){
	if (min(x,y) < 0 || x >= n || y >= m) return false;
	return true;
}

int deg(int x, int y){
	int ret = 0;
	fore(i,0,8){
		int sx = x + mov[i][0];
		int sy = y + mov[i][1];
		if (good(sx,sy)){
			ret++;
		}
	}
	return ret;
}

bool dfs(int x, int y, int move){
	a[x][y] = move;
	if (move == 64) return true;
	
	vector <array<ll,3> > v;
	
	fore(i,0,8){
		int sx = x + mov[i][0];
		int sy = y + mov[i][1];
		
		if (good(sx,sy) && a[sx][sy] == 0){
			int d = deg(sx,sy);
			v.pb({d,sx,sy});
		}
	}
	
	sort(ALL(v));
	
	for(auto &[d,x,y] : v){
		if (dfs(x,y,move+1)) return true;
	}
	a[x][y] = 0;
	return false;
}

int main(){
    fast;
    ll stfil,stcol;
    cin >> stfil >> stcol;
    stfil--, stcol--;
    
    swap(stfil,stcol);
    
    dfs(stfil,stcol,1);
    
    fore(i,0,8){
    		fore(j,0,8) cout << a[i][j] << " ";
    		cout << nl;
    }
    return 0;
}