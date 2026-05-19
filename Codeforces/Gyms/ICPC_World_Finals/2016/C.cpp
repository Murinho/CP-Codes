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

const ll maxn = 55;
int n,k;
vi g[maxn];
bool vis[maxn];

struct Node{
	struct Node *left,*right;
	int val;
};

Node *getNode(ll val){
	Node *node = new Node;
	node->left = node->right = NULL;
	node->val = val;
	return node;
}

bool parallel_dfs(Node *n1, Node *n2){
	if (n1->left && !n2->left) return false;
	if (!n1->left && n2->left) return false;
	if (n1->right && !n2->right) return false;
	if (!n1->right && n2->right) return false;
	
	if (n1->left && n2->left){
		if (!parallel_dfs(n1->left,n2->left)) return false;
	}
	if (n1->right && n2->right){
		if (!parallel_dfs(n1->right,n2->right)) return false;
	}
	return true;
}

void insert_node(Node *node, ll val){
	if (val < node->val){
		if (node->left) insert_node(node->left,val);
		else node->left = getNode(val);
	}
	else{
		if (node->right) insert_node(node->right,val);
		else node->right = getNode(val);
	}
}

void explore(int node){
	vis[node]=true;
	for(auto &signode : g[node]) if (!vis[signode]) explore(signode);
}

void solve(){
	vector<Node*> roots;
	cin>>n>>k;
	fore(i,0,n){
		vi v(k),uni;
		fore(j,0,k) cin>>v[j];
		
		uni = v;
		sort(ALL(uni));
		
		map <ll,ll> mp;
		ll cnt = 0;
		for(auto &elm : uni) mp[elm] = cnt++;
		
		Node *root = getNode(mp[v[0]]);
		fore(j,1,k) insert_node(root,mp[v[j]]);
		roots.pb(root);
	}
	
	fore(i,0,n){
		fore(j,1,n){
			if (parallel_dfs(roots[i],roots[j])){
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	
	ll ans = 0;
	fore(i,0,n) if (!vis[i]){
		ans++;
		explore(i);
	}
	cout<<ans<<nl;
}

int main(){
    fast;
    ll tc = 1;
    while(tc--){
        solve();
    }
}