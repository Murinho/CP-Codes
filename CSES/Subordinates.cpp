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
ll n,ans[maxn];
vi adj[maxn];

int explore(int node){
	ans[node] = 0;
	for(auto au : adj[node]){
		ans[node] += explore(au);
	}
	return ans[node] + 1;
}

int main(){
    fast;
	cin>>n;
	fore(i,2,n+1){
		ll x;
		cin>>x;
		adj[x].pb(i);
	}
	explore(1);
	fore(i,1,n+1) cout<<ans[i]<<" ";
	cout<<nl;
	return 0;
}