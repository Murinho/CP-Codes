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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll mod = 1e9+7;
const ll maxn = 515;
const ll maxk = 127800;

ll n,k,p[maxn][maxk];

void sweeprow(int i){
	fore(j,1,k+1){
		p[i][j] += p[i][j-1];
		p[i][j] += mod;
		p[i][j] %= mod;
	}
}

int main(){
    fast;
    cin >> n >> k;
    if (k == 0){
		cout << 1 << nl;
		return 0;
    }
    
    p[0][0] = 1;
	sweeprow(0);

	ll tope = 0;
    
    fore(i,1,n+1){
		fore(j,0,min(tope,k)+1){
			ll qans = p[i-1][j] - ((j-(i-1)) > 0 ? p[i-1][j-(i-1)-1] : 0);
			p[i][j] = (qans + mod)%mod;
		}
		tope += i;
		sweeprow(i);
    }
    
    cout << (p[n][k] - p[n][k-1] + mod)%mod << nl;
    return 0;
}