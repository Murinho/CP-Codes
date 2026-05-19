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

static inline const ll maxn = 2e5+10;
static inline const ll mod = 1e9+7;
static inline const ll maxp = 20;

vector <pii> pd[maxn]; // prime decomposition per number
ll f[maxn]; // frecuencia de valores de arreglo del input
ll n;
ll a[maxn]; // arreglo input
ll ff[maxn]; // cantidad de numeros que sirven para el base set de un GCD
ll fm[maxn]; // cantidad de numeros que son multiplos de i
bool c[maxn];
vi myprimes[maxn];
ll res[maxn];
ll pwr[maxp];

static inline void precalc(){
	pwr[0] = 1;
	fore(i,1,maxp) pwr[i] = (pwr[i-1] * 2ll);
}

static inline ll bp(ll x, ll pw){
	ll ret = 1;
	while(pw>0){
		if (pw&1) ret = (ret*x)%mod;
		x = (x*x)%mod;
		pw >>= 1ll;
	}
	return ret;
}

static inline void sieve(){
	fore(i,2,n+1){
		if (!c[i]){
 			for(int j = 1; i*j <= n; j++){
				c[i*j] = true;
				if (f[i*j]){
					myprimes[i*j].eb(i);
					fm[i] += f[i*j];
				}
			}
		}
		else{
			for(int j = 1; i*j <= n; j++){
				fm[i] += f[i*j];
			}
		}
	}
}

static inline void prime_decomp(){
	fore(i,2,n+1){
		if (f[i] == 0) continue;
		
		ll num = i;
		for(auto &prime : myprimes[i]){
			ll cnt = 0;
			while(num%prime == 0){
				cnt++;
				num /= prime;
			}
			pd[i].eb(prime,cnt);
		}
		
		// now using the prime decomp compute the masks
		ll tam = sz(pd[i]);
		fore(j,1,pwr[tam]){
			ll num = 1;
			fore(k,0,tam){
				if (pwr[k]&j){
					num *= bp(pd[i][k].f,pd[i][k].s);
				}
			}
			ff[num] += f[i];
		}
	}
}

int main(){
    fast;
    cin >> n;
    precalc();
    fore(i,1,n+1){
    	cin >> a[i];
    	f[a[i]]++;
    }
    
    sieve();
    prime_decomp();
    
    ll sum = 0;
    fore(i,2,n+1){
    	if (ff[i] == 0) res[i] = 0;
    	else{
    		// los numeros que sirven como base * los numeros que son multiplos
    		res[i] = (((bp(2,ff[i]) - 1 + mod)%mod) * bp(2,fm[i] - ff[i]))%mod;
    	}
    	sum += res[i];
    	sum %= mod;
    }
    
    res[1] = ((bp(2,n) - 1ll + mod)%mod - sum + mod)%mod;
    
    fore(i,1,n+1) cout << res[i] << " ";
    cout << nl;
    
    return 0;
}