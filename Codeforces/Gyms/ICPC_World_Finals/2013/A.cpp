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
#define pii pair<int,int>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

const int maxn = 4e4 + 100;
const int mod = 52;

int n;
bool d[mod][mod];

void init(){
	fore(i,0,mod) fore(j,0,mod) d[i][j] = false;
}

int main(){
    fast;
    cin >> n;
    fore(x,0,n){
    	string s;
    	cin >> s;
    	for (int i = 0; i < 8; i += 2) if (s[i] != '0'){
    		for (int j = 0; j < 8; j += 2) if (s[j] != '0' && j != i) {
	        	d[s[i]-'A' + (s[i+1]=='+'?0:26)][s[j]-'A' + (s[j+1]=='+'?26:0)] = true;
	      	}
    	}
	      
    }

	// Floyd Warshall but for connectivity.
	fore(i,0,mod){
		fore(j,0,mod){
			fore(k,0,mod){
				d[j][k] |= (d[j][i] & d[i][k]);
			}
		}
	}
	
	bool ok = false;
	
	fore(i,0,mod){
		if (d[i][i]) ok = true; // unbounded as we made it to a cycle.
	}
	
	if (!ok) cout << "bounded" << nl;
	else cout << "unbounded" << nl;
	
	return 0;
}