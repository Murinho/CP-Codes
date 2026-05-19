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

const ll maxn = 2e5+10;

struct STree{
	vi st; int n;
	STree(int n): st(4*n + 5),n(n){}

	ll query(int node,int ini,int fin,int l,int r){
		if (l <= ini && fin <= r) return st[node]; //Fully in
		if (ini > r || fin < l) return 0; //Fully out
		int mid = (ini+fin)/2;
		return (query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r)); 
	}
	void upd(int node,int ini,int fin,int pos, ll val){
		if (fin < pos || pos < ini) return; //Fully out
		if (ini == fin && ini == pos) { 
			st[node] += val;
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,pos,val);  
		upd(2*node + 1,mid+1,fin,pos,val); 
		st[node] = (st[2*node] + st[2*node + 1]);
		return;
	}
	void upd(int pos, ll val){ upd(1,0,n,pos,val);}
	ll query(int l, int r){ return query(1,0,n,l,r);}
};

ll n,k,a[maxn],ans=0;
vi uni;

int main(){
    fast;
    cin >> n >> k;
    fore(i,1,n+1){
    	cin >> a[i];
    	uni.pb(a[i]);
    }
    
    sort(ALL(uni));
    uni.erase(unique(ALL(uni)),uni.end());
    
	fore(i,1,n+1){
		a[i] = lower_bound(ALL(uni),a[i]) - uni.begin();
		//cout << a[i] << " ";
	}
	//cout << nl;
	
	ll m = sz(uni);
	
	STree st(m);
	
	fore(i,1,k+1){
		if (i > 0 && a[i]+1 < m) ans += st.query(a[i]+1,m-1);
		st.upd(a[i],+1);
	}
	
	fore(i,k+1,n+1){
		cout << ans << " ";
		if (a[i-k] > 0) ans -= st.query(0,a[i-k]-1);
		st.upd(a[i-k],-1);
		
		if (a[i]+1 < m) ans += st.query(a[i]+1,m-1);
		st.upd(a[i],+1);
	}
	cout << ans << nl;
	return 0;
}