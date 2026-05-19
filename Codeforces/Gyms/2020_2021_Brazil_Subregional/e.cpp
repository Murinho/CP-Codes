#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const int maxn = 1e5+5;
const int loga = 17;
const int INF = 1e9+7;

int n,m,sum[maxn],up[maxn][loga],a[maxn],dep[maxn],fen[maxn],pot[maxn];
vi adj[maxn],py[maxn];

void init(){
    a[0]=INF;
    fore(i,0,loga) pot[i]=(1ll<<i);
}

void add(int x, int v){
    while(x < maxn){
        fen[x] += v;
        x += lsb(x);
    }
}

int get(int x){
    int fq = 0;
    while(x>0){
        fq += fen[x];
        x -= lsb(x);
    }
    return fq;
}

void dfs(int node, int prof){
    dep[node] = prof;
    for(auto au : adj[node]){
        dfs(au,prof+1);
    }
}

void binlift(){
    fore(i,1,loga){
        fore(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
    }
}

ll getAnce(ll x, ll k){
    if (k==0) return x;
    for(int i = loga-1; i>=0; i--){
        if (pot[i] <= k){
            k -= pot[i];
            x = up[x][i];
        }
    }
    return x;
}

void dfsDown(int node){
    //push the parties to the fenwick tree.
    for(auto au : py[node]){
        add(au,1); //adding the lower bound.
    }
    //Get the parties:
    sum[node] += get(a[node]);
    //explore.
    for(auto au : adj[node]){
        dfsDown(au);
    }
    //remove the parties from the fenwick tree.
    for(auto au : py[node]){
        add(au,-1); 
    }
}


int main(){
    fast;
    int x,y,la,ra,l,r,mid,ance;
    cin>>n>>m;
    init();
    cin>>x>>y;
    a[1]=x;
    up[1][0]=0; 
    fore(i,2,n+1){
        cin>>x>>y;
        a[i]=x;
        up[i][0]=y;
        adj[y].pb(i); //from dad to son.
    }
    dfs(1,1); //discover the depths of the nodes.
    binlift(); 
    while(m--){
        cin>>x>>la>>ra;
        l = 0;
        r = dep[x]-1;
        while(l < r){
            mid = (l+r+1)/2;
            ance = getAnce(x,mid);
            if (a[ance] <= ra) l = mid;
            else r = mid-1;
        }
        py[getAnce(x,l)].pb(la);
    }
    dfsDown(1); //getting the answers going down.
    //Print answers:
    fore(i,1,n+1) cout<<sum[i]<<" ";
    cout<<nl;
    return 0;
}