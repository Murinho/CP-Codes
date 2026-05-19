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

const ll maxn = 2e5+100;
const ll mod = 1e9+7;

bool vis[maxn];
ll n,cnt,a[maxn],mxp[maxn];
bool c[maxn];
vi lp[maxn],p;
ll ans = 1;

void sieve(){
	c[1] = false;
	fore(i,2,maxn){
		if (!c[i]){
			p.pb(i);
			lp[i].pb(i);
			for(int j = 2; i*j < maxn; j++){
				c[i*j] = true;
				lp[i*j].pb(i);
			}
		}
	}
}

ll bp(ll x, ll pw){
	ll ret = 1;
	while(pw > 0){
		if (pw&1) ret = (ret*x)%mod;
		x = (x*x)%mod;
		pw >>= 1;
	}
	return ret;
}

void dfs(int i){
	if (vis[i]) return;
	
	vis[i] = true;
	cnt++;
	
	dfs(a[i]);
}

void decomp(ll x){
	for(auto &prime : lp[x]){
		ll y = x;
		ll cnt = 0;
		while(y%prime == 0){
			y /= prime;
			cnt++;
		}
		mxp[prime] = max(mxp[prime],cnt);
	}
}

int main(){
    fast;
    cin >> n;
    sieve();
    fore(i,1,n+1) cin >> a[i];
    
    fore(i,1,n+1){
    	if (!vis[i]){
    		cnt = 0;
    		
    		dfs(i);
    		
    		decomp(cnt);
    	}
    }
    
    for(auto &prime : p){
    	if (mxp[prime] == 0) continue;
    	
    	ans = (ans*bp(prime,mxp[prime]))%mod;
    }
    
    cout << ans << nl;
    return 0;
}