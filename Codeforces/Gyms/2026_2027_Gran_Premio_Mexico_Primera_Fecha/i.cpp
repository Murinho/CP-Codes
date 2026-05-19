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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

static const int maxn = 2e5+100;

ll a[maxn],n,deg[maxn],dp[maxn];
bool mk[maxn];
string s;

static inline void topo_bfs(){
	queue <int> q;
	if (s[0] == '<'){
	    	dp[0] = 1;
	    	deg[0] = 0;
	    	q.push(0);
	    	mk[0] = true;
    }
    if (s.back() == '>'){
	    	dp[n-1] = 1;
	    	deg[n-1] = 0;
	    	q.push(n-1);
	    	mk[n-1] = true;
    }
    fore(i,1,n-1){
    		if (mk[i]) continue;
	    	if (s[i-1] == '>' && s[i] == '<'){
	    		dp[i] = 1;
	    		deg[i] = 0;
	    		q.push(i);
	    		mk[i] = true;
	    	}
	    	else if ((s[i-1] == '>' && s[i] == '>') || (s[i-1] == '<' && s[i] == '<')){
	    		deg[i] = 1;
	    		mk[i] = true;
	    	}
	    	else if (s[i-1] == '<' && s[i] == '>'){
	    		deg[i] = 2;
	    		mk[i] = true;
	    	}
	    	else{
	    		int l = i-1;
		    	int r = i;
		    	while(l >= 0 && s[l] == '=') l--;
		    	while(r < sz(s) && s[r] == '=') r++;
		    	
		    	l++;
		    	r--;
		    	if (l == 0 && r == sz(s)-1){
		    		for(int i = 0; i<n; i++){
		    			dp[i] = 1;
		    			deg[i] = 0;
		    			mk[i] = true;
		    		}
		    	}
		    	else if (l == 0){
		    		if (s[r+1] == '<'){
		    			for(int i = 0; i<=r+1; i++){
		    				dp[i] = 1;
		    				deg[i] = 0;
		    				mk[i] = true;
		    			}
		    			q.push(r+1);
		    		}
		    		else{ // if '>'
		    			fore(i,0,r+2){
		    				deg[i] = 1;
		    				mk[i] = true;
		    			}
		    		}
		    	}
		    	else if (r == sz(s)-1){
		    		if (s[l-1] == '>'){
		    			for(int i = l; i<n; i++){
		    				dp[i] = 1;
		    				deg[i] = 0;
		    				mk[i] = true;
		    			}
		    			q.push(l);
		    		}
		    		else{ // if '<'
		    			for(int i = l; i<n; i++){
		    				deg[i] = 1;
		    				mk[i] = true;
		    			}
		    		}
		    	}
		    	else{
		    		if (s[l-1] == '>' && s[r+1] == '<'){
		    			for(int i = l; i<=r+1; i++){
			    			dp[i] = 1;
			    			deg[i] = 0;
			    			mk[i] = true;
			    		}
			    		q.push(l);
			    		q.push(r+1);
		    		}
		    		else if ((s[l-1] == '>' && s[r+1] == '>') || (s[l-1] == '<' && s[r+1] == '<')){
		    			for(int i = l; i<=r+1; i++){
			    			deg[i] = 1;
			    			mk[i] = true;
			    		}
		    		}
		    		else{
		    			for(int i = l; i<=r+1; i++){
			    			deg[i] = 2;
			    			mk[i] = true;
			    		}
		    		}
		    	}
	    	}
    }
    
    // fore(i,0,n){
    		// cout << i << ": " << deg[i] << nl;
    // }
    
    while(sz(q)){
	    	ll node = q.front();
	    	
	    	// cout << "node: " << node << nl;
	    	
	    	q.pop();
	    	
	    	// cout << "left vis: ";
	    	int ot = node-1;
	    	while(ot >= 0 && s[ot] == '='){
	    		dp[ot] = max(dp[ot],dp[node]);
	    		// cout << ot << " ";
	    		deg[ot]--;
	    		ot--;
	    	}
	    
	    	if (ot >= 0){
	    		if (s[ot] == '>'){
	    			dp[ot] = max(dp[ot],dp[node]+1);
	    			deg[ot]--;
	    			if (deg[ot] == 0){
	    				q.push(ot);
	    			}
	    		}
	    	}
	    	
	    	// cout << nl;
	    	// cout << "right vis: ";
	    	ot = node+1;
	    	while(ot < n && s[ot-1] == '='){
	    		dp[ot] = max(dp[ot],dp[node]);
	    		// cout << ot << " ";
	    		deg[ot]--;
	    		ot++;
	    	}
	    	if (ot < n){
	    		if (s[ot-1] == '<'){
	    			dp[ot] = max(dp[ot],dp[node]+1);
	    			deg[ot]--;
	    			if (deg[ot] == 0){
	    				q.push(ot);
	    			}
	    		}
	    	}
	    	// cout << nl;
    }
}

int main(){
    fast;
    cin >> n;
    fore(i,0,n) cin >> a[i];
    cin >> s;
    
    fore(i,0,n){
    		deg[i] = 1;
    }
    
    topo_bfs();
    
    fore(i,0,n){
    		mk[i] = false;
    }
    
    fore(i,0,n){
    		int pos = i;
    		ll mx = dp[i];
    		while(pos < sz(s) && s[pos] == '='){
    			mx = max(mx,dp[pos]);
    			pos++;
    		}
    		mx = max(mx,dp[pos]);
    		
    		for(int j = i; j<=pos; j++){
    			dp[j] = max(dp[j],mx);
    		}
    		i = pos;
    }
    
    ll ans = 0;
    fore(i,0,n){
    		ans += a[i]*dp[i];
    }
    
    cout << ans << nl;
    fore(i,0,n){
    		cout << dp[i] << " ";
    }
    cout << nl;
    
    return 0;
}