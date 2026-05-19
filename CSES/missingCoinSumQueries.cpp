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


const ll maxn = 2e5+100;
const ll loga = 30;
const ll inf = 1e9+100;

ll st[maxn*4][loga],a[maxn],n,q;
ll p[loga+1];
ll s[maxn][loga];

void build(int node, int ini, int fin){
	if (ini == fin){
		st[node][63 - __builtin_clzll(a[ini])] = a[ini];
		return;
	}
	int mid = (ini+fin)/2;
	build(2*node,ini,mid);
	build(2*node + 1,mid+1,fin);
	fore(i,0,loga) st[node][i] = min(st[2*node][i], st[2*node + 1][i]);
}

void query(int node, int ini, int fin, int l, int r, vi &res){
	if (fin < l || r < ini) return;
	if (l <= ini && fin <= r){
		fore(i,0,loga) res[i] = min(res[i],st[node][i]);
		return;
	}
	int mid = (ini+fin)/2;
	query(2*node,ini,mid,l,r,res);
	query(2*node + 1,mid+1,fin,l,r,res);
}

void init(){
	memset(st, inf, sizeof(st));
	p[0] = 1;
	fore(i,1,loga+1) p[i] = (p[i-1] * 2ll);
}

int main(){
    fast;
    cin >> n >> q;
    init();
    fore(i,1,n+1){
    	 cin >> a[i];
    	 s[i][63 - __builtin_clzll(a[i])] += a[i];
    }
    
    build(1,1,n);
    
    // sweep the prefix sums:
    fore(i,0,loga){
    	fore(j,1,n+1) s[j][i] += s[j-1][i];
    }
    
    // process the queries
    while(q--){
    	ll l,r,sum=0;
    	cin >> l >> r;
    	vi res(loga,inf);
    	query(1,1,n,l,r,res);

    	fore(i,0,loga){
    		if (sum >= p[i+1] - 1) sum += s[r][i] - s[l-1][i];
    		else{
    			if (res[i] <= sum+1) sum += s[r][i] - s[l-1][i];
    			else break;
    		}
    	}
		cout << sum + 1 << nl;
    }
    return 0;
}