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

const ll maxn = 2e5+100;

struct UF{
	ll pad,ran,mx;
};

UF uf[maxn];

ll bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

void join(int u, int v){
	u = bus(u);
	v = bus(v);
	
	if (u == v) return;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	uf[v].pad = u;
	uf[u].mx = max(uf[u].mx, uf[v].mx);
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	return;
}

void update_max(ll u, ll val){
	u = bus(u);
	uf[u].mx = max(uf[u].mx,val);
}

ll n,b[maxn];

void init(){
	fore(i,0,n+2){
		uf[i].pad = i;
		uf[i].ran = 0;
		uf[i].mx = 0;
	}
}

void solve(){
	cin >> n;
	init();
	vector <pii> a(n);
	fore(i,1,n+1){
		cin >> b[i];
		a[i-1].fst = b[i];
		a[i-1].snd = i;
	}
	
	sort(ALL(a));
	
	for(int i = 0; i<n; i++){
		int pos = i;
		while(pos < n && a[pos].fst == a[i].fst) pos++;
		
		// update shit.
		fore(j,i,pos){
			ll res = 0;
			ll id = a[j].snd;
			if (id > 1 && b[id-1] < b[id]) res = max(res,uf[bus(id-1)].mx);
			if (id+1 <= n && b[id] > b[id+1]) res = max(res,uf[bus(id+1)].mx);
			
			update_max(id,res+1);
		}
		// join shit.
		fore(j,i,pos){
			ll id = a[j].snd;
			if (id > 1 && b[id-1] <= b[id]) join(id-1,id);
			if (id+1 <= n && b[id] >= b[id+1]) join(id,id+1);
		}
		
		i = pos-1;
	}
	
	ll ans = 0;
	
	fore(i,1,n+1){
		ans = max(ans,uf[bus(1)].mx);
	}
	
	cout << ans << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}