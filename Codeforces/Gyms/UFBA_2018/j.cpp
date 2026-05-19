#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second


using namespace std;

const ll maxn = 1e5+5;

vi adj[maxn];
ll res[maxn],n,m;
map <ll,ll> uf[maxn]; //have a union find for every node.
pii e[maxn];

int bus(ll u, ll id){
    if (!uf[u].count(id)) return id;
    return uf[u][id] = bus(u,uf[u][id]);
}

void join(int id, ll u, ll v){
    u = bus(id,u);
    v = bus(id,v);
    if (u == v) return;

    uf[id][u] = v;
}

void dfs(int node){
    //Explore first:
    if (e[node].fst != 0) join(node,e[node].fst,e[node].snd);

    for(auto child : adj[node]){
        dfs(child);
        if (sz(uf[node]) < sz(uf[child])){ //swap the union find
            swap(uf[node],uf[child]); 
        }
        for(auto x : uf[child]){
            join(node,x.fst,x.snd);
        }
    }   
    res[node] = m - sz(uf[node]); //total amount of cities - size of the CC.
}


int main(){
    fast;
    cin>>n>>m;
    fore(i,2,n+1){ //join father with child.
        ll x;
        cin>>x;
        adj[x].pb(i);
    }
    fore(i,1,n+1){ 
        cin>>e[i].fst>>e[i].snd;
    }
    dfs(1);

    fore(i,1,n+1) cout<<res[i]<<nl;
    return 0;
}