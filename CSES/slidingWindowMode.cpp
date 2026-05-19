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

const ll maxn = 2e5+100;

set <ll> who[maxn];
ll n,k,a[maxn],f[maxn],mx=0;
vi uni;

int main(){
    fast;
    cin >> n >> k;
    fore(i,1,n+1){
    	cin >> a[i];
    	uni.pb(a[i]);
    }
    
    sort(ALL(uni));
    uni.erase(unique(ALL(uni)),uni.end());
    
    fore(i,1,n+1){
    	a[i] = lower_bound(ALL(uni),a[i]) - uni.begin();
    }
    
    fore(i,1,k+1){
    	if (f[a[i]] > 0) who[f[a[i]]].erase(a[i]);
    	f[a[i]]++;
    	who[f[a[i]]].insert(a[i]);
    	mx = max(mx,f[a[i]]);
    }
    
    fore(i,k+1,n+1){
    	cout << uni[*who[mx].begin()] << " ";
    	
    	who[f[a[i-k]]].erase(a[i-k]);
    	if (sz(who[f[a[i-k]]]) == 0 && f[a[i-k]] == mx) mx--; 
    	f[a[i-k]]--;
    	who[f[a[i-k]]].insert(a[i-k]);
    	
    	if (f[a[i]] > 0) who[f[a[i]]].erase(a[i]);
    	f[a[i]]++;
    	who[f[a[i]]].insert(a[i]);
    	mx = max(mx,f[a[i]]);
    }
    
    cout << uni[*who[mx].begin()] << nl;
    return 0;
}