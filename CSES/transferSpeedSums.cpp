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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+10;

struct Edge{
	ll u,v,w;
};
struct UF{
	ll pad,tam,ran;
};

vector <UF> uf;
vector <Edge> e;
ll n,ans;

void init(){
	ans = 0;
	uf.resize(n+1);
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].ran = 0;
		uf[i].tam = 1;
	}
}

int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

bool join(int u, int v, int w){
	u = bus(u);
	v = bus(v);
	if (u == v) return false;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	ans += uf[u].tam*uf[v].tam*w;
	
	uf[v].pad = u;
	uf[u].tam += uf[v].tam;
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	return true;
}

bool cmp(Edge &e1, Edge &e2){
	return e1.w > e2.w;
}

int main(){
    fast;
    cin >> n;
    init();
    fore(i,1,n){
    	ll u,v,w;
    	cin >> u >> v >> w;
    	e.pb({u,v,w});
    }
    
    sort(ALL(e),cmp);
    
    for(auto &edge : e){
    	join(edge.u,edge.v,edge.w);
    }
    
    cout << ans << nl;
    
    return 0;
}