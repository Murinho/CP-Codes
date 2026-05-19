// Problem: E. Enchanted Exam
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/E
// Memory Limit: 512 MB
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

const int maxn = 105;
bool c[maxn];
vi p;

void sieve(){
	c[1]=true;
	for(int i = 2; i<maxn; i++){
		if (!c[i]){
			p.pb(i);
			for(int j = 2; i*j < maxn; j++) c[i*j]=true;
		}
	}	
}

void solve(){
	sieve();
	for(auto &prime : p){
		cout<<prime<<nl;
		cout.flush();
		string ret;
		cin>>ret;
		if ("equal" == ret){
			return;
		}
		else if ("multiple" == ret){
			cout<<1<<nl;
			cout.flush();
			cin>>ret;
			return;
		}
		else if ("factor" == ret){
			for(int i = prime*2; i<maxn; i += prime){
				cout<<i<<nl;
				cout.flush();
				cin>>ret;
				if (ret == "equal"){
					return;
				}
			}
		}
	}
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}