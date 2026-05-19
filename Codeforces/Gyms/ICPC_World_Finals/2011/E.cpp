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

using namespace std;

const int maxn = 5015;
const int inf = 1e9+7;

int sd[maxn][maxn];
int ss[maxn][maxn][2];
int a[maxn][maxn];
int n,m,offs,tope,cs,q,tc=1;

void init(){
	offs = max(n,m)*2;
	tope = offs*2 + (offs/2);
	
	// limpiar:
	fore(i,0,tope){
		fore(j,0,tope){
			sd[i][j] = 0;
			a[i][j] = 0;
			fore(x,0,2) ss[i][j][x] = 0;
		}
	}
}

bool good(int row, int col){
	if (0 <= row && row < tope && 0 <= col && col < tope) return true;
	return false;
}

void fill_diagonal(int row, int col){
	while(good(row,col)){
		sd[row][col] = a[row][col] + (good(row-1,col-1) ? sd[row-1][col-1] : 0);
		row++;
		col++;
	}
}


void fill_stairs(int row, int col, int ne){
	while(good(row,col)){
		int add = 0;
		if (ne == 0 && good(row-1,col)){
			add = ss[row-1][col][1-ne];
		}
		else if (ne == 1 && good(row,col+1)){
			add = ss[row][col+1][1-ne];
		}
		ss[row][col][ne] = sd[row][col] + add;
		
		if (ne == 0) col--;
		else row++;
		
		ne = 1-ne;
	}
}

void compute_sums(){
	//compute diagonal 1:
	fore(i,0,tope){
		fill_diagonal(0,i); // start from the top row, in column i.
		if (i > 0) fill_diagonal(i,0); // start from the row i, in the leftmost column.
	}
	
	// compute staircase sums starting going left and down:
	fore(i,0,tope){
		fill_stairs(0,i,0);
		fill_stairs(0,i,1);
		if (i > 0){
			fill_stairs(i,tope-1,0);
			fill_stairs(i,tope-1,1);
		}
	}
}

int get_amou(int x, int y, int d){
	int add = (ss[x+d][y][0] - ss[x-1][y+d][1]);
	int rem = (ss[x-1][y-d-1][1] - ss[x-d-1][y][0]);
	
	return add - rem;
}

void solve(){
	init();
	fore(i,0,cs){
		int x,y;
		cin >> x >> y;
		a[offs+x][offs+y] = 1;
	}
	
	compute_sums();
	
	cout << "Case " << tc++ << ":"<<nl;
	
	while(q--){
		int k;
		int mx = 0;
		int bi = inf;
		int bj = inf;
		cin >> k;
		k = min(k,n+m-2);
		for(int i = offs+1; i<=offs+n; i++){
			for(int j = offs+1; j <= offs+m; j++){
				int ret = get_amou(i,j,k);
				if (mx < ret){
					mx = ret;
					bi = i;
					bj = j;
				}
				else if (mx == ret){
					if (j < bj){
						bi = i;
						bj = j;
					}
					else if (j == bj && i < bi){
						bi = i;
						bj = j;
					}
				}
			}
		}
		cout << mx << " (" << bi - offs << "," << bj - offs << ")" << nl;
	}
}

int main(){
    fast;
    for(;;){
		cin >> n >> m >> cs >> q;
		if (n == 0) break;
		solve();
    }
    return 0;
}