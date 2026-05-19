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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+100;

struct Node{
	ll pad,ran;
};

struct UF{
	vector <Node> uf; int n;
	
	UF(int n): uf(n+1), n(n) {}
	
	void init(){
		fore(i,0,n+1){
			uf[i].pad = i;
			uf[i].ran = 0;
		}
	}
	
	int bus(int u){
		if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
		return uf[u].pad;
	}
	
	bool connected(int u, int v){
		u = bus(u);
		v = bus(v);
		return u == v;
	}
	
	void join(int u, int v){
		u = bus(u);
		v = bus(v);
		if (u == v) return;
		
		if (uf[u].ran < uf[v].ran) swap(u,v);
		
		uf[v].pad = u;
		
		if (uf[u].ran == uf[v].ran) uf[u].ran++;
	}
};

ll n,m,q,a[maxn],b[maxn],qa[maxn],qb[maxn],res[maxn];
ll l[maxn],r[maxn];
vi tocheck[maxn];

int main(){
    fast;
    cin >> n >> m >> q;
    fore(i,1,m+1){
    	cin >> a[i] >> b[i];
    }
    
    fore(i,1,q+1){
    	cin >> qa[i] >> qb[i];
    }
    
    UF uf(n);
    
    // init the binary search:
    fore(i,1,q+1){
    	l[i] = 0;
    	r[i] = m+1;
    }
 
    bool changed = true;
    while(changed){
    	changed = false;
    	uf.init();
    	fore(i,1,q+1){
    		if (l[i] != r[i]) tocheck[(l[i] + r[i])/2].pb(i);
    	}
    	fore(i,0,m+2){
    		if (i>0 && i<=m) uf.join(a[i],b[i]);
    		while(sz(tocheck[i])){
    			changed = true;
    			int id = tocheck[i].back();
    			tocheck[i].ppb();
    			
    			if (uf.connected(qa[id],qb[id])) r[id] = i;
    			else l[id] = i+1;
    		}
    	}
    }
    
    fore(i,1,q+1){
    	if (l[i] > m) cout << -1 << nl;
    	else cout << l[i] << nl;
    }
    return 0;
}