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

const ll maxn = 1e6+100;
ll a[maxn];

struct Node{
	ll max_sum, sum, lb, rb;
	
	Node(): max_sum(0), sum(0), lb(0), rb(0) {};
	
	void merge(Node izq, Node der){
		(*this).max_sum = max({(*this).max_sum, izq.rb + der.lb, izq.sum + der.lb, izq.rb + der.sum, izq.sum + der.sum, izq.max_sum, der.max_sum});
		(*this).sum = izq.sum + der.sum;
		(*this).lb = max({izq.sum + der.lb, izq.lb, izq.sum + der.sum, 0ll});
		(*this).rb = max({izq.rb + der.sum, der.rb, izq.sum + der.sum, 0ll});
	}
};

struct STree{
	vector <Node> st; int n;
	STree(int n): st(4*n + 5), n(n) {};
	
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node].max_sum = max(0ll,a[ini]);
			st[node].sum = a[ini];
			st[node].lb = st[node].rb = max(0ll,a[ini]);
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node + 1,mid+1,fin);
		st[node].merge(st[2*node],st[2*node + 1]);
		return;
	}	
	
	Node query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return Node();
		if (l <= ini && fin <= r){
			return st[node];
		}
		int mid = (ini+fin)/2;
		Node ret;
		ret.merge(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
		return ret;
	}
	
	void build(){ build(1,1,n); }
	Node query(int l, int r){ return query(1,1,n,l,r); }
};

ll n,q;

int main(){
    fast;
    cin >> n >> q;
    fore(i,1,n+1) cin >> a[i];
    
    STree st(n);
    st.build();
    
    while(q--){
    	ll l,r;
    	cin >> l >> r;
    	Node ret = st.query(l,r);
    	cout << ret.max_sum << nl;
    }
    return 0;
} 