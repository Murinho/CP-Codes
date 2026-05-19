// Problem: J. JuPaels Palindrome
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/105873/problem/J
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e6+100;
const int alpha = 26;
const int tope = 1<<26;
int a[tope],pw[alpha];
int n,ans=1;
char s[maxn];


void solve(){
	fore(i,0,tope) a[i] = 0;
	pw[0] = 1;
	fore(i,1,alpha) pw[i] = (pw[i-1]*2);
	
	cin >> n;
	fore(i,1,n+1) cin >> s[i];
	
	ll val = 0;
	fore(i,1,n+1){
		val ^= pw[s[i]-'a'];
		if (val == 0) ans = max(ans,i);
		else if (a[val] > 0) ans = max(ans,i-a[val]);
		else a[val] = i;
		
		fore(j,0,26){
			ll aux = val^pw[j];
			//cout << "Checking: "<<aux<<nl;
			if (aux == 0) ans = max(ans,i);
			else if (a[aux] > 0) ans = max(ans,i-a[aux]);
		}
		
		//cout << val << " " << ans << nl;
	}
	cout << ans << nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}