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

const ll alpha = 25;
const ll maxmask = (1ll<<25);

ll n,res[alpha][alpha];
vi mknodes[maxmask];

void init(){
	fore(i,0,n){
		fore(j,0,n) res[i][j] = -1;
	}
}

int main(){
    fast;
    cin >> n;
    init();
    fore(i,0,n){
    	ll k;
    	cin >> k;
    	fore(j,0,k){
    		string s;
    		cin >> s;
    		ll mk = 0;
    		for(auto &elm : s){
    			mk |= (1ll<<(elm-'a'));
    		}
    		mknodes[i].pb(mk); // push the current node index.
    	}
    }
    
   	// do the process:
   	fore(i,0,n){
   		ll mk = (1ll<<i);
   		res[i][i] = 0;
   		for(int steps = 1;;steps++){
   			ll mk2 = mk;
   			fore(j,0,n){
   				if (!(mk&(1ll<<j))){
   					for(auto &omk : mknodes[j]){
   						if ((mk&omk) == omk){ // if the omk mask, is a subset of mk.
   							mk2 |= (1ll<<j);
   							res[j][i] = steps;
   							break;
   						}
   					}
   				}
   			}
   			if (mk == mk2) break;
   			
   			mk = mk2;
   		}
   	}
   	
   	fore(i,0,n){
   		fore(j,0,n) cout << res[i][j] << " ";
   		cout << nl;
   	}
}