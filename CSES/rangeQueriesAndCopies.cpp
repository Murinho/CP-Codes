#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>s
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#pragma GCC target("popcnt")
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 2e5+100;
ll a[maxn];

struct Vertex {
    Vertex *l, *r;
    ll sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr) return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

ll get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm)) + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

// creates new nodes on the path of the updated position.
Vertex* update(Vertex* v, int tl, int tr, int pos, ll new_val){ 
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

Vertex* create_copy(Vertex* v){ //creates copy of the whole segment tree
	return new Vertex(v->l,v->r);
}

vector<Vertex*> roots;

int main(){
    fast;
	ll n,q;
	cin>>n>>q;
	fore(i,1,n+1) cin>>a[i];
	
	Vertex* froot = build(1,n);
	roots.pb(froot);
	while(q--){
		ll t,k,l,r,x;
		cin>>t>>k;
		k--;
		if (t == 1){
			cin>>l>>x;
			roots[k] = update(roots[k],1,n,l,x);
		}
		else if (t == 2){
			cin>>l>>r;
			ll ret = get_sum(roots[k],1,n,l,r);
			cout<<ret<<nl;
		}
		else if (t == 3){
			Vertex *nroot = create_copy(roots[k]);
			roots.pb(nroot);
		}
	}
	return 0;
}