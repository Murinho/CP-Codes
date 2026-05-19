// Problem: J. Joining the KAK
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/J
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

const ll maxn = 1005;
ll n,k;
string s,ans;
int b[26];
int v[maxn];
int cnt = 0;

void dfs(int cur, ll &len){
	if (cur == len){
		cnt++;
		return;
	}
	
	fore(i,0,26){
		if (b[i] && cnt < k){
			b[i]--;
			v[cur] = i;
			dfs(cur+1,len);
			b[i]++; 
		}
	}
}

void solve(){
	cin >> n >> k;
	cin >> s;
	for(auto &au : s){
		b[(au-'a')]++;
	}
	
	int las = 0;
	fore(i,1,n+1){
		dfs(0,i);
		if (cnt == k){
			las = i;
			break;
		}
	}
	
	fore(i,0,las) cout << (char)(v[i] + 'a');
	cout<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}