// Problem: N. Lucky Number
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/N
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll a[5],n,x,ans=0,mn;
vi r;
bool ok;

void solve_one(ll x){
	ans += a[x]/5;
	a[x] %= 5;
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n){
    	cin>>x;
    	x %= 5;
    	a[x]++;
    }
    ans += a[0];
    a[0] = 0;
    mn = min(a[1],a[4]);
    ans += mn;
    a[1] -= mn, a[4] -= mn;
    mn = min(a[2],a[3]);
    ans += mn;
    a[2] -= mn, a[3] -= mn;
    
    // calcular los sobrantes:
    fore(i,1,5){
    	if (a[i]>0) r.pb(i);
    }
    
    if (sz(r) == 1){
    	solve_one(r[0]);
    }
    else if (sz(r) == 2){ 
    	if (r[0] == 1 && r[1] == 2){ //LISTO.
    		mn = min(a[1],a[2]/2); // hacer grupos de [1,2,2]
    		ans += mn;
    		a[1] -= mn;
    		a[2] -= (mn*2);
    		
    		mn = min(a[1]/3,a[2]); // hacer grupos de [1,1,1,2]
    		ans += mn;
			a[1] -= (mn*3);
			a[2] -= mn;
			
			solve_one(1); // hacer grupos de [1]*5
			a[2] += (a[1]/2);
			solve_one(2); // hacer grupos de [2]*5
    	}
    	else if (r[0] == 1 && r[1] == 3){
    		mn = min(a[1]/2,a[3]); // hacer grupos de [1,1,3]
    		ans += mn;
    		a[1] -= (mn*2);
    		a[3] -= mn;
    		
    		mn = min(a[1],a[3]/3); // hacer grupos de [1,3,3,3]
    		ans += mn;
    		a[1] -= mn;
    		a[3] -= (mn*3);
    		
    		solve_one(1); // hacer grupos de [1]*5
    		a[3] += (a[1]/3);
    		solve_one(3); // hacer grupos de [3]*5
    	}
    	else if (r[0] == 2 && r[1] == 4){ // LISTO.
    		mn = min(a[2],a[4]/2); // hacer grupos de [2,4,4]
    		ans += mn;
    		a[2] -= mn;
    		a[4] -= (mn*2);
    		
    		mn = min(a[2]/3,a[4]); // hacer grupos de [2,2,2,4]
    		ans += mn;
    		a[2] -= (mn*3);
    		a[4] -= mn;
    		
    		solve_one(2);
    		a[4] += (a[2]/2);
    		solve_one(4);
    	}
    	else if (r[0] == 3 && r[1] == 4){ //LISTO.
    		mn = min(a[3]/2,a[4]); // hacer grupos de [3,3,4]
    		ans += mn;
    		a[3] -= (mn*2);
    		a[4] -= mn;
    		
    		mn = min(a[3],a[4]/3); // hacer grupos de [3,4,4,4]
    		ans += mn;
    		a[3] -= mn;
    		a[4] -= (mn*3);
    		
    		solve_one(3);
    		a[4] += (a[3]/4)*3;
    		solve_one(4);
    	}
    	else ok=true;
    }
    assert(ok == false);
    cout<<ans<<nl;
    return 0;
}