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
const ll loga = 20;

vvi cycles;
ll adj[maxn],n,q,color[maxn],par[maxn],incy[maxn],dep[maxn],up[maxn][loga];
vi radj[maxn];
pii cybel[maxn];

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

void dfs(int anode, int node, int prof=0){
    up[node][0]=anode;
    dep[node]=prof;
    for(auto au : radj[node]){
        if (!incy[au] && au != anode) dfs(node,au,prof+1);
    }
}   

void binLift(){
    fore(i,1,loga){
        fore(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
    }
}

ll getAncestor(int x, int k){
    for(int i = loga-1; i>=0; i--){
        if ((1ll<<i) <= k){
            k -= (1ll<<i);
            x = up[x][i];
        }
    }
    return x;
}


int main(){
    fast;
    cin>>n>>q;
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
            cybel[cycles[i][j]] = {i,j}; //cycle index, node of cycle index.
            incy[cycles[i][j]]=1;
        }
    }

    //getting the profs and direct parents.
    fore(i,1,n+1) if (incy[i]) dfs(i,i);

    binLift();

    while(q--){
        ll x,k;
        cin>>x>>k;
        if (dep[x] <= k){ //will have to look into the cycle.
            ll node = getAncestor(x,dep[x]);
            k -= dep[x];
            ll cyidx = cybel[node].fst;
            ll id = cybel[node].snd;
            ll tam = sz(cycles[cyidx]);
            ll fiid = (id+k)%tam;
            cout<<cycles[cyidx][fiid]<<nl;
        }
        else{ //direct query for kth ancestor.
            cout<<getAncestor(x,k)<<nl;
        }
    }
}