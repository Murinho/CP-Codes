// Problem: C. Los ogros tienen capas
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const ll maxk = 1030;
const ll maxn = 105;
const ll inf = 1e18+100;
const ll loga = 11;

ll dp[maxn][maxk];
ll n,k,a[maxn],b[maxn],p[maxn],pk,pw[loga];

void init(){
	fore(i,0,maxn){
		fore(j,0,maxk) dp[i][j] = inf;
	}
	
	pw[0]=1;
	fore(i,1,loga) pw[i] = (pw[i-1]*2ll);
}

int main(){
    fast;
    cin >> n >> k;
    init();
    pk = pw[k];
    
    fore(i,1,n+1){
    	cin >> a[i];
    	p[i] = p[i-1] + a[i];
    }
    
    fore(i,0,k){
    	cin >> b[i];
    }
    
    // hacer la dp
    dp[0][0] = 0;
    fore(i,0,n){
    	fore(mk,0,pk){
    		if (dp[i][mk] == inf) continue;
    		
    		fore(j,i+1,n+1){
    			ll sum = p[j]-p[i];
    			
    			fore(bt,0,k){
    				if (pw[bt]&mk) continue;
    				
    				ll dif = (sum-b[bt])*(sum-b[bt]);
    				
    				dp[j][mk + pw[bt]] = min(dp[j][mk + pw[bt]], dp[i][mk] + dif);
    			}
    		}
    	}
    }
    
    cout << dp[n][pk-1] << nl;
    return 0;
}