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

const ll maxn = 1e5+100;

struct STree{
	vi st; int n;
	STree(int n): st(4*n + 5), n(n) {}
	
	void upd(int node, int ini, int fin, int pos, ll val){
		if (fin < pos || pos < ini) return;
		if (ini == fin){
			st[node] = max(st[node],val);
			return;
		}
		
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,pos,val);
		upd(2*node + 1,mid+1,fin,pos,val);
		st[node] = max(st[2*node],st[2*node + 1]);
	}
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return 0;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return max(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
	}
	
	void upd(int pos, ll val){ upd(1,0,n,pos,val);}
	ll query(int l, int r){ return query(1,0,n,l,r);}
};

ll n;
map <pii,ll> omp,mp;
vi a,b;
map <ll,ll> mx,my;

void map_shit(){
	sort(ALL(a));
    a.erase(unique(ALL(a)),a.end());
    sort(ALL(b));
    b.erase(unique(ALL(b)),b.end());
    
    fore(i,0,sz(a)){
    	mx[a[i]] = i;
    }
    fore(i,0,sz(b)){
    	my[b[i]] = i;
    }
    
    for(auto &[p,val] : omp){
    	pii np = {mx[p.fst],my[p.snd]};
    	mp[np] = val;
    }
}

vector <pii> points[maxn];

int main(){
    fast;
    cin >> n;
    fore(i,0,n){
    	ll x,y,z;
    	cin >> x >> y >> z;
    	omp[{x,y}] += z;
    	a.pb(x);
    	b.pb(y);
    }
    
    
    map_shit();
    
    STree st(sz(b)); // de tamanio de la cantidad de y's distintas.

    for(auto &[p,val] : mp){
    	points[p.fst].pb({p.snd,val});
    }
    
    // reversear para procesar al reves.
    fore(i,0,sz(a)){
    	if (sz(points[i])) reverse(ALL(points[i]));
    }
    
    fore(i,0,sz(a)){
    	for(auto &[y,val] : points[i]){
    		ll mx = 0;
    		if (y > 0) mx = st.query(0,y-1);
    		mx += val;
    		
    		st.upd(y,mx);
    	}
    }
    
    
    cout << st.query(0,sz(b)-1) << nl;
    return 0;
}