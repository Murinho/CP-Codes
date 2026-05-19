#include <bits/stdc++.h>
#include <ext/rope>
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
#define ull unsigned long long
 
using namespace std;
using namespace __gnu_cxx;

const ll maxn = 1e4+100;

struct qu{
	ll t,x,y;	
};

string s;
ll q;
rope <char> rp; // 0-indexed.
vector <qu> qs;
vector <pii> aqs; // answer queries {time, id}
char res[maxn];

int main(){
    fast;
   	cin >> s;
   	for(auto &au : s){
   		rp.pb(au);
   	}
   	
   	cin >> q;
   	qs.resize(q);
   	fore(i,0,q){
   		cin >> qs[i].t;
   		if (qs[i].t == 1){
   			cin >> qs[i].x >> qs[i].y;
   		}
   		else if (qs[i].t == 2){
   			cin >> qs[i].x >> qs[i].y;
   		}
   		else if (qs[i].t == 3){
   			cin >> qs[i].y;
   			aqs.pb({i,i});
   		}
   		else{
  			cin >> qs[i].x >> qs[i].y;
  			aqs.pb({qs[i].x,i}); 			
   		}
   	}
   	
   	sort(ALL(aqs));
   	
   	// for(auto &au : aqs) cout << au.fst << " " << au.snd << nl;

   	int pos = 0;
   	fore(i,0,q){
   		while(pos < sz(aqs) && aqs[pos].fst == i){
   			int id = aqs[pos].snd;
   			res[id] = rp[qs[id].y];
   			pos++;
   		}
   		
   		if (qs[i].t == 1){
   			rope<char> sub = rp.substr(qs[i].x, qs[i].y-qs[i].x+1);
   			rp.erase(qs[i].x, qs[i].y-qs[i].x+1);
   			sub += rp;
   			swap(sub,rp);
   		}
   		else if (qs[i].t == 2){
   			rope <char> sub =  rp.substr(qs[i].x, qs[i].y-qs[i].x+1);
   			rp.erase(qs[i].x, qs[i].y-qs[i].x+1);
   			rp += sub;
   		}
   	}
   	
   	fore(i,0,q){
   		if (qs[i].t == 3) cout << res[i] << nl;
   		else if (qs[i].t == 4) cout << res[i] << nl;
   	}
   	
    	return 0;
}