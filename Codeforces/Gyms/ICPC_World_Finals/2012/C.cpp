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
#define fore(i,a,b) for(int i=a;i<b;++i)
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

const int maxn = 20;
const int inf = 1e9+7;

int dp[(1<<maxn)][2][maxn];
int d[maxn][maxn];
int n,m,tc=1,tope_bits;
int pw[maxn];
int ans = inf;

void init(){
	// tope_bits = (n/2) + 2;
	tope_bits = n;
	ans = inf;
	
	// compute powers:
	pw[0] = 1;
	fore(i,1,n){
		pw[i] = (pw[i-1]*2);
	}
	
	fore(i,0,n){
		fore(j,0,n) d[i][j] = inf; // distance matrix.
		d[i][i] = 0;
	}
	
	fore(i,0,(1<<n)){
		fore(j,0,2){
			fore(x,0,n) dp[i][j][x] = inf;
		}
	}
}

void doit(int ss){
	int inipw = 0;
	queue < array <int,2> > q;
	if (ss == 0){
		inipw = pw[0];
		dp[inipw][ss][0] = 0;
		q.push({inipw,0});
	}
	else{
		inipw = pw[n-1];
		dp[inipw][ss][n-1] = 0;
		q.push({inipw,n-1});
	}

	while(sz(q)){
		auto [mk,node] = q.front();
		q.pop();
		
		fore(i,0,n){
			if (!(pw[i]&mk)){
				if (dp[mk + pw[i]][ss][i] == inf){
					q.push({mk + pw[i],i});
				}
				dp[mk + pw[i]][ss][i] = min(dp[mk + pw[i]][ss][i], dp[mk][ss][node] + d[node][i]);
			}
		}
	}
}


int main(){
    fast;
    while(cin >> n >> m){
	    init();
	    fore(i,0,m){
	    	int x,y,z;
	    	cin >> x >> y >> z;
	    	d[x][y] = min(d[x][y],z);
	    	d[y][x] = min(d[y][x],z);
	    }
	    
	    // Do floyd warshall.
	    fore(i,0,n){
	        fore(j,0,n){
	            fore(k,0,n){
	                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	            }
	        }
	    } 
	    ll h = n-2;
	    
	    if (h == 1){ // there is just 1 hotel.
	    	ans = (d[0][1] + d[1][2])*2;
	    	cout << "Case " << tc++ << ": " << ans << nl;
	    	continue;
	    }
	    
	    doit(0); // from the hq
	    doit(1); // from the attraction
	    
	    int pc = 0, ci = 0, p1 = 0, p2 = 0;
	    fore(i,0,(1<<n)){ // checar la cantidad de bits prendidos correspondientes a los hoteles.
	    	pc = __builtin_popcount(i);
	
	    	if (pc == (h/2)+1 && i%2 == 1 && (!(pw[n-1]&i))){ // (n/2) + 1 bits prendidos y el ultimo apagado.
	    		ci = (1<<n) - 1 - i; // complemento de i.
	    		
	    		// Parte 1: checar para cada bit prendido:
	    		p1 = inf;
	    		p2 = inf;
	    		fore(j,1,n-1){
	    			if (pw[j]&i){ 
	    				p1 = min(p1, dp[i][0][j] + dp[ci + pw[j]][1][j]);
	    				p2 = min(p2, dp[i + pw[n-1] - 1][1][j] + dp[ci + pw[j] + 1 - pw[n-1]][0][j]);
	    			}	
	    		}
	    		//cout << p1 << " " << p2 << nl;
	    		ans = min(ans,p1 + p2);
	    	}
	    }
	    cout << "Case " << tc++ << ": " << ans << nl;
    }
    return 0;
}