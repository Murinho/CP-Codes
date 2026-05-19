#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 2e5+100;
const ll neut = 0;

ll a[maxn],lab[maxn],labi[maxn],n,q,sab[maxn];
vi adj[maxn];

struct STree{
	vector <ll> st; int n;
	STree(int n): st(4*n + 5,neut), n(n){}
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node] = a[labi[ini]];
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node+1,mid+1,fin);
		st[node] = st[2*node] + st[2*node + 1];
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
		st[node] = st[2*node] + st[2*node + 1];
	}
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return neut;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r);
	}
	
	void build(){ build(1,1,n);}
	void upd(int pos, ll val){ upd(1,1,n,pos,val);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

ll cnt = 0;

void dfs(int anode, int node){
	cnt++;
	lab[node] = cnt;
	labi[cnt] = node;
	for(auto au : adj[node]){
		if (au != anode){
			dfs(node,au);
		}
	}
	sab[node] = cnt;
	return;
}

int main(){
    fast;
	cin>>n>>q;
	fore(i,1,n+1) cin>>a[i];
	fore(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,1);
	STree st(n);
	st.build();
	while(q--){
		ll t;
		cin>>t;
		if (t == 1){
			ll pos,val;
			cin>>pos>>val;
			st.upd(lab[pos],val);
		}
		else{
			ll pos;
			cin>>pos;
			cout<<st.query(lab[pos],sab[pos])<<nl;
		}
	}
	return 0;
}