// Problem: G. Group Photo
// Contest: Codeforces - 2025-2026 ICPC Northwestern European Regional Programming Contest (NWERC 2025)
// URL: https://codeforces.com/gym/106353/problem/G
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

const ll maxn = 5e5+100;
const ll inf = 1e9+7;

ll n,ans=0;
vector <pii> v;


int main(){
    fast;
    cin >> n;
    fore(i,0,n){
    	ll x;
    	cin >> x;
    	// puedo poner por la izquierda
    	if (x - i - 1 >= 0) v.pb({2 * i + 1, 2 * (x - i - 1)});
    	// puedo poner por la derecha
    	if (x - n + i >= 0) v.pb({2 * (x - n + i), 2 * (n - i) - 1});
    }
    
    sort(ALL(v));
    vi dp(sz(v)+1,inf);
    
    fore(i,0,sz(v)){
    	ll pos = upper_bound(ALL(dp), v[i].s) - dp.begin();
    	dp[pos] = v[i].s;
    	ans = max(ans,pos+1);
    }
    
    cout << n - ans << nl;
}