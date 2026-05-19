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

const int maxn = 50015;
const int loga = 17;

bool c[maxn];
vector<int> adj[maxn],primes;
int subt[maxn][loga],dep[maxn][loga],cenpar[maxn],cnt[maxn];
bool vis[maxn];
ll n,ans=0,sol;

int dfsExplore(int anode, int node, int depth, int layer, vi &elms){
    dep[node][layer] = depth;
    subt[node][layer] = 1;
    elms.pb(node);
    for (auto &au : adj[node]){
        if (anode != au && !vis[au]){
            subt[node][layer] += dfsExplore(node,au,depth+1,layer,elms);
        }
    }
    return subt[node][layer];
}
 
bool check(int node, int layer, int tam){
    int sum = 1;
    for (auto &au : adj[node]){
        if (dep[au][layer] > dep[node][layer]){
            sum += subt[au][layer];
            if (subt[au][layer] > tam/2) return false;
        }
    }
    if (tam-sum <= tam/2) return true;
    return false;
}   

void update_counts(int anode, int node, int dep, bool add){
	if (add) cnt[dep]++;
	else cnt[dep]--;
	
	for(auto &signode : adj[node]){
		if (anode == signode || vis[signode]) continue;
		update_counts(node,signode,dep+1,add);
	}
}

void sum_counts(int anode, int node, int dep){
	for(auto &k : primes){
		if (dep > k) continue;
		sol += cnt[k-dep];
	}
	
	for(auto &signode : adj[node]){
		if (anode == signode || vis[signode]) continue;
		sum_counts(node,signode,dep+1);
	}
}
 
void centroidBuild(int centroid_parent, int node, int layer){
    vi elms;
    int tam = dfsExplore(0,node,1,layer,elms);
    int new_centroid = -1;
    for(auto &elm : elms){
        if (check(elm,layer,tam)){
            vis[elm]=true;
            // Save each node's centroid parent.
            cenpar[elm] = centroid_parent; 
            new_centroid = elm;
            break;
        }
    }
    
    if (new_centroid == -1) return;
    
    // Do the counting process:
    sol = 0;
    update_counts(centroid_parent,new_centroid,0,1);
    for(auto &k : primes){
    	sol += cnt[k];
    }
    
    for(auto &signode : adj[new_centroid]){
    	if (vis[signode]) continue;
    	update_counts(new_centroid,signode,1,0);
    	sum_counts(new_centroid,signode,1);
    	update_counts(new_centroid,signode,1,1);
    }
    
    update_counts(centroid_parent,new_centroid,0,0);
    
    ans += sol/2;
    
    for(auto &signode : adj[new_centroid]){
    	if (vis[signode]) continue;
    	centroidBuild(new_centroid,signode,layer+1);
    }
}

void sieve(){
	c[1]=true;
	for(int i = 2; i<=n; i++){
		if (!c[i]){
			primes.eb(i);
			for(int j = 2; i*j <=n; j++) c[i*j]=true;
		}
	}
}


int main(){
    fast;
    cin>>n;
    sieve();
    fore(i,1,n){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    centroidBuild(-1,1,0);
    
    ll tot = n*(n-1);
    ans *= 2ll;
    ld prob = (ld)ans/(ld)tot;
    cout<<fixed<<setprecision(9)<<prob<<nl;
    
    return 0;
}