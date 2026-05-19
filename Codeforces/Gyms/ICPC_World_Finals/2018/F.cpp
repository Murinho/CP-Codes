// Problem: F. Go with the Flow
// Contest: Codeforces - 2018 ACM-ICPC World Finals
// URL: https://codeforces.com/gym/102482/problem/F
// Memory Limit: 256 MB
// Time Limit: 12000 ms
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
#define pii pair<int,int>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

int n,mxlen = 0, sum = 0, llen = 0, rlen = 0;
string s;
vector <int> a;

int main(){
    fast;
    cin >> n;
    fore(i,0,n){
    	cin >> s;
    	a.eb(sz(s));
    	mxlen = max(mxlen,sz(s));
    	sum += sz(s)+1;
    }
    
    
    for(int i = mxlen; i<=sum; i++){
    	vector <pii> ant; // keep the position and the answer.
    	int posa = 0; 
    	int j = 0;
    	while(posa < n){
    		int pref = 0; 
    		int pv = -1;
    		int posant = 0;
    		vector <pii> cur;
    		while(posa < n && pref + a[posa] <= i){
    			pref += a[posa];
    			posa++;
    			if (pv != -1){
    				int mx = 1;
    				while(posant < sz(ant) && ant[posant].fst < pv) posant++;
    				
    				for(int j = posant-1; j<=posant+1; j++){
    					if (j < 0 || sz(ant) <= j) continue; // out of the array.
    					
    					if (pv-1 <= ant[j].fst && ant[j].fst <= pv+1){
    						mx = max(mx,ant[j].snd + 1);
    					}
    				}
    				if (mx > rlen){
    					rlen = mx;
    					llen = i;
    				}
    				cur.pb({pv,mx});
    			}
    			pref++; // adding the space between words.
    			pv = pref;
    		}
    		swap(ant,cur);
    		j++;
    	}
    	if (j <= rlen) break;
    }
    cout << llen << " " << rlen << nl;
    return 0;
}