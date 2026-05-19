// Problem: C. Candy Rush
// Contest: Codeforces - 2023-2024 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/104736/problem/C
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll mod = 10000000000061; // 10^13
const ll b = 400032; // ~4*10^5
const ll maxn = 4e5+10;

map <ll,ll> mp; // key: hash, value: first position where it appears.

ll n,k,a[maxn],f[maxn],p[maxn];
ll h=0,ans=0,zeros=0;

void precalc(){ // precalculate the powers.
	p[0] = 1;
	fore(i,1,maxn) p[i] = (p[i-1] * b)%mod;
}

void init(){
	zeros = k;
}

void substract_all(){
	zeros = 0;
	fore(i,1,k+1){
		f[i]--;
		if (f[i] == 0) zeros++;
	}
}

void apply(ll x){ // add a new element to the frequencies

	ll aux = (p[x] * f[x])%mod; // remove the old hash part
	
	h -= aux;
	h += mod;
	h %= mod;
	
	if (f[x] == 0) zeros--;
	f[x]++;
	
	ll aux2 = (p[x] * f[x])%mod; // add the new hash part
	
	h += aux2;
	h %= mod;
}

void calc_hash(){
	h = 0;
	fore(i,1,k+1){
		
		ll aux = (p[i] * f[i])%mod;
		h += aux;
		h %= mod;
	}
}

void print_freqs(){
	fore(i,1,k+1) cout << f[i] << " ";
	cout << nl;
}

int main(){
    fast;
    cin >> n >> k;
    precalc();
    init();
    fore(i,1,n+1) cin >> a[i];
    if (n < k){
    	cout << 0 << nl;
    	return 0;
    }
    
    mp[0] = 0;
    fore(i,1,n+1){
    	apply(a[i]);
    	if (zeros == 0){
    		substract_all();
    		calc_hash();
    		//cout << i << ": redo " << nl;
    	}
    	
    	//cout << i << ": ";
    	//print_freqs();
    	
    	if (mp.count(h)){
    		ans = max(ans,i-mp[h]);
    	}
    	else{
    		mp[h] = i;
    	}
    }
    
    cout << ans << nl;
    return 0;
}