// Problem: M. Moon Dancers
// Contest: Codeforces - 2021 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103274/problem/M
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 360;

bool a[maxn],vis[maxn][maxn]; 
int n,x,cnt;

void dfs(int stp, int node){
	cnt++;
	vis[stp][node]=true;
	// go left:
	int l = (node - stp + 360)%360;
	if (!vis[stp][l] && a[l]) dfs(stp,l);
	// go right:
	int r = (node + stp)%360;
	if (!vis[stp][r] && a[r]) dfs(stp,r);
}

void solve(){
	cin>>n;
	fore(i,0,n){
		cin>>x;
		a[x]=true;
	}
	int ans = 0;
	fore(i,1,maxn){
		int res = 0;
		fore(j,0,maxn){
			if (a[j] && !vis[i][j]){
				cnt = 0;
				dfs(i,j);
				res += cnt/2;
			}
		}
		ans = max(ans,res);
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