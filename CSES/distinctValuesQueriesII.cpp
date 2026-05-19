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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 4e5+100;
const ll inf = 1e9+7;

ll nx[maxn];

struct Qu{
	ll t,x,y;
};

struct STree{
	vi st; int n;
	STree(int n): st(4*n + 5,inf), n(n) {}
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node] = nx[ini];
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node + 1,mid+1,fin);
		st[node] = min(st[2*node],st[2*node + 1]);
	}
	void upd(int node, int ini, int fin, int pos, ll val){
		if (fin < pos || pos < ini) return;
		if (ini == fin){
			st[node] = val;
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,pos,val);
		upd(2*node + 1,mid+1,fin,pos,val);
		st[node] = min(st[2*node],st[2*node + 1]);
	}
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return inf;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return min(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
	}
	
	void build(){ build(1,1,n); }
	void upd(int pos, ll val){ upd(1,1,n,pos,val); }
	ll query(int l, int r){ return query(1,1,n,l,r); }
};

ll n,q,a[maxn];
Qu qs[maxn];
vi uni;
set <ll> p[maxn];

int main(){
    fast;
    cin >> n >> q;
    fore(i,1,n+1){
    	cin >> a[i];
    	uni.pb(a[i]);
    	nx[i] = inf;
    }
    
    fore(i,1,q+1){
    	cin >> qs[i].t >> qs[i].x >> qs[i].y;
    	if (qs[i].t == 1) uni.pb(qs[i].y);
    }
    
    // value compression.
    sort(ALL(uni));
    uni.erase(unique(ALL(uni)),uni.end());
    
    fore(i,1,n+1){
    	ll x = a[i];
    	a[i] = lower_bound(ALL(uni),x) - uni.begin();
    	p[a[i]].insert(i);
    }
	fore(i,0,sz(uni)){
		ll las = -1;
		for(auto au : p[i]){
			if (las != -1) nx[las] = au;
			las = au;
		}
	}
	
	//fore(i,1,n+1) cout << a[i] << " ";
	//cout << nl;
	
    fore(i,1,q+1){
    	if (qs[i].t == 1){
    		qs[i].y = lower_bound(ALL(uni),qs[i].y) - uni.begin();
    	}
    }
    
    //fore(i,1,n+1) cout << nx[i] << " ";
    //cout << nl;
    
    // build the segment tree.
    STree st(n);
    st.build();
    
    fore(i,1,q+1){
    	if (qs[i].t == 1){
    		ll pos = qs[i].x;
    		ll nval = qs[i].y;
    		
    		// mover los actuales.
    		auto it = p[a[pos]].find(pos);
    		if (it != p[a[pos]].begin()){
    			ll prev_pos = *prev(it);
    			nx[prev_pos] = nx[pos];
    			st.upd(prev_pos,nx[prev_pos]);
    		}
    		
    		p[a[pos]].erase(pos);
    		
    		// mover los nuevos.
    		a[pos] = nval;
    		p[a[pos]].insert(pos);
    		it = p[a[pos]].find(pos);
    		
    		if (it == p[a[pos]].begin()){ // si soy el primero de todos
    			auto nit = next(it);
    			if (nit == p[a[pos]].end()) nx[pos] = inf;
    			else nx[pos] = *nit;
    			
    			st.upd(pos,nx[pos]);
    		}
    		else{ 
    			ll prev_pos = *prev(it);
    			nx[pos] = nx[prev_pos];
    			nx[prev_pos] = pos;
    			
    			st.upd(prev_pos,nx[prev_pos]);
    			st.upd(pos,nx[pos]);
    		}
    	}
    	else{
    		ll res = st.query(qs[i].x, qs[i].y);
    		if (res <= qs[i].y) cout << "NO" << nl;
    		else cout << "YES" << nl;
    	}
    }
    return 0;
}