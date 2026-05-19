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

struct Event{ // events sweeping in x direction
	ll x,y1,y2,type;
	bool operator<(Event const &other) const { return x < other.x; }
};

vi uniy;

struct STree{
	vi cnt,len; int n;
	
	STree(int n): cnt(4*n + 5,0), len(4*n + 5,0), n(n) {}
	
	void pull(int node, int ini, int fin){
		if (cnt[node] > 0){
			len[node] = uniy[fin+1] - uniy[ini];
		}
		else if (ini == fin){
			len[node] = 0;
		}
		else{
			len[node] = len[2*node] + len[2*node + 1];
		}
	}
	
	void upd(int node, int ini, int fin, int l, int r, int val){
		if (fin < l || r < ini) return;
		if (l <= ini && fin <= r){
			cnt[node] += val;
			pull(node,ini,fin);
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,l,r,val);
		upd(2*node + 1,mid+1,fin,l,r,val);
		pull(node,ini,fin);
	}
	
	void upd(int l, int r, int val){ upd(1,0,n-1,l,r,val); }
	ll covered(){
		return len[1];
	}
};

ll x[maxn],y[maxn],x2[maxn],y2[maxn];
ll ans=0;
vector <Event> e;

int main(){
    fast;
    ll n;
    cin >> n;
    fore(i,1,n+1){
    	cin >> x[i] >> y[i] >> x2[i] >> y2[i];
    	uniy.pb(y[i]);
    	uniy.pb(y2[i]);
    }
	
	sort(ALL(uniy));
	uniy.erase(unique(ALL(uniy)),uniy.end());
	
	fore(i,1,n+1){
		e.pb({x[i],y[i],y2[i],1});
		e.pb({x2[i],y[i],y2[i],-1});
	}
	
	sort(ALL(e));
	
	int k = sz(uniy);
	STree st(k);
	
	// procesar los eventos
	int i = 0;
	ll prev_x = e[0].x;
	while(i < sz(e)){
		ll curx = e[i].x;
		ans += (curx - prev_x) * st.covered();
		
		// apply all events at x
		while (i < (int)e.size() && e[i].x == curx) {
		    int i1 = lower_bound(uniy.begin(), uniy.end(), e[i].y1) - uniy.begin();
		    int i2 = lower_bound(uniy.begin(), uniy.end(), e[i].y2) - uniy.begin();
		    st.upd(i1, i2-1, e[i].type);
		    i++;
		}
		prev_x = curx;
	}
	
	cout << ans << nl;
	return 0;
}