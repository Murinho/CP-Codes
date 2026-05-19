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

const ll inf = 1e13;
const ll neutmax = -inf;
const ll neutmin = inf;
const ll maxn = 2e5+100;
const ll loga = 18;

ll a[maxn],pref[maxn];
ll up[maxn][loga];

struct STMax{
	vi st; int n;
	STMax(int n): st(4*n + 5,neutmax), n(n) {}
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node] = pref[ini];
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node + 1,mid+1,fin);
		st[node] = max(st[2*node],st[2*node + 1]);
	}
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return neutmax;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return max(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
	}
	
	void build(){ build(1,1,n);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

struct STMin{
	vi st; int n;
	STMin(int n): st(4*n + 5,neutmin), n(n) {}
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node] = pref[ini];
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node + 1,mid+1,fin);
		st[node] = min(st[2*node],st[2*node + 1]);
	}
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return neutmin;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return min(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
	}
	
	void build(){ build(1,1,n);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

ll n,lwb,upb,q,zmax,outside;

void binlift(){
	up[outside][0] = outside;
	fore(i,1,loga){
		fore(j,0,2*n + 3) up[j][i] = up[up[j][i-1]][i-1];
	}
}

int main(){
    fast;
    cin >> n >> lwb >> upb;
    
    ll difb = upb - lwb;
    fore(i,1,n+1){
    	cin >> a[i];
    	pref[i] = pref[i-1] + a[i];
    }
    
    STMax stmax(n);
    stmax.build();
    STMin stmin(n);
    stmin.build();
    
    zmax = 2*n + 1;
	outside = 2*n + 2;
    // min positions [0,n]
    // max positions [n+1,2*n], zero = 2*n + 1, outside = 2*n + 2
    
    // for each min position know where the next tope happens
    fore(i,0,n+1){
    	int l = i+1;
    	int r = n+1;
    	while(l < r){
    		ll mid = (l+r)/2;
    		ll minq = stmin.query(i+1,mid);
    		ll maxq = stmax.query(i+1,mid);
    		if (minq <= pref[i] || maxq >= pref[i] + difb) r = mid;
    		else l = mid+1;
    	}
    	if (l == n+1) up[i][0] = outside; // el siguiente se va fuera
    	else if (stmin.query(i+1,l) <= pref[i]) up[i][0] = l; // el siguiente es un minimo
    	else up[i][0] = n+l; // el siguiente es un maximo
    }
    
    // for each max position know where the next tope happens
    fore(i,0,n+1){
    	ll id = zmax;
    	if (i > 0) id = i + n;
    	
    	int l = i+1;
    	int r = n+1;
    	while(l < r){
    		ll mid = (l+r)/2;
    		ll minq = stmin.query(i+1,mid);
    		ll maxq = stmax.query(i+1,mid);
    		if (minq <= pref[i] - difb || maxq >= pref[i]) r = mid;
    		else l = mid+1;
    	}
    	
    	if (l == n+1) up[id][0] = outside; // el siguiente se va fuera
    	else if (stmin.query(i+1,l) <= pref[i] - difb) up[id][0] = l; // el siguiente es un minimo
    	else up[id][0] = n+l; // el siguiente es un maximo
    }
    
    // do binary lifting.
    binlift();
    
    // process the queries
    cin >> q;
    while(q--){
    	ll l,r,x;
    	cin >> l >> r >> x;
    	
    	if (lwb == upb){
    		cout << lwb << nl;
    		continue;
    	}
    	
    	if (l == r){
    		ll res = x + a[l];
    		if (res > upb) res = upb;
    		else if (res < lwb) res = lwb;
    		cout << res << nl;
    		continue;
    	}
    	
    	// binary search to find the next value that goes up or down.
    	ll difupb = upb - x;
    	ll diflwb = x - lwb;
    	
    	int ini = l;
    	int fin = r+1;
    	while(ini < fin){
    		ll mid = (ini+fin)/2;
    		ll minq = stmin.query(l,mid);
    		ll maxq = stmax.query(l,mid);
    		if (pref[l-1] - minq >= diflwb || maxq - pref[l-1] >= difupb) fin = mid;
    		else ini = mid+1;
    	}
    	if (fin == r+1){ // el siguiente se va fuera
    		ll res = x + (pref[r] - pref[l-1]);
    		cout << res << nl;
    	}
    	else{
    		ll cur = ini;
    		ll maxq = stmax.query(l,ini);
    		
    		if (maxq - pref[l-1] >= difupb) cur += n; // se alcanzo maximo, sino minimo
    		
    		rofe(i,loga,0){
    			ll nex = up[cur][i];
    			if (nex >= n+1) nex -= n;
    			
    			if (nex <= r){
    				cur = up[cur][i]; // si no se sale del rango
    			}
    		}
    		
    		ll sum = 0;
    		ll convid = cur;
    		if (convid >= n+1) sum = upb, convid -= n;
    		else sum = lwb;
    		
    		ll res = sum + (pref[r] - pref[convid]);
    		cout << res << nl;
    	}
    }
    return 0;
}