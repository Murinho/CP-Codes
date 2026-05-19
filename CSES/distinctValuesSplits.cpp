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
const ll mod = 1e9+7;
const ll inf = 1e9+7;
const ll neut = 0;

ll ne[maxn];

struct STree{
	vi st; int n;
	STree(int n): st(4*n + 5),n(n){}

	void build(int node,int ini,int fin){
		if (ini == fin) { 
			st[node] = ne[ini];
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid); //Left sohn
		build(2*node + 1,mid+1,fin); //Right sohn
		st[node] = min(st[2*node],st[2*node + 1]); //desired operation
		return;
	}
	ll query(int node,int ini,int fin,int l,int r){
		if (l <= ini && fin <= r) return st[node]; //Fully in
		if (ini > r || fin < l) return inf; //Fully out
		int mid = (ini+fin)/2;
		return min(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r)); 
	}

	void build(){ build(1,0,n);}
	ll query(int l, int r){ return query(1,0,n,l,r);}
};

struct STLazy{ //Lazy Segment Tree with set and add updates with sum get query.
	vi st,lzadd; int n;
	STLazy(int n): st(4*n + 5,neut),lzadd(4*n + 5,0), n(n){}

	void increment(int node, int ini, int fin, ll val){
		lzadd[node] += val;
		lzadd[node] %= mod;
		st[node] += (fin-ini+1)*val;
		st[node] %= mod;
	}

	void push(int node, int ini, int fin){
		int mid = (ini+fin)/2;
		if (lzadd[node]){
			increment(2*node,ini,mid,lzadd[node]);
			increment(2*node + 1,mid+1,fin,lzadd[node]);
			lzadd[node] = 0;
		}
	}

	void addUpdate(int node, int ini, int fin, int l, int r, ll val){
		if (fin < l || r < ini) return;
		if (l <= ini && fin <= r){
			increment(node,ini,fin,val);
			return;
		}
		push(node,ini,fin);
		ll mid = (ini+fin)/2;
		addUpdate(2*node,ini,mid,l,r,val);
		addUpdate(2*node + 1,mid+1,fin,l,r,val);
		st[node] = (st[2*node] + st[2*node + 1])%mod;
	}

	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return neut;
		if (l <= ini && fin <= r){
			return st[node];
		}
		push(node,ini,fin);
		int mid = (ini+fin)/2;
		ll lsum = query(2*node,ini,mid,l,r);
		ll rsum = query(2*node + 1,mid+1,fin,l,r);
		st[node] = (st[2*node] + st[2*node + 1])%mod;
		return (lsum + rsum)%mod;
	}

	void addUpdate(int l, int r, ll val){ addUpdate(1,0,n,l,r,val);} //[l,r]
	ll query(int l, int r){ return query(1,0,n,l,r);} //[l,r]
};

vi v;
vi p[maxn];
ll dp[maxn],a[maxn];
ll n;

void init(){
	ne[0] = ne[n+1] = n+1;
}

int main(){
   	fast;
   	cin >> n;
   	init();
   	fore(i,1,n+1){
   		cin >> a[i];
   		v.pb(a[i]);
   	}
   	
   	sort(ALL(v));
   	v.erase(unique(ALL(v)),v.end());
   	
   	fore(i,1,n+1){
   		a[i] = lower_bound(ALL(v), a[i]) - v.begin();
   	}
   	
   	// meter indices y calcular el siguiente de cada uno
	fore(i,1,n+1){
		ne[i] = n+1;
		if (sz(p[a[i]]) > 0) ne[p[a[i]].back()] = i;
		p[a[i]].pb(i);
	}
	
	// fore(i,0,n+2){
		// cout << ne[i] << " ";
	// }
	// cout << nl;
	

   	STree st(n+1);
   	st.build();
   	
   	STLazy dp(n);
   	dp.addUpdate(0,0,1);
   	
   	fore(i,0,n){
   		ll dpval = dp.query(i,i);
   		int l = i+1;
   		int r = n;
   		while(l < r){
   			ll mid = (l+r+1)/2;
   			if (st.query(i+1,mid) <= mid) r = mid-1;
   			else l = mid;
   		}
   		dp.addUpdate(i+1,l,dpval);
   	}
   	
   	cout << dp.query(n,n) << nl;
   	return 0;
}