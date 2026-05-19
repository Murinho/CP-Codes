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

const int maxn = 1e5+100;
const int loga = 17;
vi adj[maxn+5];
int subt[maxn][loga],dep[maxn][loga],cenpar[maxn];
bool vis[maxn];
int n,centroids_root;
int up[maxn][loga],pw[loga],color[maxn];
multiset <int> mst[maxn];

int dfsExplore(int anode, int node, int depth, int layer, vi &elms){
    dep[node][layer] = depth;
    subt[node][layer] = 1;
    if (layer == 0) up[node][0] = anode;
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
 
void centroidBuild(int centroid_parent, int node, int layer){
    vi elms;
    int tam = dfsExplore(0,node,1,layer,elms);
    for(auto &elm : elms){
        if (check(elm,layer,tam)){
            vis[elm]=true;
            // Save each node's centroid parent.
            if (centroid_parent == -1) centroids_root = elm;
            cenpar[elm] = centroid_parent; 
            for(auto &signode : adj[elm]){ //expand to the children.
                if (!vis[signode]){
                    centroidBuild(elm,signode,layer+1);
                }
            }
            break;
        }
    }
}

void binary_lifting(){
	pw[0]=1;
	fore(i,1,loga){
		pw[i] = (pw[i-1]*2);
		fore(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
	}
}

int lca(int x, int y){
	if (dep[x][0] < dep[y][0]) swap(x,y); // x es el mas profundo.
	
	int dif = dep[x][0]-dep[y][0];
	rofe(i,loga,0){
		if (pw[i] <= dif){
			dif -= pw[i];
			x = up[x][i];
		}
	}
	if (x == y) return x;
	
	rofe(i,loga,0){
		if (up[x][i] != up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

void update(int cur_cent, int &upd_node, bool &add){
	if (cur_cent == -1) return;
	
	int lcan = lca(cur_cent,upd_node);
	int dist = dep[cur_cent][0] - dep[lcan][0] + dep[upd_node][0] - dep[lcan][0];
	if (add) mst[cur_cent].insert(dist);
	else mst[cur_cent].erase(mst[cur_cent].find(dist));
	update(cenpar[cur_cent],upd_node,add);
}

void query(int cur_cent, int &q_node, int &ans){
	if (cur_cent == -1) return;
	int lcan = lca(cur_cent,q_node);
	int dist = dep[cur_cent][0] - dep[lcan][0] + dep[q_node][0] - dep[lcan][0];
	if (sz(mst[cur_cent])){
		int sm = *mst[cur_cent].begin();
		ans = min(ans,dist + sm);
	}
	query(cenpar[cur_cent],q_node,ans);
}


int main(){
    fast;
    cin>>n;
    fore(i,1,n){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    centroidBuild(-1,1,0);
    binary_lifting();
    ll q;
    cin>>q;
    while(q--){
    	int t,x;
    	cin>>t>>x;
    	if (t == 0){
    		bool add = true;
    		if (color[x] == 0){
    			color[x] = 1;
    		}
    		else{
    			color[x] = 0;
    			add=false;
    		}
    		update(x,x,add);
    	}
    	else{
    		int ans = n+5;
    		query(x,x,ans);
    		if (ans == n+5) cout<<-1<<nl;
    		else cout<<ans<<nl;
    	}
    }
    return 0;
}