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
 
const ll maxx = 1e5+100;
const ll maxn = 102;
 
struct Item{
	ll cost,val,cnt,id;
};
 
bool cmp(Item &it1, Item &it2){
	return it1.val * it2.cost < it2.val * it1.cost;
}
 
bool vis[maxx][maxn];
vector <Item> v;
ll n,x,dp[maxx],h[maxx],s[maxx],k[maxx];
 
void init(){
	v.reserve(n);
	fore(i,1,maxx){
		dp[i] = -1;
	}
	dp[0] = 0;
}
 
int main(){
    fast;
    cin >> n >> x;
    
    init();
    
    fore(i,0,n) cin >> h[i];
    fore(i,0,n) cin >> s[i];
    fore(i,0,n) cin >> k[i];
    
    fore(i,0,n){
    	v.pb({h[i],s[i],k[i],i});
    }
    
    sort(ALL(v),cmp);
    reverse(ALL(v));
    
    //for(auto &elm : v) cout << elm.cost << " " << elm.val << nl;
    
    for(auto &elm : v){
    	for(int i = x-elm.cost; i>=0; i--){
    		if (dp[i] == -1) continue;
    		
    		int j = i+elm.cost;
    		ll add = elm.val;
    		ll cnt = 1;
    		while(j <= x && cnt <= elm.cnt){
    			if (dp[j] >= dp[i] + add) break;
    			dp[j] = dp[i] + add;
    			
    			j += elm.cost;
    			add += elm.val;
    			cnt++;
    		}
    	}
    }
    
    ll ans = 0;
    fore(i,0,maxx) ans = max(ans,dp[i]);
    
    cout << ans << nl;
    
    return 0;
}