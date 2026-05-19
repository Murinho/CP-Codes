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

const ll maxn = 1e6+100;

ll k,n,cnt=0;
char a[maxn];

void init(){
	fore(i,1,n+1) a[i] = '-';
}

bool check(){
	fore(i,2,n){
		if (a[i-1] == '-' && a[i] == '-' && a[i+1] == '-') return false;
		if (a[i] == 'X' && (a[i-1] == 'X' || a[i+1] == 'X')) return false;
	}
	if (a[1] == '-' && a[2] == '-') return false;
	if (a[n-1] == '-' && a[n] == '-') return false;
	return true;
}

int main(){
    fast;
    cin >> k >> n;
    init();
    int las = -1;
    int i = 1;
    while(i <= n && cnt < k){
    	int j = las+3;
    	while(j >= i){
    		if (j <= n){
    			ll falt = k-cnt-1;
    			ll sob = n-j;
    			sob /= 2ll;
    			
    			if (falt <= sob){
    				a[j] = 'X';
    				//cout << "puse: " << j << nl;
    				cnt++;
    				break;
    			}
    		}
    		j--;
    	}
    	i = j+2;
    	las = j;
    }
    
    if (check()){
    	fore(i,1,n+1) cout << a[i];
    	cout << nl;
    }
    else cout << "*" << nl;
    
    
    return 0;
}