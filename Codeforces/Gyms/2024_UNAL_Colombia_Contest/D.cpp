// Problem: D. Wise Splitting
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const ll maxn = 1e6+100;
ll n,m,a[maxn],las = 0;

struct Trans{
	ll x,y,c;
};
vector < Trans > p;

int main(){
    fast;
	cin>>n>>m;
	fore(i,0,m){
		ll x,y,z;
		cin>>x>>y>>z;
		a[x] -= z;
		a[y] += z;
	}
	
	Trans t;
	//First go with the positive ones:
	fore(i,1,n+1){
		if (a[i] > 0 && i != las){
			if (las != 0 && a[las] != 0){
				t.x = las, t.y = i, t.c = a[las];
				a[las] = 0;
				a[i] += t.c*(-1);
				p.pb(t);
			}
			las = i;
		}
	}
	//Then with the negatives ones:
	fore(i,1,n+1){
		if (a[i] < 0 && i != las){
			if (las != 0 && a[las] != 0){
				t.x = las, t.y = i;
				if (a[las] > 0){
					t.c = a[las];
					a[i] += a[las];
				}
				else{
					t.c = (a[las]*(-1));
					a[i] -= a[las];
				}
				p.pb(t);
			}
			a[las] = 0;
			las = i;
		}
	}
	cout<<sz(p)<<nl;
	for(auto au : p) cout<<au.x<<" "<<au.y<<" "<<au.c<<nl;
	return 0;
}