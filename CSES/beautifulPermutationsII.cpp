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

const ll maxn = 1e6+10;

ll n,a[maxn];
ll p[5] = {0,2,4,1,3};

void solve0(){
	for(int i = 1; i<n; i += 5){
		fore(j,0,5) cout << p[j] + i << " ";
	}
}

void solve2(){
	int add = 1;
	for(int i = 1; i<=n-7; i += 5, add += 5){
		fore(j,0,5) cout << p[j] + i << " ";
	}
	fore(j,0,4) cout << p[j] + add << " ";
	add += 5;
	cout << add << " " << add-2 << " " << add+1 << nl;
}

void solve3(){
	int add = 1;
	for(int i = 1; i<=n-8; i += 5, add += 5){
		fore(j,0,5) cout << p[j] + i << " ";
	}
	fore(j,0,4) cout << p[j] + add << " ";
	add += 5;
	cout << add << " " << add+2 << " " << add-2 << " " << add+1 << nl;
}

void solve4(){
	int add = 1;
	for(int i = 1; i<=n-4; i += 5, add += 5){
		fore(j,0,5) cout << p[j] + i << " ";
	}
	cout << add+1 << " " << add+3 << " " << add << " " << add+2 << nl;
}

int main(){
    fast;
    cin >> n;
    if (n == 1){
    	cout << 1 << nl;
    }
    else if (n <= 3){
    	cout << "NO SOLUTION" << nl;
    }
    else{
    	if (n%5 == 0){
    		solve0();
    		cout << nl;
    	}
    	else if (n%5 == 1){
    		solve0();
    		cout << n << nl;
    	}
    	else if (n%5 == 2){
    		solve2();
    	}
    	else if (n%5 == 3){
    		solve3();
    	}
    	else if (n%5 == 4){
    		solve4();
    	}
    }
    
    return 0;
}