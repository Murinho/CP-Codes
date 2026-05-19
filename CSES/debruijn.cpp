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

string tour;
int n;
stack<int> s;
vector<int> g[maxn];

int main(){
    fast;
    cin>>n;
	if (n == 1) {
		cout << "01" << nl;
	    return 0;
	}
	for (int i=0;i<(1ll<<(n-1));i++) {
	    g[i].pb((i*2)%(1ll<<(n-1)));
	    g[i].pb((i*2+1)%(1ll<<(n-1)));
	}
	s.push(0);
	while (sz(s)) {
	    int u = s.top();
		if (sz(g[u])) {
		    int v = g[u].back();
		    g[u].ppb();
		    s.push(v);
		} else {
		    tour.pb(u%2+'0');
		    s.pop();
		}
	}
	for (int i=0;i<n-2;i++) tour.pb('0');
	    
	for (char &u : tour) cout<<u;
}