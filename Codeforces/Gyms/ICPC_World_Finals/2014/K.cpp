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
 
using namespace std;

const ll maxn = 2e6+100;
const ll inf = 1e9+7;
const ll loga = 21;

ll a[maxn],who[maxn],lb[maxn],rb[maxn],nx[maxn],up[maxn][loga];

struct STree{
	vector<pii> st; int n;
	STree(int n): st(4*n + 5), n(n) {}
	
	void build(int node, int ini, int fin){
		if (ini == fin){
			st[node] = {a[ini],who[ini]};
			return;
		}
		int mid = (ini+fin)/2;
		build(2*node,ini,mid);
		build(2*node + 1,mid+1,fin);
		st[node] = max(st[2*node],st[2*node+1]);
	}
	
	pii query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return {0,0};
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return max(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
	}
	
	void build(){ build(1,0,n-1);}
	pii query(int l, int r){ return query(1,0,n-1,l,r);}
};


ll n,m,pw[loga];

void init(){
	fore(i,0,2*n + 1) a[i] = -1;
	
	pw[0] = 1;
	fore(i,1,loga) pw[i] = (pw[i-1]*2ll);
}

void binlift(){
	for(int i = 1; i<=2*m; i++) up[i][0] = nx[i];
	
	for(int i = 1; i<loga; i++){
		for(int j = 1; j<=2*m; j++) up[j][i] = up[up[j][i-1]][i-1];
	}
}

bool check(int start, int steps){
	if (steps == m+1) return true;
	
	int cur = start;
	
	rofe(i,loga,0){
		if (pw[i] <= steps){
			steps -= pw[i];
			cur = up[cur][i];
		}
	}
	
	if (cur == 0) return true; // llegue al final.
	
	int stpos = lb[start];
	int epos = rb[cur];
	int tot = epos - stpos + 1;
	
	if (n <= tot) return true; // recorri igual o mas que n posiciones.
	
	return false;
}

int main(){
	fast;
	cin >> n >> m;
	init();
	bool ok = false;
	fore(i,1,m+1){
		cin >> lb[i] >> rb[i];
		
		lb[i]--, rb[i]--;
		
		lb[i+m] = lb[i] + n;
		rb[i+m] = rb[i] + n;
		
		// Cuando la respuesta puede ser = 1.
		if (lb[i] == 0 && rb[i] == n-1) ok = true;
		if (rb[i]+1 == lb[i]) ok = true;
		
		if (lb[i] > rb[i]){
			rb[i] += n;
			rb[i+m] += n;
		}
		
		ll l = lb[i];
		ll r = rb[i];

		// Checar si es el mejor rango empezando en l.
		if (a[l] < r){
			a[l] = r;
			who[l] = i;
		}
		
		// Ahora offset. Checar si es el mejor rango empezando en l.
		l += n;
		r += n;
		if (a[l] < r){
			a[l] = r;
			who[l] = i+m;
		}
	}
	
	if (ok){
		cout << 1 << nl;
		return 0;
	}
	
	STree st(2*n);
	st.build(); 
	
	// Calcular el siguiente rango mas alcanzable.
	
	for(int i = 1; i<=2*m; i++){
		if (2*n - 1 <= rb[i]){ // se llego al final.
			nx[i] = 0;
		}
		else{
			pii res = st.query(lb[i],rb[i]+1);
			nx[i] = res.snd;
			
			if (nx[i] == 0) nx[i] = i;
		}
	}
	
	binlift();
	
	ll ans = inf;
	
	// for each node find the closest to give a full lap:
	fore(i,1,m+1){
		if (nx[i] == i) continue;
		ll l = 1;
		ll r = m+1;
		while(l < r){
			ll mid = (l+r)/2;
			if (check(i,mid)) r = mid;
			else l = mid+1;
		}
		
		ans = min(ans,l);
	}
	
	if (ans <= m) cout << ans+1 << nl;
	else cout << "impossible" << nl;
	return 0;
}