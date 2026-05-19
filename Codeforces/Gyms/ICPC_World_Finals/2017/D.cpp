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

struct Ev{
	ll type,price,day;
};

ll n,m,ans=0;
vector <pii> a; // non increasing starts 
vector <Ev> e; // type0: starts, type1: ends.

bool cmp(Ev &e1, Ev &e2){
	if (e1.day == e2.day) return e1.type < e2.type;
	return e1.day < e2.day;
}

ll f(ll &qcur, ll &ecur, ll i){
	ll ret = (qcur-a[i].fst) * (ecur-a[i].snd);
	return ret;
}

void ts(ll qcur, ll ecur){
	ll l = 0;
	ll r = sz(a)-1;
	while(l+350 < r){
		ll m1 = l + (r-l) / 3;
		ll m2 = r - (r-l) / 3;
		ll f1 = f(qcur,ecur,m1);
		ll f2 = f(qcur,ecur,m2);
		if (f1 < f2) l = m1;
		else r = m2;
	}
	
	for(int i = l; i<=r; i++){
		if (sz(a) <= i) break;
		ll ret = f(qcur,ecur,i);
		ans = max(ans,ret);
	}
	return;
}

ll bs(ll price){
	if (!sz(a)) return -1;
	if (a.back().fst >= price) return -1;
	
	int l = 0;
	int r = sz(a)-1;
	while(l < r){
		ll mid = (l+r)/2;
		if (a[mid].fst < price) r = mid;
		else l = mid+1;
	}
	
	return l;
}

void solve(){
	cin >> n >> m;
	fore(i,0,n){
		ll x,y;
		cin >> x >> y;
		e.pb({0,x,y});
	}
	fore(i,0,m){
		ll x,y;
		cin>>x>>y;
		e.pb({1,x,y});
	}
	
	sort(ALL(e),cmp);
	
	for(auto &[type,price,day] : e){
		//cout << type << ": " << price << " " << day << nl;
		if (type == 0){
			if (!sz(a)){
				a.pb({price,day});
			}
			else if (a.back().fst > price){
				a.pb({price,day});
			}
		}
		else{ // answer the query.
			// find the first profitable price (first price lower to the current price).
			ll l = bs(price);
			if (l != -1) ts(price,day);
		}
	}
	cout << ans << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}