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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


// simulation.
// keep segment tree of maximum keeping for each row, the maximum finished onboarding time.
// update segment tree accordingly.
// size of segtree 1e5.

const ll maxn = 1e5+5;

struct STree{
	vi st; int n;
	STree(int n): st(4*n + 5,0ll), n(n) {}
	
	void upd(int node, int ini, int fin, int pos, ll val){
		if (fin < pos || pos < ini) return;
		if (ini == fin){
			st[node] = max(st[node],val);
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,pos,val);
		upd(2*node + 1,mid+1,fin,pos,val);
		st[node] = max(st[2*node], st[2*node + 1]);
	}	
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return 0;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return max(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
	}
	
	void upd(int pos, ll val){ upd(1,1,n,pos,val);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

ll a[maxn],b[maxn];

int main(){
    fast;
    ll n;
    cin >> n;
    STree st(maxn);
    
    fore(i,0,n) cin >> a[i];
    fore(i,0,n) cin >> b[i];
    
    // process in order
    ll last = -1;
    fore(i,0,n){
    		ll mx = st.query(1,a[i]);
    		mx = max(mx,last+1);
    		st.upd(a[i],mx + a[i] + b[i]);
    		last = mx;
    }
    
    cout << st.query(1,maxn-1) << nl;
    return 0;
}