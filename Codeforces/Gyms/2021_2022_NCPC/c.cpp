#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i <b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; --i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+10;
const ll INF= 1e18;

struct Edge{
    ll ot,c;
};

ll d[maxn],n,m,k,t[maxn],indeg[maxn],color[maxn],inpath[maxn],vis[maxn];
vector <Edge> adj[maxn];
vi dag[maxn];
bool swapped;

priority_queue < pii, vector < pii >, greater < pii > > pq; //{weight,node}

void init(){
    fore(i,0,n+1) d[i]=INF; //initialize distances.
}

void daikra(){
    init();
    d[0]=0;
    pq.push({d[0],0});
    while(!pq.empty()){
        pii p= pq.top();
        pq.pop();
        ll w = p.fst;
        ll node = p.snd;
        if (d[node] != w || node == n) continue;
        for(auto au : adj[node]){
            int signode = au.ot;
            ll sigw = au.c;
            if (d[signode] > d[node] + sigw){
                d[signode] = d[node] + sigw;
                pq.push({d[signode],signode});
            }
        }
    }
}

void topobfs(){
    //Calculate the indegrees of every nodes:
    fore(i,0,n+1){
        for(auto signode : dag[i]){
            indeg[signode]++;
        }
    }

    queue <ll> q;
    q.push(0);

    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto signode : dag[node]){
            indeg[signode]--;
            if(indeg[signode] == 0){
                if (k>0 && inpath[signode] == 1){
                    color[signode]=1;
                    k--;
                }
                else color[signode]=2;
                q.push(signode);
            }
        }
    }
}

void dfs(int node){
    vis[node]=1;
    if (node == n){
        inpath[node]=1;
        return;
    }
    for(auto signode : dag[node]){
        if (!vis[signode]) dfs(signode);
        if (inpath[signode] == 1) inpath[node]=1;
    }
}

int main(){
    fast;
    swapped = false;
    cin>>n>>m>>k;
    fore(i,1,n+1) cin>>t[i];

    adj[0].pb({1,t[1]}); //start node.
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb({y,t[y]});
        adj[y].pb({x,t[x]});
    }

    if (n == 2 && k == 1){
        cout<<"impossible"<<nl;
        return 0;
    }

    if (n-k > k){
        k = n-k;
        swapped = true;
    }
    //cout<<"myk: "<<k<<nl;

    //Do daikra:
    daikra();
    /*
    cout<<"Dist:"<<nl;
    fore(i,0,n+1) cout<<i<<": "<<d[i]<<nl;
    cout<<"----"<<nl; */

    //Build the DAG.
    fore(i,0,n){
        for(auto au : adj[i]){
            ll signode = au.ot;
            ll sigw = au.c;
            if (d[i] + sigw == d[signode]) dag[i].pb(signode);
        }
    }

    //Print DAG:
    /*
    cout<<"DAG:"<<nl;
    fore(i,0,n+1){
        cout<<i<<": ";
        for(auto signode : dag[i]) cout<<signode<<" ";
        cout<<nl;
    } 
    cout<<"-----"<<nl; */

    //Find which nodes belong to the shortest path.
    dfs(0);
    /*
    fore(i,0,n+1) cout<<i<<": "<<inpath[i]<<nl;
    cout<<"------"<<nl; */

    //Assign norwegian or swedish for each node.
    topobfs();

    //Check if there are remaining norwegians:
    fore(i,1,n+1){
        if (k>0 && color[i] == 2){
            k--;
            color[i]=1;
        }
    }
    fore(i,1,n+1){
        if (swapped){
            if (color[i] == 1) color[i]=2;
            else color[i]=1;
        }
        if (color[i] == 1) cout<<"N";
        else cout<<"S";
    }
    cout<<nl;
    return 0;
}