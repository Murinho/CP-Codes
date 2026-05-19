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
 
using namespace std;

const ll maxn = 1e7+10;

ll n,k,x,a,b,c;
ll ans=0;
ll cur=0;
ll arr[maxn];

int main(){
    fast;
   	cin >> n >> k;
   	cin >> x >> a >> b >> c;
   	arr[1] = x;
   	cur = x;
   	fore(i,2,k+1){
   		arr[i] = (arr[i-1]*a + b)%c;
   		cur ^= arr[i];
   	}
   	
   	fore(i,k+1,n+1){
   		ans ^= cur;
   		cur ^= arr[i-k];
   		arr[i] = (arr[i-1]*a + b)%c;
   		cur ^= arr[i];
   	}
   	ans ^= cur;
   	cout << ans << nl;
   	
   	return 0;
}