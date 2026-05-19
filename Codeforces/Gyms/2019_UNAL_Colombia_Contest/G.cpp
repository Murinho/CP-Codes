// Problem: G. Graduation
// Contest: Codeforces - 2019 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/102307/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 1e5+10;
vi adj[maxn],radj[maxn];
ll indeg[maxn],dep[maxn],dis[maxn],n,k,ans=0,a[maxn];

void bfs(){
	set < pii > st; //{depth,node}.
	fore(i,1,n+1) if (!indeg[i]) st.insert({dep[i],i});
	
	ll cnt = 0;
	while(sz(st)){
		cnt++;
		set <int> nos; //the classes (nodes) that cannot be taken in the same semester.
		set <int> sav; //deep nodes that are indeg = 0, but cannot be taken in the round.
		ll tak = 0;
		while(tak < k && sz(st)){
			pii p = *st.rbegin();
			st.erase(p);
			ll prof = p.fst;
			ll node = p.snd;
			if (nos.count(node)){
				sav.insert(node);
			}
			else{
				dis[node] = cnt;
				tak++;
				//cout<<node<<" --> "<<cnt<<nl;
				for(auto au : adj[node]){
					indeg[au]--;
					if (!indeg[au]){
						st.insert({dep[au],au});
						nos.insert(au);
					}
				}
			}
		}
		//put the saved nodes back in the set:
		for(auto au : sav) st.insert({dep[au],au});
		sav.clear(), nos.clear();
	}
}

void dfs(int node, int prof){
	dep[node] = prof;
	for(auto au : radj[node]){
		dfs(au,prof+1);
	}
}

int main(){
    fast;
	cin>>n>>k;
	fore(i,1,n+1){
		ll x;
		cin>>x;
		a[i] = x;
		if (x != 0){
			adj[i].pb(x);
			radj[x].pb(i);
			indeg[x]++;
		}
	}
	fore(i,1,n+1) if (!a[i]) dfs(i,1);
	bfs();
	ans = 0;
	fore(i,1,n+1) ans = max(ans,dis[i]);
	cout<<ans<<nl;
	return 0;
}