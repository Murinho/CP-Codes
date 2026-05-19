#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 2e5+100;
ll n,subsz[maxn],subsum[maxn],res[maxn];
vi adj[maxn];

void dfs(int anode, int node){
	subsz[node] = 1;
	for(auto au : adj[node]){
		if (anode != au){
			dfs(node,au);
			subsz[node] += subsz[au]; //acum the subtree size.
			subsum[node] += subsum[au] + subsz[au]; //subtree sum.
		}
	}
}

void rooting(int anode, int node, ll szup, ll sumup){
	sumup += szup;
	res[node] = subsum[node] + sumup;
	for(auto au : adj[node]){
		if (anode != au){
			//before proceeding, calc the next szup and sumup:
			ll addsz = subsz[node] - subsz[au];
			ll addsum = subsum[node] - subsum[au] - subsz[au];
			rooting(node,au,szup + addsz,sumup + addsum);
		}
	}
}

int main(){
    fast;
	cin>>n;
	fore(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,1);
	rooting(1,1,0,0);
	fore(i,1,n+1) cout<<res[i]<<" ";
	cout<<nl;
	return 0;
}