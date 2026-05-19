// Problem: D. Document Dimensions
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
#define sz(a) ((int)a.size())
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

const int maxn = 2e6 + 100;
const int inf = 1e9+7;
int n,mx=0,best=inf;
string s,t;
int pv[maxn];

void solve(){
	cin>>n;
	fore(i,0,n){
		cin>>t;
		mx = max(mx,sz(t));
		if (i>0) s += " ";
		s += t;
	}
	// compute where is the previous space:
	int las = -1;
	fore(i,0,sz(s)){
		if (s[i] == ' ') las = i;
		pv[i] = las;
	}
	
	// compute the best 
	for(int i = mx; i<=sz(s); i++){
		int pos = 0;
		int h = 0;
		while(pos < sz(s)){
			h++;
			int npos = pos + i - 1;
			
			// check if we are in the end of a word
			if (npos >= sz(s)-1){
				break;
			}
			else if (s[npos] == ' '){
				while(npos < sz(s) && s[npos] == ' ') npos++;
			}
			else if (s[npos+1] == ' '){
				npos++;
				while(npos < sz(s) && s[npos] == ' ') npos++;
			}
			else{ // go to the previous space found.
				npos = pv[npos];
				npos++;
			}
			pos = npos;
		}
		best = min(best, i + h);
	}
	cout<<best<<nl;
}

int main(){
    fast;
    int tc=1;
    while(tc--){
        solve();
    }
}