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

const ll abt = 26;
vi g[abt];
bool vis[abt][abt];

void dfs(ll &stnode, int node){
	vis[stnode][node]=true;
	for(auto &signode : g[node]){
		if (!vis[stnode][signode]) dfs(stnode,signode);
	}
}

void solve(){
	ll n,m;
	cin>>n>>m;
	fore(i,0,n){
		char ca,cb;
		int x,y;
		cin>>ca>>cb;
		x = (int)(ca-'a');
		y = (int)(cb-'a');
		g[x].pb(y);
	}
	fore(i,0,abt){
		dfs(i,i);
	}
	
	fore(i,0,m){
		string s,t;
		cin>>s;
		cin>>t;
		if (sz(s) != sz(t)){
			cout<<"no"<<nl;
			continue;
		}
		bool ok=true;
		fore(j,0,sz(s)){
			int x,y;
			x = (int)(s[j]-'a');
			y = (int)(t[j]-'a');
			if (!vis[x][y]){
				ok=false;
				break;
			}
		}
		if (ok) cout<<"yes"<<nl;
		else cout<<"no"<<nl;
	}
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}