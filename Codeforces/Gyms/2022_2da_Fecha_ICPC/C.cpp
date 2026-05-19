// Problem: C. Correcting School Enrollment Errors
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll n,m;
map <ll, set <ll> > req,given;
set <ll> ids;
ll nr = 0, missed = 0, totmis = 0;

void solve(){
	cin >> n >> m;
	fore(i,0,n){
		ll id,k,x;
		cin >> id >> k;
		fore(j,0,k){
			cin >> x;
			req[id].insert(x);
		}
		ids.insert(id);
	}
	
	fore(i,0,m){
		ll id,k,x;
		cin >> id >> k;
		fore(j,0,k){
			cin >> x;
			given[id].insert(x);
		}
		ids.insert(id);
	}
	
	for(auto &id : ids){
		// check the given ones:
		vector < pair <ll,char > > v;
		for(auto &elm : given[id]){
			if (!req[id].count(elm)){
				v.pb({elm,'-'});
				nr++;
			}
		}
		// check the req ones:
		for(auto &elm : req[id]){
			if (!given[id].count(elm)){
				v.pb({elm,'+'});
				missed++;
			}
		}
		
		if (sz(v)){
			sort(ALL(v));
			totmis++;
			cout << id;
			for(auto &[val,sign] : v){
				cout << " " << sign << val;
			}
			cout<<nl;
		}
	}
	if (totmis) cout << "MISTAKES IN "<< totmis << " STUDENTS: " << nr << " NOT REQUESTED, " << missed << " MISSED"<<nl;
	else cout << "GREAT WORK! NO MISTAKES FOUND!"<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}