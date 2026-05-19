// Problem: H. Redes
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/H
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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll inf = 1e18;
const pii neut = {-inf,-1};
const ll maxn = 1e5+100;

int mov[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};

struct Point{
    ll x,y,id;
    bool operator < (const Point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct Edge{
	ll p1,p2,cost;
	
	bool operator < (const Edge &other) const {
		return (*this).cost < other.cost;
	}
};

struct STree{
    vector<pii> st; int n;
    STree(int n): st(4*n + 5,neut), n(n) {}

    void upd(int node, int ini, int fin, int pos, pii val){
        if (pos < ini || fin < pos) return;
        if (ini == fin){ st[node] = max(st[node], val); return; }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node+1,mid+1,fin,pos,val);
        st[node] = max(st[2*node],st[2*node+1]);
    }

    pii query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return neut;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return max(query(2*node,ini,mid,l,r),
                   query(2*node+1,mid+1,fin,l,r));
    }

    void upd(int pos, pii val){ upd(1,0,n-1,pos,val); }
    pii query(int l, int r){
        if (l > r) return neut;
        return query(1,0,n-1,l,r);
    }
};

struct UF{
	ll pad,ran;
};

UF uf[maxn];

int bus(int u){
	if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
	return uf[u].pad;
}

bool join(int u, int v){
	u = bus(u);
	v = bus(v);
	
	if (u == v) return false;
	
	if (uf[u].ran < uf[v].ran) swap(u,v);
	
	uf[v].pad = u;
	
	if (uf[u].ran == uf[v].ran) uf[u].ran++;
	
	return true;
}

vector <Edge> edges;
ll n;

void compute(vector <Point> pts, int id){
	vi uni;
	for(auto &au : pts){
		au.x *= mov[id][0];
		au.y *= mov[id][1];
		
		uni.pb(au.y - au.x);
	}
	
	sort(ALL(pts));
	
	sort(ALL(uni));
	uni.erase(unique(ALL(uni)),uni.end());
	
	ll tam = sz(uni);
	
	STree st(tam);
	
	
	for(auto &pt : pts){
		ll pos = lower_bound(ALL(uni),pt.y - pt.x) - uni.begin();
		auto [mx,who] = st.query(0,pos);
		
		if (who != -1){
			ll cost = (pt.x + pt.y - mx);
		
			edges.pb({pt.id,who,cost});
		}
		
		st.upd(pos,{pt.x + pt.y, pt.id});
	}
}

void init(){
	fore(i,0,n+1){
		uf[i].pad = i;
		uf[i].ran = 0;
	}
}

int main(){
    fast;
    cin >> n;
    init();
    vector <Point> pts;
    fore(i,0,n){
    	ll x,y;
    	cin >> x >> y;
    	pts.pb({x,y,i});
    }
    
    fore(i,0,4) compute(pts,i);
    
    fore(i,0,4){
    	for(auto &pt : pts) swap(pt.x,pt.y);
    	compute(pts,i);
    	for(auto &pt : pts) swap(pt.x,pt.y);
    }
    
    // cout << sz(edges) << nl;
//     
    // for(auto &edge : edges){
    	// cout << edge.p1 << " " << edge.p2 << " " << edge.cost << nl;
    // }
    
    ll ans = 0;
    sort(ALL(edges));
    
    ll cnt=0;
    for(auto &edge : edges){
    	if (join(edge.p1,edge.p2)){
    		ans += edge.cost;
    		cnt++;
    		
    		if (cnt == n-1) break;
    	}
    }
    
    cout << ans << nl;
    
    return 0;
}