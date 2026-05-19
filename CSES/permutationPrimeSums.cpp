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

const ll maxn = 1e5+250;

bool c[maxn];
int a[maxn],b[maxn];
int n;

void sieve(){
	c[1] = false;
	fore(i,2,maxn){
		if (!c[i]){
			for(int j = 2; i*j < maxn; j++){
				c[i*j] = true;
			}
		}
	}
}

int nextPrime(int x){
	while(c[x]) x++;
	
	return x;
}

int main(){
    fast;
   	cin >> n;
	sieve();
	
	fore(i,1,n+1) a[i] = i;
	
	int cur = n;
	while(cur >= 1){
		int np = nextPrime(cur+1);
		int otp = np-cur;
		
		fore(j,otp,cur+1){
			b[j] = cur-(j-otp);
		}
		cur = otp-1;
	}
	
	fore(i,1,n+1) cout << a[i] << " ";
	cout << nl;
	fore(i,1,n+1) cout << b[i] << " ";
	cout << nl;
	
	return 0;
}