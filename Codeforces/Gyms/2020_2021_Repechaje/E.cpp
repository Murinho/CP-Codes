// Problem: E. Enterprise Recognition Program
// Contest: Codeforces - 2020-2021 ICPC - Gran Premio de Mexico - Repechaje
// URL: https://codeforces.com/gym/102966/problem/E
// Memory Limit: 256 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e6+100;
vi g[maxn];
ll tin[maxn],tout[maxn],cnt=0,p[maxn],res[maxn];


struct STree{
	vi st; int n;
	STree(int n): st(4*n + 5,0), n(n) {}
	
	void upd(int node, int ini, int fin, int pos, ll val){
		if (fin < pos || pos < ini) return;
		if (ini == fin){
			st[node] += val;
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,pos,val);
		upd(2*node + 1,mid+1,fin,pos,val);
		st[node] = st[2*node] + st[2*node + 1];
	}	
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return 0;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r);
	}
	
	void upd(int pos, ll val){ upd(1,1,n,pos,val);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

void euler_tour(int node){
	tin[node]=++cnt;
	for(auto &signode : g[node]) euler_tour(signode);
	tout[node]=cnt;
}

void solve(){
	ll n,m,q;
	cin>>n>>m>>q;
	ll root;
	fore(i,1,n+1){
		ll x;
		cin>>x;
		if (x==0){
			root = i;
			continue;
		}
		g[x].pb(i);
	}
	
	euler_tour(root);
	
	STree st(n);
	
	while(m--){
		ll t,e,v;
		cin>>t>>e>>v;
		if (t == 1){
			p[e] += v;
		}
		else{
			st.upd(tin[e],v);
		}
	}
	
	fore(i,1,n+1){
		ll ret = st.query(tin[i],tout[i]) + p[i];
		res[tin[i]] = ret;
	}
	
	fore(i,1,n+1) res[i] += res[i-1];
	
	while(q--){
		ll t,e;
		cin>>t>>e;
		if (t == 1){
			cout<<res[tin[e]] - res[tin[e] - 1]<<nl;
		}
		else{
			cout<<res[tout[e]] - res[tin[e] - 1]<<nl;
		}
	}
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}