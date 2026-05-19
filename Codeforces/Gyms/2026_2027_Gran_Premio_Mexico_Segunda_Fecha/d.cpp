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
 
using namespace std;

// checar si los circulos se intersectan.
// si se intersectan entonces si r1 + r2 + dist(centro1,centro2) <= k, se puede.
// tambien checar, si max(r1*2, r2*2) <= k, se puede.

ld dist(ll x1, ll y1, ll x2, ll y2){ 
	return sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
}

void solve(){
	ll x1,y1,r1,x2,y2,r2,k;
    bool ok = false;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> k;
    
    if (r1*2ll >= k || r2*2ll >= k){
    		ok = true;
    }
    
    if (dist(x1,y1,x2,y2) <= (ld)(r1+r2)){ // se intersectan
    		if (dist(x1,y1,x2,y2) + (ld)r1 + (ld)r2 >= (ld)k){
    			ok = true;
    		}
    }
    
    cout << (ok ? "YES" : "NO") << nl;
    return;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
    		solve();
    }
    return 0;
}