// Problem: D. Circular DNA
// Contest: Codeforces - 2019 ICPC World Finals
// URL: https://codeforces.com/gym/102511/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int maxn = 1e6+10;
const int inf = 1e9;

struct Marker{
	char c;
	int val;
};

vector <int> sum[maxn]; // sum of every value.
int sgmp[maxn];

struct STree{
    vector<int> st; int n, typ;
    STree(int n, int typ): st(4*n + 5,0),n(n), typ(typ){}

    void build(int node,int ini,int fin){
        if (ini == fin) { 
            st[node] = sum[typ][ini];
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid); //Left sohn
        build(2*node + 1,mid+1,fin); //Right sohn
        st[node] = min(st[2*node],st[2*node + 1]); //desired operation
        return;
    }
    int query(int node,int ini,int fin,int l,int r){
        if (l <= ini && fin <= r) return st[node]; //Fully in
        if (ini > r || fin < l) return inf; //Fully out
        int mid = (ini+fin)/2;
        return min(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r)); 
    }
    void build(){ build(1,0,n-1);}
    int query(int l, int r){ return query(1,0,n-1,l,r);}
};

vector <STree> trees;
Marker a[maxn];
int n,mp[maxn],best,cut;
set <int> valid;

void doit(int curpos, int add){
	int val = a[curpos].val;
	int l = mp[curpos] + add; // sumarle 1 si es el anterior.
	int r = sz(sum[val])-1;
	if (r == -1) return;
	
	int stpos = sgmp[val]; // posicion del segment tree.
	
	int pref = (l>0 ? sum[val][l-1] : 0ll);
	
	if (l <= r){
		int min_suf = trees[stpos].query(l,r);
		if (min_suf < pref) return;
	}
	
	int min_pref = 0;
	
	if (l>0){
		min_pref = trees[stpos].query(0,l-1);
	}
	
	if (min_pref == pref){
		valid.insert(val);
	}
} 

void solve(){
	cin >> n;
	fore(i,1,n+1){
		cin>>a[i].c>>a[i].val;
		mp[i] = sz(sum[a[i].val]);
		sum[a[i].val].pb((a[i].c == 's' ? +1 : -1));
	}
	
	// Compute the sums:
	fore(i,1,maxn){ 
		if (!sz(sum[i])) continue;
		
		bool ok = true;
		
		fore(j,0,sz(sum[i])){
			sum[i][j] += (j>0 ? sum[i][j-1] : 0);
			if (sum[i][j] < 0) ok = false;
		}
		if (sum[i].back() != 0){ // We guarantee that the remaining sum vectors add up to 0.
			sum[i].clear(), sum[i].resize(0);
		}
		else if (ok){
			valid.insert(i);
		}
	}
	
	cut = 1;
	best = sz(valid);
	
	// Build the segment trees:
	fore(i,1,maxn){
		if (sz(sum[i])){
			STree sgt(sz(sum[i]),i);
			
			sgt.build();
			
			sgmp[i] = sz(trees);
			trees.pb(sgt);
		}
	}
	
	
	for(int i = 2; i<=n; i++){
		if (valid.count(a[i-1].val)) valid.erase(a[i-1].val);
		if (valid.count(a[i].val)) valid.erase(a[i].val);
		
		// Checar anterior:
		doit(i-1, +1);
		doit(i, 0);
		
		if (best < sz(valid)){
			best = sz(valid);
			cut = i;
		}
	}
	
	cout << cut << " " << best << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}