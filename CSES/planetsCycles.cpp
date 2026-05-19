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
#define sz(a)((int)a.size())
#define lsb(x)((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 2e5+5;

vvi cycles;
ll adj[maxn],n,color[maxn],par[maxn],dep[maxn],incy[maxn],roots[maxn],cybel[maxn];
vi radj[maxn];

void dfs_cycle(int u, int p){
    if (color[u]==2) return;
    if (color[u]==1){
        vi v;
        int cur = p;
        v.pb(cur);
        while(cur!=u){
            cur = par[cur];
            v.pb(cur);
        }
        reverse(ALL(v));
        cycles.pb(v);
        return;
    }
    par[u]=p;
    color[u]=1;
    dfs_cycle(adj[u],u);
    color[u]=2;
}

void dfs(int anode, int node, int root, int prof=0){
    dep[node]=prof;
    roots[node]=root;
    for(auto au : radj[node]){
        if (!incy[au] & au != anode) dfs(node,au,root,prof+1);
    }
}

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1){
        ll x;
        cin>>x;
        adj[i]=x;
        radj[x].pb(i);
    }

    //identify cycles:
    cycles.pb({}); //empty.
    fore(i,1,n+1) if (!color[i]) dfs_cycle(i,i);

    //label the cycles:
    fore(i,1,sz(cycles)){
        fore(j,0,sz(cycles[i])){
            cybel[cycles[i][j]] = i;
            incy[cycles[i][j]]=1;
        }
    }

    //getting to profs and setting the roots for each of the nodes.
    fore(i,1,n+1) if (incy[i]) dfs(i,i,i);

    fore(i,1,n+1){
        ll x=i;
        ll ans = dep[x];
        x = roots[x];
        ll cyidx = cybel[x];
        ans += sz(cycles[cyidx]);
        cout<<ans<<" ";
    }
    cout<<nl;
    return 0;
}



