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

set <ll> st;
ll n;

void init(){
	fore(i,1,n+1) st.insert(i);
}

int main(){
    fast;
	cin>>n;
	init();
	if (n == 1){
		cout<<1<<nl;
		return 0;
	}
	auto it = st.begin();
	it = next(it); //start in number 2.
	while(true){
		cout<<*it<<" ";
		
		if (sz(st) == 1) break;
		ll num = *it;
		it = next(it);
		st.erase(num);
		
		//Step 2:
		if (it == st.end()) it = st.begin();
		it = next(it);
		if (it == st.end()) it = st.begin();
	}
	cout<<nl;
	return 0;
}