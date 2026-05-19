// Problem: H. Robotic Skills
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/H
// Memory Limit: 1024 MB
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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1010;
ll n,a[maxn][maxn],dprow[maxn][2],dpcol[maxn][2];
pii where[maxn*maxn]; // where is a value located.

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1){
    	fore(j,1,n+1){
    		cin>>a[i][j];
    		where[a[i][j]] = {i,j};
    	}
    }
    
    rofe(x,(n*n)+1,1){ // alternar entre horizontal y vertical
    	ll i = where[x].fst;
    	ll j = where[x].snd;
    	ll hor = dpcol[j][1] + 1;
    	ll ver = dprow[i][0] + 1;
    	dprow[i][0] = max(dprow[i][0],hor);
    	dpcol[j][0] = max(dpcol[i][0],hor);
    	dprow[i][1] = max(dprow[i][1],ver);
    	dpcol[j][1] = max(dpcol[j][1],ver);
    }
    
    ll ans = 1;
    fore(i,1,n+1) {
    	fore(j,0,2){
    		ans = max({ans,dprow[i][j],dpcol[i][j]});
    	}
    }
    	
    cout<<ans<<nl;
    return 0;
}