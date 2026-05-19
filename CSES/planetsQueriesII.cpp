#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
 
using namespace std;
 
const ll maxn = 2e5+5;
const ll loga = 18;

int n,color[maxn],dpar[maxn],cycolor[maxn],cypos[maxn],cysz[maxn],cnt=0,q;
bool indeg[maxn];
int up[maxn][loga],depth[maxn],upo[maxn][loga];
vector <int> mradj[maxn];

void dfs(int u, int p){
    if (color[u] == 2) return;
    if (color[u] == 1){
        vi v;
        cnt++;
        int cur = p;
        cycolor[cur]=cnt;
        v.pb(cur);
        while(cur != u){
            cur = dpar[cur];
            cycolor[cur]=cnt;
            v.pb(cur);
        }
        cur=0;
        rofe(i,sz(v),0) cypos[v[i]]=cur, cur++;
        cysz[cnt]=sz(v); //save the size of the cycole.
        return;
    }
    dpar[u]=p;
    color[u]=1;
    if (upo[u][0] != u) dfs(upo[u][0],u);
    color[u]=2;
}

void binlift(){
    fore(i,1,loga){
        fore(j,1,cnt+1) up[j][i] = up[up[j][i-1]][i-1];
        fore(j,1,n+1) upo[j][i] = upo[upo[j][i-1]][i-1];
    }
}

void dfs_depth(int node, int dep){
    depth[node] = dep;
    for(auto signode : mradj[node]){
        dfs_depth(signode,dep+1);
    }
}

int main(){
    fast;
    cin>>n>>q;
    fore(i,1,n+1){
        cin>>upo[i][0];
    }

    fore(i,1,n+1) if (!color[i]) dfs(i,0);

    fore(i,1,n+1) if (!cycolor[i]){
        cnt++; 
        cycolor[i]=cnt; //color of the cycle.
        cysz[cnt]=1; //size of the cycle.
    }
    
    //Merge nodes into its cycles and create new graph:
    fore(i,1,n+1){
        int signode = upo[i][0];
        if (cycolor[i] != cycolor[signode]){
            up[cycolor[i]][0] = cycolor[signode];
            mradj[cycolor[signode]].pb(cycolor[i]); //merge reverse adjancecy list.
            indeg[cycolor[i]]=1;
        }
    }

    //Compute the depths of the merged reversed graph:
    fore(i,1,cnt+1) if (!indeg[i] && !depth[i]) dfs_depth(i,1);

    //Compute binary lifting.
    binlift();
 
    while(q--){
        int x,y,cx,cy;
        cin>>x>>y; //from x to y.
        if (x == y){
            cout<<0<<nl;
            continue;
        }
        //Change the indices to cycle cnt indexing.
        cx = cycolor[x];
        cy = cycolor[y];
        int ans=0;
        if (cx == cy){
            if (cypos[x] <= cypos[y]) ans += (cypos[y]-cypos[x]);
            else{
                ll tam = cysz[cycolor[x]];
                ans += (tam-(cypos[x]-cypos[y]));
            }
            cout<<ans<<nl;
            continue;
        }
        if (depth[cx] <= depth[cy]){
            cout<<-1<<nl;
            continue;
        }
        int dif = depth[cx]-depth[cy]-1;
        ans=dif+1;
        rofe(i,loga,0){
            if ((1ll<<i) <= dif){
                dif -= (1ll<<i);
                cx = up[cx][i];
                x = upo[x][i];
            }
        }
        cx = up[cx][0];
        x = upo[x][0];
        if (cx != cy){
            cout<<-1<<nl;
            continue;
        }
        else{
            if (cypos[x] <= cypos[y]) ans += (cypos[y]-cypos[x]);
            else{
                ll tam = cysz[cycolor[x]];
                ans += (tam-(cypos[x]-cypos[y]));
            }
            cout<<ans<<nl;
        }
    }
    return 0;
}