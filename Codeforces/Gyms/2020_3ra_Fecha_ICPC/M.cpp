// Problem: M. Mathematics society problem
// Contest: Codeforces - 2020 ICPC Gran Premio de Mexico 3ra Fecha
// URL: https://codeforces.com/gym/102890/problem/M
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

const int maxn = 1010;
int placed[10],sum[maxn][10],ne[maxn][10],n,las[10],rem[10],b[10];
int a[maxn];
string s;

bool check(int pos){
	for(int i = 1; i<=9; i++){
		if (placed[i] + sum[pos][i] < b[i] - rem[i]) return false;
	}
	return true;
}

void solve(){
	cin>>s;
	n = sz(s);
	ll tot = n;
	fore(i,0,n){
		int val = (int)(s[i]-'0');
		a[i+1] = val;
		b[val]++;
	}
	
	fore(i,1,10){
		cin>>rem[i];
		tot -= rem[i];
	}
	
	if (tot == 0){
		cout<<tot<<nl;
		return;
	}
	
	// initialize where is the last occurence of each number:
	fore(i,1,10) las[i] = n+1;
	
	// compute the suffix sums for each number:
	for(int i = n; i>=0; i--){
		for(int j = 1; j<=9; j++) sum[i][j] = sum[i+1][j];
		if (i > 0) sum[i][a[i]]++;
	}
	
	// compute the next value for each number and position:
	for(int i = n; i>=0; i--){
		for(int j = 1; j<=9; j++){
			ne[i][j] = las[j];
		}
		if (i > 0) las[a[i]] = i;
	}
	
	// compute the number:
	int cnt = 0;
	int pos = 0;
	for(int i = 0; i<tot; i++){
		for(int j = 9; j>=1; j--){
			int sigpos = ne[pos][j];
			if (sigpos == n+1 || placed[j] == b[j] - rem[j]) continue;
			if (check(sigpos)){
				cout<<j;
				placed[j]++;
				pos = sigpos;
				cnt++;
				break;
			}
		}
	}
	assert(cnt == tot);
	cout<<nl;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}