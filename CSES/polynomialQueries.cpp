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

const pii neut = {0,0};
const ll maxn = 2e5+100;

ll a[maxn];

struct STree{
	vi st; vector <pii> lazy; int n;
	
	STree(int n): st(4*n + 5,0), lazy(4*n + 5,neut), n(n) {}
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node] = a[ini];
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node + 1,mid+1,fin);
		st[node] = (st[2*node] + st[2*node + 1]);
	}
	
	ll gauss(ll start, ll len, ll step){
		return 1LL * start * len + 1ll * step * (len-1) * len / 2ll;
	}
	
	void push(int node, int ini, int fin){
		if (lazy[node] == neut) return;
		
		st[node] += gauss(lazy[node].fst,fin-ini+1, lazy[node].snd);
		
		if (ini < fin){
			int mid = (ini+fin)/2;
			lazy[2*node].fst += lazy[node].fst;
			lazy[2*node].snd += lazy[node].snd;
			lazy[2*node + 1].fst += lazy[node].fst + 1LL * lazy[node].snd * (mid - ini + 1);
			lazy[2*node + 1].snd += lazy[node].snd;
		}
		
		lazy[node] = neut;
	}
	
	void upd(int node, int ini, int fin, int l, int r, int val){
		if (lazy[node].fst) push(node,ini,fin);
		if (fin < l || r < ini) return;
		if (l <= ini && fin <= r){
			lazy[node].fst = val + (ini - l);
			lazy[node].snd++;
			push(node,ini,fin);
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,l,r,val);
		upd(2*node + 1,mid+1,fin,l,r,val);
		st[node] = st[2*node] + st[2*node + 1];
	}
	
	ll query(int node, int ini, int fin, int l, int r){
		if (lazy[node].fst) push(node,ini,fin);
		if (fin < l || r < ini) return 0;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r);
	}
	
	void build(){ build(1,1,n);}
	void upd(int l, int r){ upd(1,1,n,l,r,1);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

ll n,q;

int main(){
    fast;
	cin >> n >> q;
	fore(i,1,n+1) cin >> a[i];
	
	STree st(n);
	st.build();
	
	while(q--){
		ll t,l,r;
		cin >> t >> l >> r;
		if (t == 1) st.upd(l,r);
		else cout << st.query(l,r) << nl;
	}
	
	return 0;
}