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
 
const ll maxn = 2e5+100;
const ll lzneut = 0; // be aware of the value of lzneut!!
const ll neut = 0;
 
struct Line{
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>>{ // For Max values
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	// For Min values use: cht.add(-k,-m) and -cht.query(x);
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p > y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
 
struct STree{
	vector <LineContainer> lct;
	vi st;
	ll n;
	STree(int n): lct(4*n+5), st(4*n + 5, 0), n(n) {}
	
	void upd(int node, int ini, int fin, ll ca, ll cb, ll l, ll r){
		if (fin < l || r < ini) return;
		if (l <= ini && fin <= r){
			lct[node].add(ca,cb);
			st[node]++;
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,ca,cb,l,r);
		upd(2*node + 1,mid+1,fin,ca,cb,l,r);
		// st[node] = (st[2*node] + st[2*node + 1]);
		return;
	}
	
	void query(int node, int ini, int fin, ll pos, ll &ans){
		if (pos < ini || fin < pos) return;
		if (st[node] > 0) ans = max(ans,lct[node].query(pos));
		if (ini >= fin) return;
		int mid = (ini+fin)/2;
		query(2*node,ini,mid,pos,ans);
		query(2*node + 1,mid+1,fin,pos,ans);
		return; 
	}
	
	void upd(ll ca, ll cb, ll l, ll r){ upd(1,0,n,ca,cb,l,r); }
	void query(ll pos, ll &ans){ query(1,0,n,pos,ans); }
};
 
struct UF{
	ll pad,ran,l,r;
};
 
UF uf[maxn];
 
int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}
 
bool join(int u, int v){
	u = bus(u);
	v = bus(v);
	
	if (u == v) return false;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	uf[v].pad = u;
	uf[u].l = min(uf[u].l,uf[v].l);
	uf[u].r = max(uf[u].r,uf[v].r);
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	return true;
}
 
ll n,k,a[maxn];
vector <pii> v;
vi add[maxn],rem[maxn];
 
void init(){
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].l = uf[i].r = i;
		uf[i].ran = 0;
	}
}
 
bool cmp(pii &p1, pii &p2){
	if (p1.f == p2.f) return p1.s < p2.s;
	return p1.f > p2.f;
}
 
int main(){
    fast;
    cin >> n >> k;
    init();
    STree st(n);
    fore(i,1,n+1){
    	cin >> a[i];
    	v.pb({a[i],i});
    	st.upd(0,a[i],i,i);
    }
    
    sort(ALL(v),cmp);
    
    fore(i,0,n){
    	int pos = i;
    	while(pos < n && v[pos].f == v[i].f){
    		if (v[pos].s-1 >= 1 && a[v[pos].s - 1] >= a[v[pos].s]) join(v[pos].s - 1, v[pos].s);
    		if (v[pos].s+1 <= n && a[v[pos].s + 1] >= a[v[pos].s]) join(v[pos].s + 1, v[pos].s);
    		pos++;
    	}
    	
    	fore(j,i,pos){
    		ll pad = bus(v[j].s);
    		ll l = uf[pad].l;
    		ll r = uf[pad].r;
    		ll elm = v[j].f;
    		ll ramp_stop = r - k + 1;
    		
    		cout << "added: " << v[j].s << " -> " << elm << " range: " << l-k+1 << " " << r << nl;
    		
    		if (l < ramp_stop){
	    		// hacer rampa descendiente en [ramp_stop, r] con pendiente -elm
	    		ll yint = (r+1)*elm;
	    		
	    		st.upd(-elm,yint,ramp_stop,r);
	    		// cout << "upd: " << -elm << " " << yint << " " << ramp_stop << " " << r << nl;
	    		// hacer linea recta en [l, ramp_stop - 1] con yintercept elm
	    		st.upd(0,elm,l,ramp_stop-1);
	    		// cout << "upd: " << 0 << " " << elm << " " << l << " " << ramp_stop - 1 << nl;
	    		
	    		// hacer rampa ascendente en [l-k+1,l]
	    		yint = (elm)*(-1);
	    		
	    		st.upd(elm,yint,max(l-k+1,1ll),l);
			}
			else{
				// hacer ramp descendiente en [l, r] con pendiente -elm
	    		ll yint = (r+1)*elm;
	    		st.upd(-elm,yint,l,r);
	    		
	    		// hacer rampa ascendente en [l-k+1,l]
	    		yint = (elm)*(-1);
	    		
	    		cout << yint << nl;
	    		
	    		st.upd(elm,yint,max(l-k+1,1ll),l);
			}
    	}
    	
    	i = pos-1;
    }
    
    fore(i,1,n-k+2){
    	ll ans = 0;
    	st.query(i,ans);
    	cout << ans << " ";
    }
    cout << nl;
    
    return 0;
}