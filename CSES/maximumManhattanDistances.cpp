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

set <ll> s1,s2,s3;
ll n,x,y,ans;

int main(){
    fast;
    cin >> n;
    fore(i,0,n){
    		cin >> x >> y;
    		s1.insert(x+y);
    		s2.insert(x-y);
    		s3.insert(-x+y);
    		
    		ans = 0;
    		ans = max(ans, *s1.rbegin() - *s1.begin());
    		ans = max(ans, *s2.rbegin() - *s2.begin());
    		ans = max(ans, *s3.rbegin() - *s3.begin());
    		
    		cout << ans << nl;
    }
    
    return 0;
}