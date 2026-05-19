#include <bits/stdc++.h>
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
#define RB(x) (x<n?r[x]:0)

using namespace std;

const ll maxn = 2e5+100;
const ll INF = 1e13;
 
struct Query{
    ll s,t,id;
};

struct Edge{
    ll ot,w;
};

ll n,q;
ll vis[maxn],qres[maxn],res[maxn],root;
vector <Edge> adj[maxn];
pii a[maxn][2]; //{shortest path, winner leaf}.
vector <Query> qys[maxn];

void dfs(int anode, int node){   // will return the {shortest path, winner leaf}.
    a[node][0].fst = a[node][0].snd = a[node][1].fst = a[node][1].snd = INF;
    bool leaf=true;
    for(auto au : adj[node]){
        if (au.ot != anode){
            leaf=false;
            dfs(node,au.ot);
            pii branch;
            branch.fst = a[au.ot][0].fst + au.w;
            branch.snd = a[au.ot][0].snd;
            if (branch < a[node][0]){
                a[node][1] = a[node][0];
                a[node][0] = branch;
            }
            else if (branch < a[node][1]){
                a[node][1] = branch;
            }
        }       
    }
    if (leaf){
        a[node][0].fst = 0, a[node][0].snd = node;
    }
    //cout<<node<<" --> "<<a[node][0].fst<<" "<<a[node][0].snd<<nl;
    res[a[node][0].snd]++;
}   

void dfs_reroot(int anode, int node, pii up_best){
    if (up_best < a[node][0]){ 
        res[a[node][0].snd]--; // update the current conquerors answers.
        res[up_best.snd]++;
    } 

    //cout<<"node: "<<node<<nl;
    //cout<<"up_best: "<<up_best.fst<<" "<<up_best.snd<<nl;
    //fore(i,1,n+1) cout<<res[i]<<" ";
    //cout<<nl;

    // Then answer the queries:
    for(auto qy : qys[node]) qres[qy.id]=res[qy.s];

    // Do the rerooting.
    for(auto au : adj[node]){
        ll signode = au.ot;
        ll w = au.w;
        if (anode != signode){
            pii new_up_best;
            vector <pii> undo; // {node,add_val}
            if (a[signode][0].snd == a[node][0].snd){ // if going in the branch of the best leaf chose the second best leaf or up_best.
                if (up_best < a[node][0]) new_up_best = up_best;
                else{
                    res[a[node][0].snd]--;
                    undo.pb({a[node][0].snd,+1});
                    if (up_best < a[node][1]){
                        res[up_best.snd]++;
                        undo.pb({up_best.snd,-1});
                        new_up_best = up_best;
                    }
                    else if (a[node][1] < up_best){
                        res[a[node][1].snd]++;
                        undo.pb({a[node][1].snd,-1});
                        new_up_best = a[node][1];
                    }
                }
            }
            else{ // else choose the best leaf.
                if (up_best < a[node][0]) new_up_best = up_best;
                else new_up_best = a[node][0];
            }
            new_up_best.fst += w;
            dfs_reroot(node,signode,new_up_best);

            // Discard the changes if up_best became the conqueror of the current node:
            for(auto au : undo) res[au.fst] += au.snd;
        }
    }
    if (up_best < a[node][0]){ 
        res[a[node][0].snd]++; // update the current conquerors answers.
        res[up_best.snd]--;
    } 
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n-1){
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    cin>>q;
    fore(i,1,q+1){
        Query qy;
        cin>>qy.s>>qy.t;
        qy.id=i;
        qys[qy.t].pb(qy); // push it where it ends.
    }   
    if (n == 2){ //special case.
        fore(i,1,q+1) cout<<1<<nl;
        return 0;
    }
    fore(i,1,n+1) if (sz(adj[i])>1){ // choose a node that is not a leaf.
        root = i;
        break;
    }
    dfs(root,root);

    dfs_reroot(root,root,{INF,INF});
    
    // Query answers:
    fore(i,1,q+1) cout<<qres[i]<<nl;

    return 0;
}