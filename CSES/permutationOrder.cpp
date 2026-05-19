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

const ll maxn = 21;

ll n,k,a[maxn],t;
ll f[maxn];
bool mk[maxn];

void precalc(){
	f[0] = 1;
	fore(i,1,maxn) f[i] = (f[i-1]*i);
}

void init(){
	fore(i,0,maxn){
		mk[i] = false;
		a[i] = 0;
	}
}

void solve(){
	init();
	cin >> t;
	if (t == 1){
		cin >> n >> k;
		fore(i,1,n+1){
			fore(j,1,n+1){
				if (mk[j]) continue;
				
				if (k > f[n-i]) k -= f[n-i];
				else{
					a[i] = j;
					mk[j] = true;
					break;
				}
			}
		}
		fore(i,1,n+1) cout << a[i] << " ";
		cout << nl;
	}
	else{
		cin >> n;
		fore(i,1,n+1) cin >> a[i];
		
		k = 0;
		fore(i,1,n+1){
			ll cnt = 0;
			fore(j,1,a[i]){
				if (!mk[j]) cnt++;
			}
			k += (cnt*f[n-i]);
			mk[a[i]] = true;
		}
		cout << k+1 << nl;
	}
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