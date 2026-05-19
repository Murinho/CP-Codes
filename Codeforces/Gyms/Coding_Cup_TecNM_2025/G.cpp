// Problem: G. Tortuguitas
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const ll maxn = 1e3+100;

ll n;
map <pii,ll> f,res;
vector <pii> uni;
ll ans=0;

bool cmp(pii p1, pii p2){
	return p1.s < p2.s;
}

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
    	ll x,y;
    	cin >> x >> y;
    	f[{x,y}]++;
    	uni.pb({x,y});
    }
    
    uni.pb({0,0});
    
    sort(ALL(uni));
	uni.erase(unique(ALL(uni)),uni.end());
	
	sort(ALL(uni),cmp);
	
	ans = f[{0,0}];
    res[{0,0}] = f[{0,0}];

	fore(i,0,sz(uni)){
		fore(j,i+1,sz(uni)){
			ll dt = uni[j].s - uni[i].s;
			ll dx = abs(uni[j].f - uni[i].f);
			
			if (dt >= dx){
				res[uni[j]] = max(res[uni[j]], res[uni[i]] + f[uni[j]]);
				ans = max(ans,res[uni[j]]);
			}
		}
	}
    
    cout << ans << nl;
    
    return 0;
}