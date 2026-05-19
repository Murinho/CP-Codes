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

const int maxn = 5e5+5;
const int block_size = 280;

int n,q,bb[maxn],bl[maxn],br[maxn],mxb[maxn],a[maxn];
unordered_map <int,int> mp[maxn]; // cada bloque tiene su propio mapa. Key = nivel_dragon, Valor = padre del UF.

struct UF{
	int pad,ran,val;
};

UF uf[maxn];

int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

void join(int u, int v){
	u = bus(u);
	v = bus(v);
	
	if (u == v) return;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	uf[v].pad = u;
	
	return;
}

void mp_init(int &l, int &r){
	int dad;
	for (int i = l; i<=r; i++){
		dad = mp[bb[i]][a[i]];
		if (dad == 0){
			mp[bb[i]][a[i]] = i;
		}
		else{
			join(dad,i);
			mp[bb[i]][a[i]] = uf[i].pad;
		}
	}
}

void uf_init(int &l, int &r){
	for(int i = l; i<=r; i++){
		uf[i].pad = i;
		uf[i].ran = 0;
		uf[i].val = a[i];
	}
}

void get_max(int &l, int r, int &ans){
	for(int i = l; i<=r; i++){
		ans = max(uf[bus(i)].val,ans);
	}
	return;
}

void rebuild(int &l, int r, int &target_x){
	int bid = bb[l];
	int l_block = bl[bid];
	int r_block = br[bid];
	for(int i = l_block; i<=r_block; i++){
		a[i] = uf[bus(i)].val;
		mp[bid][a[i]] = 0;
		if (l <= i && i <= r && a[i] == target_x){
			a[i]++;
			mxb[bid] = max(mxb[bid],a[i]);
		}
		mp[bid][a[i]] = 0;
	}
	
	uf_init(l_block, r_block);
	mp_init(l_block, r_block);
}

int main(){
    fast;
    cin >> n >> q;
    
    // construir bloques:
    fore(i,1,n+1){
    	bb[i] = (i/block_size);
    	if (bl[bb[i]] == 0) bl[bb[i]] = i;
    	br[bb[i]] = i;
    }
    
    int start = 1;
    // construir union find:
    uf_init(start,n);
    
    // construir los maps:
    mp_init(start,n);
    
    int t,l,r,x;
    while(q--){
    	cin >> t >> l >> r;
    	if (t == 1){
    		cin >> x;
    		// hacer las updates:
    		rebuild(l,min(r,br[bb[l]]),x);
    		for(int i = bb[l]+1; i <= bb[r]-1; i++){
    			int dad = mp[i][x];
    			if (dad == 0) continue;
    			
    			if (mp[i][x+1] > 0){ // si existe el siguiente valor, unir con ellos.
    				join(dad,mp[i][x+1]);
    				int new_dad = uf[bus(dad)].pad;
    				mp[i][x+1] = new_dad;
    				uf[new_dad].val = x+1;
    			}
    			else{ // no existe
    				uf[dad].val = x+1;
    				mp[i][x+1] = dad;
    			}
    			mxb[i] = max(mxb[i],x+1);
    			mp[i][x] = 0;
    		}
    		if (bb[l] != bb[r]){
    			rebuild(bl[bb[r]],r,x);
    		}
    	}
    	else{
    		// encontrar el maximo:
    		int ans = 0;
    		get_max(l,min(r,br[bb[l]]),ans);

    		for(int i = bb[l]+1; i<=bb[r]-1; i++){
    			ans = max(ans,mxb[i]);
    		}
    		
    		if (bb[l] != bb[r]){
    			get_max(bl[bb[r]],r,ans);
    		}
    		cout << ans << nl;
    	}
    }
    return 0;
}