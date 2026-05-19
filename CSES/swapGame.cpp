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
#define vi vector <short>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<int,int>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace std;
 
const int maxn = 362885;
 
static vector <pii> moves = {{0,1},{0,3},{1,2},{1,4},{2,5},{3,4},{3,6},{4,5},{4,7},{5,8},{6,7},{7,8}};
static unordered_map <int,int> mp; // map a permutation with an id.
static int imp[maxn]; // map an id with its permutation
static short dp[maxn];
static int pw[10];
static string s;
 
void precalc(){
	pw[8] = 1;
	rofe(i,8,0){
		pw[i] = (pw[i+1] * 10);
	}
	
	memset(dp,-1,sizeof(dp));
	s = "123456789";
	
	int id = 0;
	int val;
	do{
		val = stoi(s);
		mp[val] = id;
		imp[id] = val;
		id++;
	}while(next_permutation(ALL(s)));
}
 
void bfs(int &stnode){
	dp[stnode] = 0;
	if (stnode == 0) return;
	
	static queue <int> q;
	q.push(stnode);
	while(sz(q)){
		int node = q.front();
		q.pop();
		
		int v = imp[node];
		string s = to_string(v);
		for(auto &au : moves){
			int signode = v;
			signode = signode - ((s[au.fst] - '0')*pw[au.fst]) + ((s[au.fst] - '0')*pw[au.snd]); // remove and add first digit
			signode = signode - ((s[au.snd] - '0')*pw[au.snd]) + ((s[au.snd] - '0')*pw[au.fst]); // remove and add second digit
			signode = mp[signode];
			if (dp[signode] == -1){
				dp[signode] = dp[node] + 1;
				if (signode == 0) return;
				q.push(signode);
			}
		}
	}
}
 
int main(){
    fast;
    precalc();
    s = "";
    fore(i,0,9){
    		char c;
    		cin >> c;
    		s += c;
    }
 
    bfs(mp[stoi(s)]);
    
    cout << dp[0] << nl;
    
    return 0;
}