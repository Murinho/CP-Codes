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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e6+5;

bool c[maxn];
vi ops[maxn],aps[maxn];
ll n,q;
vi d;

void sieve(){
	for(int i = 2; i<=n; i++){
		if (!c[i]){
			ops[i].pb(i);
			for(int j = 2; i*j<=n; j++){
				c[i*j] = true;
				ops[i*j].pb(i);
			}
		}
	}
	
	fore(i,2,n+1){
		ll x = i;
		for(auto &prime : ops[i]){
			while(x%prime == 0){
				aps[i].pb(prime);
				x /= prime;
			}
		}
	}
}

bool cmp(ll x, ll y){
	ll mn = min(sz(aps[x]),sz(aps[y]));
	fore(i,0,mn){
		if (aps[x][i] < aps[y][i]) return true;
		else if (aps[x][i] > aps[y][i]) return false;
	}
	if (sz(aps[x]) < sz(aps[y])) return true;
	return false;
}

void precomp(){
	fore(i,1,n+1){
		d.eb(i);
	}
	
	sort(ALL(d),cmp);
}

int main(){
    fast;
    cin >> n >> q;
    sieve();
    precomp();
    while(q--){
    	ll x;
    	cin >> x;
    	x--;
    	cout << d[x] << nl;
    }
    return 0;
}