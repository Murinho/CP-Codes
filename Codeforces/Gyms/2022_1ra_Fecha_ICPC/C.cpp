// Problem: C. Candies median
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103708/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
#define fore(i,a,b) for(int i=a;i<b;++i)
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

const int maxn = 5e5+100;
const ll inf = 1e18;

struct Upd{
	ll l,r,x;
};

ll n,q;
ll a[maxn];
Upd ups[maxn];
map <ll,ll> mp;
ll pref[maxn];


void compress(vi &uni){ // these are the boundaries.
	mp.clear();
	sort(ALL(uni));
	uni.erase(unique(ALL(uni)),uni.end());
	
	fore(i,0,sz(uni)){
		mp[uni[i]] = i; // real to mapped.
		pref[i] = 0;
	}	
}

ll get_kth(vi &uni, ll k){
	fore(i,0,sz(uni)-1){
		ll dif = uni[i+1] - uni[i];
		ll val = pref[i];
		ll elms = dif * val;
		if (k <= elms){ // we found the interval where this is at.
			ll sta = uni[i];
			ll pos = (k/val) + ((k%val) ? 1 : 0);
			return sta + pos - 1;
		}
		k -= elms;
	}
	return inf; // should never happen.
}

void solve_query(){
	ll k,sum = 0;
	cin >> k;
	vi uni;
	fore(i,0,k){
		cin >> ups[i].l >> ups[i].r >> ups[i].x;
		ups[i].r++;
		uni.pb(ups[i].l), uni.pb(ups[i].r);
	}
	
	compress(uni);
	
	for(int i = 0; i<k; i++){
		int ml = mp[ups[i].l];
		int mr = mp[ups[i].r];
		pref[ml] += ups[i].x;
		pref[mr] -= ups[i].x;
		sum += ups[i].x * (ups[i].r - ups[i].l);
	}
	
	fore(i,1,sz(uni)) pref[i] += pref[i-1];
	
	ll mid1 = (sum/2) + (sum%2);
	ll mid2 = ((sum+1)/2) + ((sum+1)%2);
	
	ll lwb = get_kth(uni, mid1);
	ll upb = get_kth(uni, mid2);
	
	cout << fixed << setprecision(1) << (a[lwb] + a[upb])/2.0 << nl;
	return;
}

int main(){
    fast;
    cin >> n >> q;
	fore(i,1,n+1) cin >> a[i];
	
	while(q--){
		solve_query();
	}
}