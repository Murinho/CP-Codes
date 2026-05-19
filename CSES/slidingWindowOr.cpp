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
 
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
const ll maxn = 1e7+15;
const ll maxb = 30;
 
ll n,k,x,a,b,c;
ll ori=0;
int arr[maxn];
int f[maxb];
int p[maxb];
int ans=0;
 
void init(){
	p[0] = 1;
	fore(i,1,maxb) p[i] = (p[i-1] * 2ll);
}
 
void insert(int num){
	while(num > 0){
		int pos = lsbpos(num) - 1;
		if (f[pos] == 0) ori += p[pos];
		f[pos]++;
		
		num -= lsb(num);
	}
}
 
void del(int num){
	while(num > 0){
		int pos = lsbpos(num) - 1;
		f[pos]--;
		if (f[pos] == 0) ori -= p[pos];
		
		num -= lsb(num);
	}
}

void solve_small(){
	arr[1] = x;
	fore(i,2,k+1){
		arr[i] = (a*arr[i-1] + b)%c;
	}
	ll res;
	fore(i,k+1,n+1){
		res = 0;
		fore(j,i-k,i) res |= arr[j];
		ans ^= res;
		
		arr[i] = (a*arr[i-1] + b)%c;
	}
	res = 0;
	fore(j,n+1-k,n+1) res |= arr[j];
	ans ^= res;
	
	cout << ans << nl;
}
 
int main(){
    fast;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    init();
    
    if (k <= 5){
    	solve_small();
    	return 0;
    }
    
    arr[1] = x;
    insert(arr[1]);
    
    fore(i,2,k+1){
    	arr[i] = (a*arr[i-1] + b)%c;
    	insert(arr[i]);
    }
    
    fore(i,k+1,n+1){
    	ans ^= ori;
    	del(arr[i-k]);
    	arr[i] = (a*arr[i-1] + b)%c;
    	insert(arr[i]);
    }
    ans ^= ori;
    cout << ans << nl;
    return 0;
}