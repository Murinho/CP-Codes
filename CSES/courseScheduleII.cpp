#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
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

const ll maxn = 1e5+10;

ll n,m,res[maxn],deg[maxn];
vi g[maxn];

int main(){
    fast;
    cin>>n>>m;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
       	g[y].pb(x);
       	deg[x]++;
    }
    
   	priority_queue <ll> pq;
   	fore(i,1,n+1) if (!deg[i]) pq.push(i);
   	
   	vi ans;
   	
   	while(sz(pq)){
   		ll node = pq.top();
   		pq.pop();
   		
   		ans.pb(node);
   		
   		for(auto &signode : g[node]){
   			deg[signode]--;
   			if (deg[signode] == 0) pq.push(signode);
   		}		
   	}
   	
   	reverse(ALL(ans));
   	for(auto &elm : ans) cout << elm << " ";
   	cout << nl;
    return 0;
}