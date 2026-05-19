#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int

#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define fst first
#define snd second
#define sz(a) ((ll) a.size())
#define ALL(a) a.begin(),a.end()
#define ppb pop_back
 
struct STC{
	
	vector<bool>vis;
	
	void dfs(int v, vector<vector<int>>const &g, vector<int>&output){
		vis[v]=true;
		for(auto u:g[v]){
			if(!vis[u]){
				dfs(u,g,output);
			}
		}
		output.push_back(v);
	}
	
	void calc(vector<vector<int>> const& g,
					vector<vector<int>> &components,
					vector<vector<int>> &adj_cond){
						
		int n=g.size();
		components.clear(), adj_cond.clear();
		
		vector<int>order;
		vis.assign(n,false);
		
		for(int i=0;i<n;i++){
			if(!vis[i]){
				dfs(i,g,order);
			}
		}
		
		vector<vector<int>>g_rev(n);
		for(int v=0;v<n;v++){
			for(auto u:g[v]){
				g_rev[u].push_back(v);
			}
		}	
		vis.assign(n,false);
		reverse(order.begin(),order.end());
		
		vector<int>roots(n,0);
		
		for(auto v:order){
			if(!vis[v]){
				vector<int>component;
				dfs(v,g_rev,component);
				components.push_back(component);
				int root = *min_element(component.begin(),component.end());
				for(auto u:component){
					roots[u]=root;
				}
			}
		}
		
		adj_cond.assign(n,{});
		for(int v=0;v<n;v++){
			for(auto u:g[v]){
				if(roots[v]!=roots[u])
					adj_cond[roots[v]].push_back(roots[u]);
			}
		}				
	}	
};
 
 
void solve(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> g, comp, adj;
	vector<double>nums(n);
	g.resize(n);
	adj.resize(n);
	
	for(int i=0;i<n;i++)cin>>nums[i];
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
	}
	
	STC strong;
	
	strong.calc(g,comp,adj);
	
	vector<int> d(n);
	
	/*for(auto a:comp){
		for(auto b:a){
			cout<<b<<" ";
		}
		cout<<"\n";
	}*/
	
	for(int i=0;i<n;i++){
		//cout<<i<<": ";
		for(auto a:adj[i]){
			d[i]++;
			//cout<<a<<" ";
		}
		//cout<<"\n";
	}
	
	double ans=0.0;
	
	for(auto a:comp){
		double aux=1.0;
		if(d[*min_element(a.begin(),a.end())] == 0){
			for(auto b:a){
				aux*=(1.0-nums[b]);
			}
		}
		if(aux != 1.0)ans=max(ans,aux);
	}
	cout<<std::setprecision(10)<<(ans)<<"\n";
} 
 
int32_t main(){
	
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//cout.precision(10);
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}