// Problem: C. Cellar Chase
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/C
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
 
using namespace std;

const ll maxn = 1e6+10;
string s;

pii dfs(int pos){
	if (s[pos+1] == ')') return {1,pos+1};
	pii lft = dfs(pos+1);
	char op = s[lft.snd + 1];
	pii rgt = dfs(lft.snd + 2);
	if (op == '*') return {lft.fst + rgt.fst, rgt.snd + 1};
	return {max(lft.fst, rgt.fst), rgt.snd + 1};
}

void solve(){
	cin >> s;
	pii ret = dfs(0);
	cout<<ret.fst<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}