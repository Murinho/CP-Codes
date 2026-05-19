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

const ll maxn = 1005;
const ll mod = 1e9+7;
const ll maxm = 105;
const ll alpha = 26;

ll z[maxn][alpha][maxn],t[maxm][alpha];
ll dp[maxn][maxm];
ll pot[maxn];

void z_function(ll len, ll las, string &s){
	for (ll i = 1, l = 0, r = 0; i < sz(s); ++i) {
		if (i <= r) z[len][las][i] = min(r - i + 1, z[len][las][i - l]);
		while (i + z[len][las][i] < sz(s) && s[z[len][las][i]] == s[i + z[len][las][i]]) z[len][las][i]++;
		if (i + z[len][las][i] - 1 > r) l = i, r = i + z[len][las][i] - 1;
	}
	
	t[len][las] = 0;
	fore(i,1,sz(s)){
		ll en = i + z[len][las][i];
		if (en == sz(s)){
			t[len][las] = z[len][las][i];
			break;
		}
	}
}

void precalc(){ // precalculate the powers of 26.
	pot[0] = 1;
	fore(i,1,maxn) pot[i] = (pot[i-1] * alpha)%mod;
}

ll n,m;
string s;

int main(){
    fast;
    precalc();
    cin >> n;
    cin >> s;
    m = sz(s);
    
    if (m > n){
    	cout << 0 << nl;
    	return 0;
    }
   	
   	// precalculate the transitions of the dp.
   	string aux = "";
   	fore(i,0,m){
   		aux += ".";
   		fore(j,0,alpha){
   			aux[sz(aux)-1] = (char)(j+'A');
   			z_function(i+1,j,aux);
   		}
   		aux[sz(aux)-1] = s[i];
   	}
   	
   	t[1][(int)s[0]-'A'] = 1;
   	
   	// do the dp
	dp[0][0] = 25;
	dp[0][1] = 1;
	fore(i,0,n-1){
		fore(j,0,m){
			if (dp[i][j] == 0) continue;
			
			fore(k,0,alpha){
				char c = (char)(k+'A');
				if (c == s[j]){ // if there is a direct transition
					dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%mod;
				}
				else{ // go back to the longest streak to complete the substring
					ll nt = t[j+1][k];
					dp[i+1][nt] = (dp[i+1][nt] + dp[i][j])%mod;
				}
			}
		}
	}
	
	ll ans = 0;
	fore(i,0,n){
		if (dp[i][m] > 0){
			ll add = (dp[i][m] * pot[n-i-1])%mod;
			ans = (ans + add)%mod;
		}
	}
	
	cout << ans << nl;
	return 0;
}