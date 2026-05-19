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

const ll maxn = 8;
const ll maxk = 105;

ld dp[maxn*maxn][maxn][maxn][maxk];
ld mult[maxn][maxn];
int k;
int mov[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void init(){
	fore(i,0,maxn){
		fore(j,0,maxn){
			mult[i][j] = 0.25;
		}
	}
	
	fore(i,0,maxn){
		mult[0][i] = (ld)(1.0/3.0);
		mult[maxn-1][i] = (ld)(1.0/3.0);
		mult[i][0] = (ld)(1.0/3.0);
		mult[i][maxn-1] = (ld)(1.0/3.0);
	}
	
	mult[0][0] = mult[0][maxn-1] = mult[maxn-1][maxn-1] = mult[maxn-1][0] = 0.5;
}

bool good(int x, int y){
	if (x >= 0 && x < maxn && y >= 0 && y < maxn) return true;
	return false;
}

int main(){
    fast;
   	cin >> k;
   	init();
   	
   	// do the dp
   	int curx = 0;
   	int cury = 0;
	fore(st,0,maxn*maxn){ // start
		dp[st][curx][cury][0] = 1.0;
		fore(t,0,k){ // turn
			fore(i,0,maxn){ // row
				fore(j,0,maxn){ // column
					if (dp[st][i][j][t] == 0.0) continue;
					
					fore(x,0,4){ // movement
						int si = i + mov[x][0];
						int sj = j + mov[x][1];
						if (good(si,sj)){
							dp[st][si][sj][t+1] += (dp[st][i][j][t]*mult[i][j]);
						}
					}
				}
			}
		}
		
		cury++;
		if (cury == maxn){
			cury = 0;
			curx++;
		}
	}
	
	ld ans = 0.0;
	fore(i,0,maxn){
		fore(j,0,maxn){
			ld sum = 1.0;
			fore(st,0,maxn*maxn){
				sum *= (1.0 - dp[st][i][j][k]);
			}
			ans += sum;
		}
	}
	
	cout << fixed << setprecision(6) << ans << nl;
	return 0;
}