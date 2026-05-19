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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1005;
const ll inf = 1e9+7;

ll dp[maxn][maxn];
ll n;
int mov[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,-2},{1,-2},{-1,2}};

void init(){
	fore(i,0,n) fore(j,0,n) dp[i][j] = inf;
	
	dp[0][0] = 0;
}

bool good(int &x, int &y){
	if (0 <= x && x < n && 0 <= y && y < n) return true;
	return false;
}

void solve(){
	cin >> n;
	init();
	
	queue <pii> q;
	q.push({0,0});
	
	while(sz(q)){
		auto [r,c] = q.front();
		q.pop();
		
		fore(i,0,8){
			int sr = r + mov[i][0];
			int sc = c + mov[i][1];
			if (good(sr,sc) && dp[sr][sc] == inf){
				dp[sr][sc] = dp[r][c] + 1;
				q.push({sr,sc});
			}
		}
	}
	
	fore(i,0,n){
		fore(j,0,n) cout << dp[i][j] << " ";
		cout << nl;
	}
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}