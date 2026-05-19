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
multiset <ll> mst;

int main(){
    fast;
	ll k,n;
	cin>>k>>n;
	st.insert(0), st.insert(k);
	mst.insert(k);
	while(n--){
		ll x;
		cin>>x;
		st.insert(x);
		auto it = st.find(x);
		ll ant = *prev(it);
		ll aft = *next(it);
		mst.erase(mst.find(aft-ant));
		mst.insert(x-ant);
		mst.insert(aft-x);
		cout<<*mst.rbegin()<<" ";
	}
	cout<<nl;
	return 0;
}