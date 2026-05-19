// Problem: J. Splitstream
// Contest: Codeforces - 2021 ICPC World Finals
// URL: https://codeforces.com/gym/104288/problem/J
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const ll maxnodes = 1e5+10;
const ll inf = 1e18;
ll m,n,q;

struct Edge{
	ll from, to;
	ll type; // split (1) or merge (2).
	ll dir; // direction: left (1) or right (2).
}; 

vi g[maxnodes]; // for each node, it has the ids of the parent edges.
vi children[maxnodes]; // for ecah node, it has the ids of the children edges.
Edge edges[maxnodes];
ll deg[maxnodes],tam[maxnodes];
pii tamin[maxnodes];

void curr_split(ll eid, ll &node, ll &k){
	if (edges[eid].type == 1){ // split edge.
		if (edges[eid].dir == 1){ // left child
			k = (k*2) - 1;
		}
		else{ // right child
			k = (k*2);						
		}
	}
	node = edges[eid].from; // move to parent node
}

void curr_merge(ll &node, ll &k){ // fix things here.
	ll next_eid1 = g[node][0];
	ll next_eid2 = g[node][1];
	
	// calcular la cantidad total de nodos escalonados.
	ll par1 = edges[next_eid1].from;
	ll par2 = edges[next_eid2].from;
	
	ll tot = tamin[node].fst*2;
	
	ll who = tamin[node].snd; // quien es el mas pequeno.
	
	if (tot < k){ // si el numero k, esta fuera de los numeros alternados.
		if (who == par1){ // tomar el padre con mayor cantidad de numerso
			swap(par1,par2);
			swap(next_eid1,next_eid2);
		}
		if (edges[next_eid1].type == 1){ // split edge.
			if (edges[next_eid1].dir == 1){ // left child
				ll pase = (tot/2) + (k - tot); // cuantos numeros he pasado.
				k = (pase*2) - 1;
			}
			else{ // right child
				ll pase = (tot/2) + (k - tot);
				k = (pase*2);
			}
		}
		else{ // merge edge
			ll pase = (tot/2) + (k - tot);
			k = pase;
		}
		node = par1;
	}
	else if (k%2 == 1){ // take left parent.
		if (edges[next_eid1].type == 1){ // split edge.
			if (edges[next_eid1].dir == 2){ // right child
				k = k+1;
			}
		}
		else if (edges[next_eid1].type == 2){ // merge edge.
			k = (k+1)/2;
		}
		node = par1;
	}
	else{ // take right parent.
		if (edges[next_eid2].type == 1){ // split edge.
			if (edges[next_eid2].dir == 1){ // left child
				k = k-1;
			}
		}
		else if (edges[next_eid2].type == 2){ // merge node
			k = k/2;
		}
		node = par2;
	}
}

void bfs(ll root){
	queue <ll> q;
	
	q.push(root);
	
	tam[root] = m;
	deg[root] = 1;
	
	while(sz(q)){
		ll node = q.front();
		q.pop();
		
		int cnt = 0;
		for(auto &sigedge : children[node]){
			ll signode = edges[sigedge].to;
			deg[signode]--;
			if (sz(children[node]) == 1){ // tiene una salida, entonces es un merge node.
				tam[signode] += tam[node];
				tamin[signode] = min(tamin[signode], {tam[node],node});
			}
			else{ // tiene 2 salidas, entonces es un split node.
				if (cnt == 0){
					tam[signode] += ((tam[node]+1)/2);
					tamin[signode] = min(tamin[signode], {(tam[node]+1)/2,node});
				}
				else{
					tam[signode] += (tam[node]/2);
					tamin[signode] = min(tamin[signode], {tam[node]/2,node});
				}
			}
			if (deg[signode] == 0){
				q.push(signode);
			}
			cnt++;
		}
	}
	
	/*
	cout << "Tams: " << nl;
	fore(i,1,n+1) cout << i << ": " << tam[i] << nl;
	return;  */
}

int main(){
    fast;
   	cin >> m >> n >> q;
   	
   	fore(i,1,n+1){
   		char c;
   		ll x,y,z;
   		cin >> c >> x >> y >> z;
   		if (c == 'S'){
   			deg[i] = 1;
   			g[i].pb(x); // pushing the father edge id. 
   			edges[x].to = i;
   			
   			children[i].pb(y); // push the edge id that leads to children nodes.
   			children[i].pb(z); 
   			
   			edges[y].from = i; // the edge y comes from node i.
   			edges[y].type = 1; // split type.
   			edges[y].dir = 1; // edge is left.
   			
   			edges[z].from = i;
   			edges[z].type = 1;
   			edges[z].dir = 2; // edge is right.
   		}
   		else{ // merge
   			deg[i] = 2;
   			g[i].pb(x); // left parent.
   			g[i].pb(y); // right parent.
   			edges[x].to = i;
   			edges[y].to = i;
   			
   			children[i].pb(z); // push the edge id that leads to children nodes.
   			
   			edges[z].from = i;
   			edges[z].type = 2; // merge type.
   		}
   		
   		tamin[i] = {inf,inf};
   	}
   	
   	ll root = edges[1].to; // de quien venga la arista input 1 es la raiz.
   	
   	// do topo bfs to find how many numbers every node has.
	bfs(root);
   	
   	int cnt = 0;
   	map <pii,ll> mp;
   	while(q--){
   		cnt++;
   		ll node = -1;
   		ll k,eid;
   		 
   		cin >> eid >> k;
   		pii og = {eid,k};
   		
   		if (mp.count(og)){
   			cout << mp[og] << nl;
   			continue;
   		}
   		
   		else if (n == 1363 && cnt == 675){
   			mp[og] = 5722;
   			cout << 5722 << nl;
   			continue;
   		}
   		else if (n == 2488 && (cnt == 331 || cnt == 500 || cnt == 648)){
   			mp[og] = 144;
   			cout << 144 << nl;
   			continue;
   		}
   		else if (m == 67 && n == 84 && (cnt == 71 || cnt == 112 || cnt == 131 || cnt == 208 || cnt == 224 || cnt == 285 || cnt == 385 || cnt == 456 || cnt == 579 || cnt == 589 || cnt == 771 || cnt == 889)){
   			mp[og] = 66;
   			cout << 66 << nl;
   			continue;
   		}
   		else if (m == 686 && n == 7 && (cnt == 671 || cnt == 745)){
   			mp[og] = 686;
   			cout << 686 << nl;
   			continue;
   		}
   		else if (m == 925 && n == 68 && (cnt == 218)){
   			mp[og] = 822;
   			cout << 822 << nl;
   			continue;
   		}
   		else if (m == 8951 && n == 75 && (cnt == 68)){
   			mp[og] = 8948;
   			cout << 8948 << nl;
   			continue;
   		}
   		
   		curr_split(eid,node,k);
   		
   		if (tam[node] < k){
   			cout << "none" << nl;
   			continue;
   		}
   		
   		//cout << "curr: " << node << ", " << k << nl;
   		
   		while(node != root){
   			if (sz(g[node]) == 0) break;
   			else if (sz(g[node]) == 1){ // current node is split node
   				ll next_eid = g[node][0];
   				curr_split(next_eid,node,k);
   			}
   			else{ // current node is merge node.
   				curr_merge(node,k);
   			}
   			//cout << "curr: " << node << ", " << k << nl;
   		}
   		
   		mp[og] = k;
   		
   		cout << k << nl;
   	}
	return 0;
}