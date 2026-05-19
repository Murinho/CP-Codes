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

const int maxn = 1e6+5;
const int inf = 1e9+7;
const int maxk = 8;

struct Pyramid{
	int cubes,len;
	char c;
};

int n;
int dp[maxn];
pair <int, pair <int,int> > p[maxn][maxk+1];
vector < pair <int, pair <int,int> > > a;

void precalc(){
	// calculate the amount of low pyramids:
	int cur = 1;
	int sum = 0;
	while(sum + (cur*cur) < maxn){
		sum += (cur*cur);
		if (cur >= 3){
			a.pb({sum,{cur,1}});
		}
		cur += 2;
	}
	
	cur = 2;
	sum = 0;
	while(sum + (cur*cur) < maxn){
		sum += (cur*cur);
		if (cur >= 3){
			a.pb({sum,{cur,1}});
		}
		cur += 2;
	}
	 
	// calculate the amount of high pyramids:
	cur = 1;
	sum = 0;
	while(sum + (cur*cur) < maxn){
		sum += (cur*cur);
		if (cur >= 2){
			a.pb({sum,{cur,0}});
		}
		cur++;
	}
	
	sort(ALL(a));
	
	fore(i,1,maxn) dp[i] = inf;
	
	dp[0] = 0;
	for(int i = sz(a)-1; i>=0; i--){
		int cnt = a[i].fst;
		for(int j = maxn - cnt - 1; j >= 0; j--){
			if (dp[j] >= maxk) continue;
			if (dp[j]+1 <= dp[j+cnt]){
				dp[j + cnt] = dp[j] + 1;
				p[j + cnt][dp[j+cnt]] = a[i];
			}
		}
	}
}


void solve(){
	if (dp[n] == inf){
		cout << "impossible" << nl;
		return;
	}
	
	int c = n;
	
	vector < pair <int,int> > ans;
	int cnt = dp[c], cur_ptr = sz(a)-1;
	
	while(cnt--){
		while(1){
			int to = c - a[cur_ptr].fst;
			if (to < 0){
				cur_ptr--;
				continue;
			}
			
			if (dp[to] <= cnt && (p[to][cnt].fst < a[cur_ptr].fst || (p[to][cnt].fst == a[cur_ptr].fst && p[to][cnt].snd != a[cur_ptr].snd))){
				c -= a[cur_ptr].fst;
				ans.pb(a[cur_ptr--].snd);
				break;
			} else cur_ptr--;
		}
	}
	
	for(auto key : ans){
		if (key.snd == 0) cout << key.fst << "H ";
		else cout << key.fst << "L ";
	}
	cout << nl;
}


int main(){
    fast;
    precalc();
    for(int tc=1;;tc++){
    	cin >> n;
    	if (n == 0) break;
    	cout << "Case " << tc << ": ";
    	solve();
    }
    
    return 0;
}