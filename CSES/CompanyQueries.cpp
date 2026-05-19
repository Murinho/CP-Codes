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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+100;
const ll loga = 24;
ll up[maxn][loga],n,q;

ll kthAncestor(int x, int k){
	for(int i = loga-1; i>=0; i--){
		ll pot = (1ll<<i);
		if (pot <= k){
			k -= pot;
			x = up[x][i];
		}
	}
	return (x == 0 ? -1 : x);
}

void binLift(){
	fore(i,1,loga){
		fore(j,1,n+1){
			up[j][i] = up[up[j][i-1]][i-1];
		}
	}
}

int main(){
    fast;
	cin>>n>>q;
	fore(i,2,n+1){
		ll x;
		cin>>x;
		up[i][0] = x;
	}
	binLift();
	while(q--){
		ll x,k;
		cin>>x>>k;
		cout<<kthAncestor(x,k)<<nl;
	}
	return 0;
}