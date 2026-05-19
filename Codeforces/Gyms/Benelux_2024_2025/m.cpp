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

const ll maxn = 2e5+100;
const ll inf = 1e16;
const ll neut = inf;

struct STree{
	vi st,lzset;
	int n;
	STree(int n): st(4*n + 5,neut), lzset(4*n + 5,neut), n(n){}
	
	void assign(int node, int ini, int fin, ll val){
		lzset[node] = min(lzset[node],val);
		st[node] = min(st[node],val);
	}
	
	void push(int node, int ini, int fin){
		int mid = (ini+fin)/2;
        if (lzset[node] != neut){
            assign(2*node,ini,mid,lzset[node]);
            assign(2*node + 1,mid+1,fin,lzset[node]);
            lzset[node] = neut;
        }
	}
	
	void setUpdate(int node, int ini, int fin, int l, int r, ll val){
        if (fin < l || r < ini) return;
        if (l <= ini && fin <= r){
            assign(node,ini,fin,val);
            return;
        }
        push(node,ini,fin);
        ll mid = (ini+fin)/2;
        setUpdate(2*node,ini,mid,l,r,val);
        setUpdate(2*node + 1,mid+1,fin,l,r,val);
        st[node] = min(st[2*node],st[2*node + 1]);
    }
    
    ll query(int node, int ini, int fin, int l, int r){
    	if (fin < l || r < ini) return neut;
        if (l <= ini && fin <= r){
            return st[node];
        }
        push(node,ini,fin);
        int mid = (ini+fin)/2;
        ll lmin = query(2*node,ini,mid,l,r);
        ll rmin = query(2*node + 1,mid+1,fin,l,r);
        st[node] = min(st[2*node],st[2*node + 1]);
        return min(lmin,rmin);
    }
    
    void setUpdate(int l, int r, ll val){ setUpdate(1,1,n,l,r,val);}
    ll query(int pos){ return query(1,1,n,pos,pos);}
};

ll n,m,a[maxn];

struct Ival{
	ll l,r;
};

vector <Ival> ivals;
vi tin[maxn],tout[maxn];
	
void init(){
	ivals.clear(), ivals.resize(m+1);
}

bool cmp(Ival iv1, Ival iv2){
	if (iv1.l == iv2.l){
		return iv1.r < iv2.r;
	}
	return iv1.l < iv2.l;
}

int main(){
    fast;
	cin>>n>>m;
	init();
	fore(i,1,n+1) cin>>a[i];
	
	fore(i,1,m+1){
		cin>>ivals[i].l>>ivals[i].r;
	}
	
	sort(ALL(ivals),cmp);
	
	fore(i,1,sz(ivals)){
		tin[ivals[i].l].pb(i); //tiempo de entrada.
		tout[ivals[i].r].pb(i); //tiempo de salida [inclusivo].
	}
	
	STree sgt(m);
	
	set <ll> st; //active intervals tending to the suffix with no gaps to the left.
	
	fore(i,1,n+1){
		// process the arriving intervals:
		for(auto &id : tin[i]) st.insert(id);
		
		if (sz(st)){
			ll sm = *st.begin() - 1; //first element to the left that doesn't occur in the set.
			ll dpval = (sm > 0 ? sgt.query(sm) : 0);
			ll cur_cost = dpval + a[i];
			
			ll bg = *st.rbegin();
			sgt.setUpdate(sm+1,bg,cur_cost); // update with min(cur_cost,st[j])
		}
		
		for(auto &id : tout[i]){
			while(sz(st) && *st.begin() <= id){
				st.erase(*st.begin());
			}
		}
	}
	
	cout<<sgt.query(m)<<nl;
	return 0;
}