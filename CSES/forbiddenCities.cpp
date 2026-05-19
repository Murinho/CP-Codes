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
 
using namespace std;

const ll maxn = 1e5+100;

struct dsu_save {
	int v, rnkv, u, rnku;
		
	dsu_save() {}
	dsu_save(int v, int rnkv, int u, int rnku)
		: v(v), rnkv(rnkv), u(u), rnku(rnku) {}
};

struct dsu_with_rollbacks {
	vi p, rnk;
	int comps;
	stack<dsu_save> op;

	dsu_with_rollbacks() {}
	dsu_with_rollbacks(int n) {
		p.resize(n);
		rnk.resize(n);
		fore(i,0,n){
			p[i] = i;
			rnk[i] = 0;
		}
		comps = n;
	}

	int find_set(int v){
		return (v == p[v]) ? v : find_set(p[v]);
	}
	bool unite(int v, int u){
		v = find_set(v);
		u = find_set(u);
		if (v == u) return false;
		comps--;
		if (rnk[v] > rnk[u]) swap(v, u);
		op.push(dsu_save(v, rnk[v], u, rnk[u]));
		p[v] = u;
		if (rnk[u] == rnk[v]) rnk[u]++;
		return true;
	}
	void rollback(){
		if (op.empty()) return;
		dsu_save x = op.top();
		op.pop();
		comps++;
		p[x.v] = x.v;
		rnk[x.v] = x.rnkv;
		p[x.u] = x.u;
		rnk[x.u] = x.rnku;
	}
};

struct query {
	int v, u;
	bool united;
	query(int _v, int _u) : v(_v), u(_u) {}
};

struct askQuery{
	ll u,v,id; // u y v son los nodos que queremos checar si estan conectados y id de la query.
};

vector <askQuery> askedQueries[maxn];
bool ans[maxn];

struct QueryTree {
	vector<vector<query>> t;
	dsu_with_rollbacks dsu;
	int T;

	QueryTree() {}
	QueryTree(int T, int n) : T(T) {
		dsu = dsu_with_rollbacks(n);
		t.resize(4 * T + 4);
	}

	void add_to_tree(int v, int l, int r, int ul, int ur, query& q) {
		if (ul > ur)
			return;
		if (l == ul && r == ur) {
			t[v].pb(q);
			return;
		}
		int mid = (l+r)/2;
		add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
		add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
	}
	void add_query(query q, int l, int r) {
		add_to_tree(1, 0, T - 1, l, r, q);
	}
	void dfs(int v, int l, int r) {
		for (query& q : t[v]) {
				q.united = dsu.unite(q.v, q.u);
		}
		if (l == r){ // 
			for(auto &aq : askedQueries[l]){
				if (dsu.find_set(aq.u) == dsu.find_set(aq.v)) ans[aq.id] = true;
				else ans[aq.id] = false;
			}
		}
		else {
				int mid = (l + r) / 2;
				dfs(2 * v, l, mid);
				dfs(2 * v + 1, mid + 1, r);
		}
		for (query q : t[v]) {
			if (q.united) dsu.rollback();
		}
	}
	void solve() {
		dfs(1, 0, T - 1);
		return;
	}
};

ll n,m,q;
vi g[maxn];


int main(){
	fast;
	cin >> n >> m >> q;
	QueryTree qt(n+1,n+1);
	fore(i,0,m){
		ll x,y;
		cin >> x >> y;
		x--, y--;
		if (x > y) swap(x,y);
		
		query edge(x,y);
		
		if (0 < x) qt.add_query(edge,0,x-1);
		if (x+1 < y) qt.add_query(edge,x+1,y-1);
		if (y+1 < n) qt.add_query(edge,y+1,n-1);
	}
	
	fore(i,0,q){
		ll x,y,z;
		cin >> x >> y >> z;
		x--, y--, z--;
		if (x == z || y == z){
			ans[i] = false;
		}
		else{
			askedQueries[z].pb({x,y,i});
		}
	}
	
	qt.solve();
	
	// print answer:
	fore(i,0,q) cout << (ans[i] ? "YES" : "NO") << nl;
	
	return 0;
}