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

const ll maxn = 1e5+100;
const ll loga = 17;
const ll inf = 1e9+7;

ll n,q,up[maxn][loga],a[maxn];

void binlift(){
	fore(i,1,loga){
		fore(j,0,n+1) up[j][i] = up[up[j][i-1]][i-1];
	}
}

ll solve(ll vl, ll vr){
	ll ret = 0;
	ll x = vl;
	rofe(i,loga,0){
		if (up[x][i] <= vr){
			ret += (1ll<<i);
			x = up[x][i];
		}
	}
	
	return ret+1;
}

int main(){
	fast;
	cin >> n >> q;
	fore(i,0,n) cin >> a[i];
	
	a[n] = inf;
	
	stack <pii> stk;
	stk.push({a[n],n});
	up[n][0] = n;
	
	rofe(i,n,0){
		while(stk.top().fst <= a[i]) stk.pop();
		
		up[i][0] = stk.top().snd;
		stk.push({a[i],i});
	}
	
	binlift();
	
	while(q--){
		ll l,r;
		cin >> l >> r;
		l--, r--;
		ll ans = solve(l,r);
		cout << ans << nl;
	}
	return 0;
}