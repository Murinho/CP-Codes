#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

struct STree{
	vector <ll> st; int n;
	STree(int n): st(4*n + 5,0ll), n(n) {}
	
	void upd(int node, int ini, int fin, int pos, ll val){
		if (fin < pos || pos < ini) return;
		if (ini == fin && ini == pos){
			st[node] = max(st[node],val);
			return;
		}
		int mid = (ini+fin)/2;
		upd(2*node,ini,mid,pos,val);
		upd(2*node + 1,mid+1,fin,pos,val);
		st[node] = max(st[2*node],st[2*node + 1]);
	}
	
	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return 0;
		if (l <= ini && fin <= r) return st[node];
		int mid = (ini+fin)/2;
		return max(query(2*node,ini,mid,l,r), query(2*node + 1,mid+1,fin,l,r));
	}
	
	void upd(int pos, ll val){ upd(1,1,n,pos,val);}
	ll query(int l, int r){ return query(1,1,n,l,r);}
};

struct Range{
	ll l,r,c;
};

bool cmp(Range r1, Range r2){
	return r1.r < r2.r;
}


int main(){
    //fast;
    ll n;
	cin>>n;
	vector <Range> a(n);
	vector <ll> uni;
	
	fore(i,0,n) cin>>a[i].l>>a[i].r>>a[i].c, uni.pb(a[i].l), uni.pb(a[i].r);
	
	//do the mapping:
	sort(ALL(uni));
	uni.erase(unique(ALL(uni)),uni.end());
	int cnt = 0;
	map <ll,ll> mp;
	
	for(auto elm : uni){
		cnt++;
		mp[elm] = cnt;
	}
	//create segtree:
	STree st(cnt);
	//process the ranges:
	sort(ALL(a),cmp);
	
	for(auto &ra : a){
		ll pmx = 0;
		//cout<<"cur: "<<ra.l<<" "<<ra.r<<nl;
		if (mp[ra.l] > 1){
			pmx = st.query(1,mp[ra.l]-1);
		}
		st.upd(mp[ra.r],pmx + ra.c);
	}
	cout<<st.query(1,cnt)<<nl;
	return 0;
}