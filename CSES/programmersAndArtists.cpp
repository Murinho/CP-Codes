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
const ll INF = 1e18;

bool tried[maxn][2];
ll n,cap[2];
ll a[maxn][2];
set <pii> st[2];
ll ans=0;

void try_insert(int id, int where){
	if (tried[id][where]) return;
	
	tried[id][where] = true;
	
	if (sz(st[where]) < cap[where]){
		st[where].insert({a[id][where],id});
	}
	else{
		pii sm = *st[where].begin();
		if (a[id][where] > sm.fst){
			st[where].erase(sm);
			st[where].insert({a[id][where],id});
			try_insert(sm.snd, 1-where);
		}
		else{
			try_insert(id, 1-where);
		}
	}
}

int main(){
    fast;
    cin >> cap[0] >> cap[1] >> n;
    cap[0]++, cap[1]++;
    st[0].insert({INF,0});
    st[1].insert({INF,0});
    fore(i,1,n+1) cin >> a[i][0] >> a[i][1];
    
    fore(i,1,n+1){
    		if (a[i][0] >= a[i][1]){
    			try_insert(i,0);
    		}
    		else{
    			try_insert(i,1);
    		}
    }
    
    for(auto &au : st[0]){
    		if (au.fst == INF) continue;
    		ans += au.fst;
    }
    
    for(auto &au : st[1]){
    		if (au.fst == INF) continue;
    		ans += au.fst;
    }
    
    // then try to switch things here??
    
    cout << ans << nl;
    
    return 0;
}