// Problem: A. Catch the Plane
// Contest: Codeforces - 2018 ACM-ICPC World Finals
// URL: https://codeforces.com/gym/102482/problem/A
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

using namespace std;

const ll maxn = 1e6+100;
const ll stnode = 0;
const ll enode = 1;
const ld eps = 1e-7;

struct Route{
	int n1,n2;
	ll ta,tb;
	ld p,val;
	
	bool operator <(const Route &r) const {
		if (n1 != r.n1) return n1 < r.n1;
		return ta < r.ta;
	}
};

ll n,m,k;
ld ans=0.0;

int main(){
    fast;
   	cin >> m >> n >> k;
   	vector <Route> v(m+1);
   	fore(i,0,m){
   		cin >> v[i].n1 >> v[i].n2 >> v[i].ta >> v[i].tb >> v[i].p;
   		v[i].val = 0.0;
   	}
   	
   	v[m].n1 = 1;
   	v[m].ta = k+1;
   	v[m].val = 1.0;
   	
   	sort(ALL(v));
   	
   	vector <pii> ord(m+1);
   	fore(i,0,m+1) ord[i] = {-v[i].ta, -i};
   	sort(ALL(ord));
   	
   	fore(i,0,m+1){
   		if (-ord[i].fst <= k){
   			int idx = -ord[i].snd;
   			Route &r = v[idx];
   			r.val = 0.0;
   			Route r2;
   			
   			r2.n1 = r.n1;
   			r2.ta = r.ta;
   			
   			auto it = upper_bound(ALL(v),r2);
   			
   			if (it != v.end() && it->n1 == r.n1){
   				r.val += (1.0-r.p) * it->val; // miss route
   			} 
   			
   			r2.n1 = r.n2;
   			r2.ta = r.tb;
   			
   			it = upper_bound(ALL(v),r2);
   			
   			if (it != v.end() && it->n1 == r.n2){
   				r.val += r.p * it->val; // catch route
   			}
   			
   			if (idx < m && v[idx+1].n1 == v[idx].n1){
   				r.val = max(r.val, v[idx+1].val); // don't try route at all
   			}
   			
   			if (r.n1 == 0) ans = max(ans,r.val);
   		}
   	}
   	
   	cout << fixed << setprecision(8) << ans << nl;
   	
   	return 0;
}