// Problem: F. First Problem
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/105873/problem/F
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
 
using namespace std;

const ll maxn = 1e5+100;
const ll block_size = 131;


int n,q;
ll a[maxn];
ll bb[maxn]; // to what block certain position belongs to.
ll bl[maxn],br[maxn]; // the l and the r from each block.
ll lazy[maxn]; // lazy value of sum for each block.
unordered_map <ll,ll> mp[maxn]; // [block]: unique value, dsu representative.

struct UF{
	ll pad,ran,val;
};

UF uf[maxn];

int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

void join(int u, int v, ll &val, ll &bid){
	u = bus(u);
	v = bus(v);
	
	if (u == v) return;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	uf[v].pad = u;
	uf[u].val = val;
	mp[bid][val] = u;
}

ll get_max(int l, int r){ // getting the max in a range.
	ll ans = 0; 
	for(int i = l; i<=r; i++){
		ll aux = uf[bus(i)].val + lazy[bb[i]];
		ans = max(ans,aux);
	}
	return ans;
}

void uf_init(int &l, int &r){
	for(int i = l; i<=r; i++){
		uf[i].pad = i;
		uf[i].ran = 0;
		uf[i].val = a[i];
	}
}

void mp_init(int &l, int &r){
	for(int i = l; i<=r; i++){
		if (!mp[bb[i]].count(a[i])){
			mp[bb[i]][a[i]] = i;
		}
		join(mp[bb[i]][a[i]], i, a[i], bb[i]);
	}
}

void rebuild(int bid, int l_add, int r_add){
	int l_block = bl[bid];
	int r_block = br[bid];
	for(int i = l_block; i<=r_block; i++){
		a[i] = uf[bus(i)].val + lazy[bid];
		if (l_add <= i && i <= r_add){
			a[i]++;
		}
	}
	lazy[bid] = 0; // reiniciar el lazy.
	
	mp[bid].clear();
	
	uf_init(l_block,r_block);
	mp_init(l_block, r_block);
}

void reset_query(int bid, int l_reset, int r_reset, ll mx){
	if (mx == 0) return;
	
	int l_block = bl[bid];
	int r_block = br[bid];
	for(int i = l_block; i<=r_block; i++){
		a[i] = uf[bus(i)].val + lazy[bid];
		if (l_reset <= i && i <= r_reset && a[i] == mx){
			a[i] = 0;
		}
	}
	lazy[bid] = 0; // reiniciar el lazy.
	
	mp[bid].clear();
	
	uf_init(l_block,r_block);
	mp_init(l_block, r_block);
}

int main(){
    fast;
    int start = 1;
    cin >> n >> q;
	fore(i,1,n+1) cin >> a[i];

	// build all the blocks:
	fore(i,1,n+1){
		bb[i] = (i/block_size);
		if (bl[bb[i]] == 0){
			bl[bb[i]] = i; // first element of the block
			lazy[bb[i]] = 0;
		}
		br[bb[i]] = i; // last element of the block
	}
	
	// initialize union find:
	uf_init(start,n);
	
	// build the sets:
	mp_init(start,n);
	
	//fore(i,1,n+1) cout << i << ": " << uf[bus(i)].val << nl;
	
	while(q--){
		char c;
		ll l,r;
		cin >> c >> l >> r;
		if (c == 'Q'){
			ll ans = 0,ret;
			ret = get_max(l,min(br[bb[l]],r)); // prefijo.
			ans = max(ans,ret);
			for(int i = bb[l]+1; i<bb[r]; i++){ //bloques completos.
				ll x = mp[i].rbegin()->fst + lazy[i];
				ans = max(ans,x);
			}
			if (bb[l] != bb[r]){
				ret = get_max(bl[bb[r]],r); //sufijo
				ans = max(ans,ret);
			}
			cout << ans << nl; 
		}
		else if (c == 'A'){
			rebuild(bb[l],l,min(br[bb[l]],r)); // bloque, inicio y fin de la add update.
			
			for(int i = bb[l]+1; i<bb[r]; i++){
				lazy[i]++;
			}
			
			if (bb[l] != bb[r]){
				rebuild(bb[r],bl[bb[r]],r);
			}
		}
		else{ // reconstruir reiniciando.
			ll mx = 0;
			// First get the max of all blocks:
			for(int i = 0; i<=bb[n]; i++){
				mx = max(mx,mp[i].rbegin()->fst + lazy[i]);
			}
			
			reset_query(bb[l],l,min(br[bb[l]],r),mx);
			
			for(ll i = bb[l]+1; i<bb[r] && mx > 0; i++){ //bloques completos.
				ll bg = mp[i].rbegin()->fst;
				ll maxic = bg + lazy[i];
				if (mx == maxic){ // maximums match.
					ll new_val = lazy[i]*(-1);
					ll pad_old = mp[i][bg];
					if (mp[i].count(new_val)){
						join(mp[i][new_val], pad_old, new_val, i);
					}
					else{
						mp[i][new_val] = uf[bus(pad_old)].pad;
						uf[bus(pad_old)].val = new_val;
					}
					mp[i].erase(bg);
				}
			}
			
			if (bb[l] != bb[r]){
				reset_query(bb[r],bl[bb[r]],r,mx);
			}
		}
		
		//fore(i,1,n+1) cout << uf[bus(i)].val + lazy[bb[i]] << " ";
		//cout << nl;
	}
}