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

const ll maxn = 1e5+100;
const ll inf = 1e18;

ll n,m;
ll c[maxn],d[maxn],cc[maxn];
vi citcomp[maxn];
set <ll> compcit[maxn]; // borrar las ciudades que vayan saliendo

void init(){
	fore(i,0,n+1){
		d[i] = inf;
	}
	fore(i,0,m+1){
		cc[i] = inf;
	}
}

void daikra(){
	priority_queue < pii, vector <pii>, greater <pii> > pq; // {costo, compania}
	for(auto &elm : citcomp[1]){
		cc[elm] = c[elm];
		pq.push({c[elm],elm});
	}
	
	while(sz(pq)){
		auto [w,u] = pq.top();
		pq.pop();
		
		if (cc[u] != w) continue;
		
		// iterar sobre las ciudades de la compania b.
		vi v;
		for(auto &city : compcit[u]){
			 v.pb(city);
			 d[city] = min(d[city],w);
		}
		
		// borrar las ciudades vistas por esta compania de las listas de las otras companias
		for(auto &city : v){
			for(auto &comp : citcomp[city])	{
				compcit[comp].erase(city);
				if (cc[comp] > w + c[comp]){
					cc[comp] = w + c[comp];
					pq.push({cc[comp],comp});
				}
			}
		}
	}
}

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,1,m+1) cin >> c[i];
    
    fore(i,1,m+1){
    	ll k;
    	cin >> k;
    	fore(j,0,k){
    		ll x;
    		cin >> x;
    		citcomp[x].pb(i); // in this city, companies x have it
    		compcit[i].insert(x); // in this company, there is city x
    	}
    }
    
    daikra();
    
    d[1] = 0;
    
    fore(i,1,n+1) cout << d[i] << " ";
    cout << nl;
    
    return 0;
}