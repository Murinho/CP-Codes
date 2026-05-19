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

const ll maxn = 1e7+100;
ll ans=0,arr[maxn];
ll n,k,x,a,b,c;

deque <ll> dq;

void insert(ll x){
	while(sz(dq) && dq.back() > x) dq.pop_back();
	dq.push_back(x);
}

ll getmin(){ // minimums at the front
	return dq.front();
}

void remove(ll x){
	if (sz(dq) && dq.front() == x) dq.pop_front();
}

// 2 4 3 5 6 7

// 2 3 4 5 6 7

int main(){
    fast;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    
    arr[1] = x;
	insert(arr[1]);
    fore(i,2,k+1){
    	arr[i] = (a*arr[i-1] + b)%c;
    	insert(arr[i]);
    }
    fore(i,k+1,n+1){
    	ans ^= getmin();
    	remove(arr[i-k]);
    	
    	arr[i] = (a*arr[i-1] + b)%c;
    	insert(arr[i]);
    }
    ans ^= getmin();
    cout << ans << nl;
    return 0;
}