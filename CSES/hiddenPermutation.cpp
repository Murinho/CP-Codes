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

const ll maxn = 1005;

ll n,res[maxn];
vi a;

string ask(ll i, ll j){
	cout << "? " << i << " " << j << nl;
	cout.flush();
	string res;
	cin >> res;
	return res;
}

void respond(){
	cout << "! ";
	fore(i,1,n+1) cout << res[i] << " ";
	cout << nl;
	cout.flush();
	return;
}

int main(){
    cin >> n;
    a.pb(1);
    
    fore(i,2,n+1){
    	int l = 0;
    	int r = i-2;
    	while(l < r){
    		ll mid = (l+r)/2;
    		if (ask(i,a[mid]) == "YES") r = mid;
    		else l = mid+1;
    	}
    	
    	int pos = l;
    	if (r == i-2 && ask(i,a[r]) == "NO"){ // es el mas grande de todos.
    		pos = l+1;
    	}
    	
    	vi b;
    	fore(j,0,pos) b.pb(a[j]);
    	b.pb(i);
    	fore(j,pos,sz(a)) b.pb(a[j]);
    	
    	a = b;
    }

	fore(i,0,n){
		res[a[i]] = i+1;
	}
    
	respond();
	return 0;
}