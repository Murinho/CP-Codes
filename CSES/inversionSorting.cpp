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

const ll maxn = 1005;

int n,pref[maxn],c[maxn],a[maxn];
int tot;
int v[maxn];

int ask(ll l, ll r){
	cout << l << " " << r << nl;
	cout.flush();
	int ret;
	cin >> ret;
	return ret;
}

ll g(ll x){
	return x*(x+1)/2;
}

int main(){
    fast;
    cin >> n;
    tot = ask(1,1);
    fore(i,2,n+1){
    	int ret = ask(1,i);
    	if (ret == 0) return 0;
    	
    	pref[i] = (tot + g(i-1) - ret)/2;
    	c[i] = pref[i] - pref[i-1];
    	ask(1,i);
    }
    
    fore(i,1,n+1) v[i] = i;
    
    fore(i,2,n+1){
    	for(int j = i; j>i-c[i]; j--) swap(v[j-1],v[j]);
    }
    
    // construir la permutacion original
    fore(i,1,n+1){
    	a[v[i]] = i; 
    }
    
    // ordenar la permutacion
    fore(i,1,n+1){
    	int pos = -1;
    	fore(j,1,n+1){
    		if (a[j] == i){
    			pos = j;
    			break;
    		}
    	}
    	if (pos == i) continue;
    	
    	int ret = ask(i,pos);
    	if (ret == 0) return 0;
    	
    	int l = i;
    	int r = pos;
    	while(l < r){
    		swap(a[l],a[r]);
    		l++, r--;
    	}
    }
}