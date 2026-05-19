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
 
using namespace std;

const ll mod = 1e9+7;

vvi mul(vvi a, vvi b) {
	vvi c(sz(a), vi(sz(b[0])));
	for (int i = 0; i < sz(a); i++) 
		for (int j = 0; j < sz(b); j++)
			for ( int k = 0; k < sz(a); k++) 
				(c[i][j] += a[i][k]*b[k][j]%mod)%=mod; 
	return c;
}

vvi exp( vvi x, ll y) {
	vvi r(sz(x), vi(sz(x)));
	bool flag = false;
	while (y>0){
		if (y&1) {
			if (!flag) r = x, flag = true;
			else r = mul(r,x);
		}
		y=y>>1;
		x = mul(x,x);
	}
	return r;
}

ll n,f[6];

int main(){
    fast;
    cin >> n;
    f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	f[4] = 8;
	f[5] = 16;
	if (n <= 5) cout << f[n] << nl;
	else{
		vvi mat(6);
		mat[0] = {1,1,1,1,1,1}; // multipliers
		mat[1] = {1,0,0,0,0,0};
		mat[2] = {0,1,0,0,0,0};
		mat[3] = {0,0,1,0,0,0};
		mat[4] = {0,0,0,1,0,0};
		mat[5] = {0,0,0,0,1,0};
		
		vi iniv = {f[5],f[4],f[3],f[2],f[1],f[0]};
		
		mat = exp(mat,n-5);
		ll ans = 0;
		fore(i,0,6){
			ll aux = (mat[0][i]*iniv[i])%mod;
			ans = (ans + aux)%mod;
		}
		cout << ans << nl;
	}
	return 0;
}