// Problem: K. Keep Fighting
// Contest: Codeforces - The 2025 ICPC Latin America Championship
// URL: https://codeforces.com/gym/105789/problem/K
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

using namespace std;

ll n,p,h,atk=0,ans=0;
vi su,mu;

int main(){
    fast;
   	cin>>n>>p>>h;
   	fore(i,0,n){
   		char c;
   		ll x;
   		cin>>c;
   		if (c == '*'){
   			cin>>x;
   			if (x > 1ll) mu.pb(x);
   		}
   		else if (c == '+'){
   			cin>>x;
   			su.pb(x);
   		}
   		else atk++;
   	}
   	
   	if (atk == 0ll){ // there is no way to attck
   		cout<<"*"<<nl;
   		return 0;
   	}
   	if (p >= h){ // just attack once.
   		cout<<1<<nl;
   		return 0;
   	}
   	if (sz(su) == 0 && p == 0ll){ // no way to sum and multipliers are unuseful.
   		cout<<"*"<<nl;
   		return 0;
   	}
   	if (sz(su) == 0 && sz(mu) == 0){ // only have attacks.
   		ll need = (h/p) + (h%p > 0ll ? 1ll : 0ll); // attacks that I need.
       	if (need%atk == 0){
       		ll g;
       		g = ((need-1)/atk)*n;
       		g += atk;
       		ans = g;
       	}
       	else{
       		ll g;
       		g += (need/atk)*n;
       		g += need%atk;
       		ans = g;
       	}
    	cout<<ans<<nl;
    	return 0;
    }
   	
   	if (sz(su)) sort(ALL(su)), reverse(ALL(su));
   	if (sz(mu))	sort(ALL(mu)), reverse(ALL(mu));
   	
   	for(;;){
   		ll pp = p;
   		// first sum:
   		for(auto &au : su) pp = min(pp + au, h);
   		// then multiply:
   		for(auto &au : mu) pp = min(pp * au, h);
   		if (pp == 0ll){
   			cout<<"*"<<nl;
   			return 0;
   		}
   		// then attack:
   		ll hh = h;
   		fore(i,0,atk){
   			if (hh <= pp){
   				hh = 0ll;
   				break;
   			}
   			hh -= pp;
   		}
   		if (hh <= 0ll) break;
   		
   		h = hh;
   		p = pp;
   		ans += n;
   	}
   	ll res = n;
   	for(ll i = 0; i<=sz(su); i++){
   		for(ll j = 0; j<=sz(mu); j++){
   			ll pp = p;
   			for(ll ii = 0; ii<i; ii++) pp = min(pp + su[ii], h);
   			for(ll jj = 0; jj<j; jj++) pp = min(pp * mu[jj], h);
   			
   			ll hh = h;
   			for(ll kk = 1; kk<=atk; kk++){
   				if (hh <= pp){
   					res = min(res,i + j + kk);
   					break;
   				}
   				hh -= pp;
   			}
   		}
   	}
   	ans += res;
   	cout<<ans<<nl;
   	return 0;
}