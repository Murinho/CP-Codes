// Problem: H. Huron Designs
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/105873/problem/H
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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

const ll maxmask = 2097152;
const ll maxn = 21;
const ld eps = 1e-7;

ll n;
ld dp[maxmask]; // want to maximize this.
ll d[maxn],p[maxn],c[maxn],lx[maxn],rx[maxn],ly[maxn],ry[maxn];
ll pw[maxn];
bool vis[maxmask];
ld ans = 0.0;


void precalc(){
	pw[0] = 1;
	fore(i,1,maxn) pw[i] = (pw[i-1]*2ll);
}

int main(){
    fast;
    cin >> n;
    precalc();
    fore(i,0,n){
    	cin >> d[i] >> p[i] >> c[i] >> lx[i] >> rx[i] >> ly[i] >> ry[i];
    }
    
    queue <ll> q;
    q.push(0);
    dp[0] = 0.0;
    vis[0]=true;
    
    while(sz(q)){
    	ll mk = q.front();
    	q.pop();
    	
    	ans = max(ans,dp[mk]);
    	
    	// Compute current time:
    	ll curtime = 0;
    	fore(i,0,n){
    		if (pw[i]&mk){
    			curtime += c[i];
    		}
    	}
    	
    	//cout << "Cur mk: " << mk << " curtime: " << curtime << nl;
    	
    	// Check if I can propagate to some task:
    	fore(i,0,n){
    		if (!(pw[i]&mk)){
    			if (curtime + c[i] <= d[i]){
    				ld profit = (ld)p[i];

    				ld add = (rx[i]+lx[i])/2.0;
    				
    				//cout << "Prop to: "<<mk + pw[i] << nl;
    				
    				if (curtime + c[i] <= ly[i]){ // you will get the bonus 100% of the time.
    					//cout << "Always" << nl;
    					dp[mk+pw[i]] = max(dp[mk+pw[i]], dp[mk] + profit + add);
    				}
    				else if (curtime + c[i] <= ry[i] && ly[i] != ry[i]){ // sometimes you will get the bonus.
    					//cout << "Sometimes" << nl;
    					ld vrl = ry[i] - (curtime + c[i]);
    					ld whole = ry[i] - ly[i];
    					ld mult = vrl/whole;
    					add *= mult;
    					dp[mk+pw[i]] = max(dp[mk+pw[i]], dp[mk] + profit + add);
    				}
    				else{ // you will never get the bonus.
    					//cout << "Never" << nl;
    					dp[mk+pw[i]] = max(dp[mk+pw[i]], dp[mk] + profit);
    				}
    				
    				if (!vis[mk+pw[i]]){
						vis[mk+pw[i]] = true;
						q.push(mk+pw[i]);
    				}
    			}
    		}
    	}
    }
    
    cout << fixed << setprecision(10) << ans << nl;
    return 0;
}