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

const ll inf = 1e18;
const ll maxf = 87;

ll f[maxf],n;

void precalc(){
	f[0] = 1;
	f[1] = 1;
	fore(i,2,maxf){
		f[i] = f[i-1] + f[i-2];
	}
	return;
}

void solve(){
	cin >> n;
	ll sq = sqrt(n)*2ll;
	// solve: G[k] = (a*F[k-2]) + (b*F[k-1])
	fore(b,1,sq){ // fix b.
		fore(k,2,maxf){ // fix k
			if (f[k-1] > inf/b) break; // check for overflows.
			ll aux = f[k-1]*b;
			if (n <= aux) break;
			ll rem = ((n-aux)%f[k-2]);
			ll a = ((n-aux)/f[k-2]);
			if (rem == 0 && a <= b){
				cout << a << " " << b << nl;
				return;
			}
		}
	}
	cout << "nothing found lol" << nl;
	return;
}

int main(){
	fast;
	ll tc;
	precalc();
	cin >> tc;
	while(tc--){
		solve();
	}
	return 0;
}