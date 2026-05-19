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

const ll maxn = 2e5+10;

ll n;
char c[maxn];

char ask(int x){
	cout << "? " << x << nl;
	cout.flush();
	cin >> c[x];
	return c[x];
}

void respond(int x){
	cout << "! " << x << nl;
	cout.flush();
	return;
}

int main(){
    fast;
    cin >> n;
    c[1] = ask(1);
    c[n] = ask(n);
    if (c[1] == c[n]){
    	cout << "! " << n << nl;
    	cout.flush();
    	return 0;
    }
    
    int l = 1;
    int r = n;
    while(l+1 < r){
    	int mid = (l+r)/2;
    	c[mid] = ask(mid);
    	if ((mid-l)%2 == 0){ // should be equal
    		if (c[mid] != c[l]) r = mid;
    		else l = mid;
    	}
    	else{ // should be different
    		if (c[mid] == c[l]) r = mid;
    		else l = mid;
    	}
    }
    
    respond(l);
    
    return 0;
}