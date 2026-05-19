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

const ll maxn = 1e5+100;

ll a[maxn],b[maxn],l[maxn],r[maxn];
ll mppre[maxn],mpin[maxn];
ll n;

void dfs(int node){
	if (l[node] > 0) dfs(l[node]);
	if (r[node] > 0) dfs(r[node]);
	cout << node << " ";
}

int cnt = 2;

void build_tree(int node, int ini, int fin){
	//cout << node << " " << ini << " " << fin << nl;
	
	if (mpin[a[cnt]] < ini || fin < mpin[a[cnt]] || ini >= fin) return;
	
	if (cnt <= n && mpin[a[cnt]] < mpin[node]){ // go left
		cnt++;
		l[node] = a[cnt-1];
		build_tree(a[cnt-1],ini,mpin[node]-1);
	}
	
	if (mpin[a[cnt]] < ini || fin < mpin[a[cnt]] || ini >= fin) return;
	
	if (cnt <= n && mpin[a[cnt]] > mpin[node]){ // go right
		cnt++;
		r[node] = a[cnt-1];
		build_tree(a[cnt-1],mpin[node]+1,fin);
	}
}


int main(){
    fast;
   	cin >> n;
   	fore(i,1,n+1){
   		cin >> a[i];
   		mppre[a[i]] = i;
   	}
   	
   	fore(i,1,n+1){
   		cin >> b[i];
   		mpin[b[i]] = i;
   	}
   	
   	build_tree(a[1],1,n);
   	
   	//cout << "-------- " << nl;
   	//fore(i,1,n+1) cout << i << " " << l[i] << " " << r[i] << nl;
   	
   	dfs(a[1]);
   	
   	cout << nl;
}