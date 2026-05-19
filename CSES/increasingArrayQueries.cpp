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

const ll maxn = 2e5+100;
const ll inf = 2e9;
const ll loga = 18;

ll n,q;
ll a[maxn],p[maxn],up[maxn][loga],vap[maxn][loga];

void getmaxes(){
	vector <pii> stack;
	stack.pb({inf,n+1}); // mayor a menor
	up[n+1][0] = n+1;
	vap[n+1][0] = 0;
	rofe(i,n+1,1){
		int l = 0;
		int r = sz(stack)-1;
		while(l < r){
			ll mid = (l+r+1)/2;
			if (a[i] <= stack[mid].fst) l = mid;
			else r = mid-1;
		}
		up[i][0] = stack[l].snd;
		ll sum = p[stack[l].snd - 1] - p[i];
		ll must = (stack[l].snd - i - 1)*a[i];
		vap[i][0] = must - sum;
		while(sz(stack) && stack.back().fst < a[i]) stack.ppb();
		
		stack.pb({a[i],i});
	}
}

void binlift(){
	fore(i,1,loga){
		fore(j,1,n+2){
			up[j][i] = up[up[j][i-1]][i-1];
			vap[j][i] = vap[j][i-1] + vap[up[j][i-1]][i-1];
		}
	}
}


int main(){
    fast;
   	cin >> n >> q;
   	fore(i,1,n+1){
   		cin >> a[i];
   		p[i] = p[i-1] + a[i];
   	}
   	
   	getmaxes();
   	
   	binlift();
   	
   	while(q--){
   		ll l,r;
   		cin >> l >> r;
   		
   		ll ans = 0;
   		ll pos = l;
   		rofe(i,loga,0){
   			if (up[pos][i] <= r){
   				ans += vap[pos][i];
   				pos = up[pos][i];
   			}
   		}
   		
   		ll sum = p[r] - p[pos];
   		ll must = a[pos]*(r-pos);
   		ans += (must - sum);
   		cout << ans << nl;
   	}
   	
   	return 0;
}