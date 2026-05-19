// Problem: K. Kernel Of Love
// Contest: Codeforces - 2019 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/102307/problem/K
// Memory Limit: 256 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const ll maxn = 1e5+100;

int main(){
    fast;
	ll t;
	cin>>t;
	while(t--){
		ll x;
		cin>>x;
		if (x <= 2) cout<<0<<nl;
		else cout<<((x/3)*2)+1 - (x%3 == 0)<<nl;
	}
	return 0;
}