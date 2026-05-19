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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

// componentes conexas.
// greedy, tomar las dos componentes conexas con mas elementos no escogidos.
// matchearlos.

static const ll maxn = 1e5+5;

vi g[maxn];
bool vis[maxn];
int n,m,cnt,id=0;
set <pii> st;
vector <int> ids[maxn];

void inline dfs(int u){
	cnt++;
	ids[id].eb(u);
	vis[u] = true;
	for(auto &v : g[u]){
		if (!vis[v]){
			dfs(v);
		}
	}
}

int main(){
    fast;
    cin >> n >> m;
    fore(i,0,m){
    		ll x,y;
    		cin >> x >> y;
    		g[x].eb(y);
    		g[y].eb(x);
    }
    
    fore(i,0,n){
    		if (!vis[i]){
    			cnt = 0;
    			dfs(i);
    			st.insert({cnt,id});
    			id++;
    		}
    }
    
    int ans = 0;
    ostringstream ost;
    while(sz(st) >= 2){
    		pii bg = *st.rbegin();
    		st.erase(bg);
    		pii bg2 = *st.rbegin();
    		st.erase(bg2);
    		
    		ans++;
    		ost << ids[bg.s].back() << " " << ids[bg2.s].back() << nl;
    		
    		ids[bg.s].ppb(), ids[bg2.s].ppb();
    		
    		bg.f--, bg2.f--;
    		if (bg.f > 0) st.insert(bg);
    		if (bg2.f > 0) st.insert(bg2);
    }
    cout << ans << nl;
    cout << ost.str();
    
    return 0;
}