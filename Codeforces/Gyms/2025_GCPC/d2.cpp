// Problem: D. Find the Last Number
// Contest: Codeforces - Codeforces Round 1061 (Div. 2)
// URL: https://codeforces.com/contest/2156/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const ll maxn = 1e5+10;
const ll loga = 17;

ll n;
bool a[maxn],c[maxn];
ll b[maxn];

ll ask(ll pos, ll x){
	cout << "? " << pos << " " << x << nl;
	cout.flush();
	ll res;
	cin >> res;
	return res;
}

void respond(ll x){
	cout << "! " << x << nl;
	cout.flush();
	return;
}

void init(){
	fore(i,1,n+1) a[i] = c[i] = true;
}

void solve(){
	cin >> n;
	init();
	
	ll cur = 0;
	ll pw = 1;
	while(1){
		if (cur + pw > n) break;

		// calcular cuantos deberian existir.
		ll cnt = 0;
		fore(i,1,n+1){
			if ((i&pw) && c[i]) cnt++;
		}
		
		// calcular cuantos realmente existen.
		ll cnt2 = 0;
		fore(i,1,n){
			if (a[i]){
				b[i] = ask(i,pw);
				if (b[i] == 1) cnt2++;
			}
		}
		
		//cout << cnt << " " << cnt2 << nl;
		if (cnt == cnt2){ // todos estan, entonces no.
			fore(i,1,n){
				if (a[i] && b[i] == 1){
					a[i] = false;
					//cout << i << ": falso" << nl;
				}
			}
			fore(i,1,n+1){
				if ((i&pw)) c[i] = false;
			}
		}
		else{ // alguno no esta.
			cur += pw;
			fore(i,1,n){
				if (a[i] && b[i] == 0){
					//cout << i << ": falso" << nl;
					a[i] = false;
				}
			}
			fore(i,1,n+1){
				if (!(i&pw)) c[i] = false;
			}
		}
		
		pw *= 2ll;
	}
	respond(cur);
	return;
}

int main(){
    //fast;
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}