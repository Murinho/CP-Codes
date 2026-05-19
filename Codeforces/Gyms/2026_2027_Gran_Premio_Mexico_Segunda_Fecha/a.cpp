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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


// usar hashing para calcular los prefijos validos.
// un prefijo es valido si no hay ningun otro prefijo el cual sea exactamente igual a un sufijo del prefijo candidato.
// guardar las longitudes de cada prefijo valido.
// despues hacer standard knapsack.

const ll maxn = 2005;
const ll M = 998244353;
const ll B = 131;

ll pws[maxn],h[maxn],dp[maxn];
set <ll> seen;
vector <ll> lens;
string s;
int n,k;

ll conv(char c){ return (c-'a'+1); }

ll getHash(int l1, int len1){
	int r1 = l1 + len1;
	ll h1 = (h[r1]-h[l1]*pws[len1]%M + M)%M;
	return h1;
}

void clean(){
	seen.clear();
	lens.clear();
	fore(i,1,k+1){
		dp[i] = 0;
	}
	dp[0] = 1;
}

void precalc(){
	pws[0] = 1;
	fore(i,1,maxn) pws[i] = (pws[i-1]*B)%M;
}

void computeHashes(){
	h[0] = conv(s[0]);
	fore(i,0,n){
		h[i+1] = ((h[i]*B) + conv(s[i]))%M;
	}
}

bool isValid(int prefend){
	for(int i = prefend; i>=0; i--){
		ll curh = getHash(i,prefend-i+1);
		if (seen.count(curh)){
			return false;
		}
	}
	return true;
}

void solve(){
	cin >> n >> k;
	cin >> s;
	clean();
	computeHashes();
	
	// compute the valid prefixes
	fore(i,0,n){
		if (isValid(i)){
			lens.eb(i+1);
			seen.insert(getHash(0,i+1));
		}
	}
	
	// cout << "Lens: " << nl;
	// for(auto &elm : lens){
		// cout << elm << " ";
	// }
	// cout << nl;
	
	// do knapsack
	fore(i,0,k){
		if (dp[i] == 0) continue;
		for(auto &elm : lens){
			if (i + elm > k) break;
			dp[i+elm] += dp[i];
			dp[i+elm] %= M;
		}
	}
	
	cout << dp[k] << nl;
	return;
}

int main(){
    fast;
    precalc();
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}