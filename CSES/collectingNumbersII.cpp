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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 2e5+100;
ll a[maxn],ans = 0,loca[maxn],ap[maxn];
ll n,q;

void check(int x){ //checking (x-1) and (x):
	if (x <= 1 || x > n) return;
	if (ap[x]) ap[x] = 0, ans--;
	
	if (loca[x-1] > loca[x]) ap[x] = 1, ans++;
	return;
}

//4 2 1 5 3
//4 1 2 5 3


int main(){
    fast;
	cin>>n>>q;
	fore(i,1,n+1) cin>>a[i], loca[a[i]] = i;
	fore(i,2,n+1){
		if (loca[i-1] > loca[i]){
			ans++;
			ap[i] = 1;
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		swap(a[x],a[y]);
		loca[a[x]] = x;
		loca[a[y]] = y;
		if (a[x] > a[y]) swap(x,y);
		
		check(a[x]-1);
		check(a[x]);
		check(a[x]+1);
		check(a[y]-1);
		check(a[y]);
		check(a[y]+1);
		cout<<ans + 1<<nl;
	}
}