#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'

using namespace std;

const ll maxn = 1e5+100;
const ll loga = 17;
const ll inf = 1e9+7;

ll n,m,up[maxn][loga];
ll d[maxn];
ll ba,bb,ans;
vi g[maxn];

void init(){
    ans = inf;
    fore(i,0,n+1) d[i] = -1;
}

void build(int id){ // build the binary lifting for a given node
    fore(i,1,loga){
        up[id][i] = up[up[id][i-1]][i-1];
    }
}

ll lca(int x, int y){
    if (d[x] < d[y]) swap(x,y);

    ll dif = d[x] - d[y];

    rofe(i,loga,0){
        if (dif & (1ll<<i)) x = up[x][i];
    }

    if (x == y) return x;

    rofe(i,loga,0){
        if (up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}

void bfs(){
    queue <ll> q;
    d[1] = 1;
    q.push(1);
    while(sz(q)){
        ll node = q.front();
        q.pop();

        build(node); // construir su binlift.

        for(auto &signode : g[node]){
            if (d[signode] == -1){
                d[signode] = d[node] + 1;
                up[signode][0] = node;
                q.push(signode);
            }
            else if (node != 1 && signode != 1){
                ll lcan = lca(node,signode);
                if (lcan != node && lcan != signode && ans > d[node] + d[signode]){
                    ans = d[node] + d[signode];
                    ba = node;
                    bb = signode;
                }
            }
        }
    }
}

void get_path(int node, int tope, vi &path){
    while(node != tope){
        path.pb(node);
        node = up[node][0];
    }
}

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,0,m){
        ll x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    bfs();

    if (ans == inf) cout << "impossible" << nl;
    else{
        cout << ans << nl;
        // cout << ba << " " << bb << nl;
        ll lcan = lca(ba,bb);
        vi p1,p2,p3;
        get_path(lcan,1,p1);
        get_path(ba,lcan,p2);
        get_path(bb,lcan,p3);

        cout << 1 << " ";

        reverse(ALL(p1));
        for(auto &node : p1) cout << node << " ";
        reverse(ALL(p1));

        reverse(ALL(p2));
        for(auto &node : p2) cout << node << " ";
        reverse(ALL(p2));

        for(auto &node : p3) cout << node << " ";

        for(auto &node : p1) cout << node << " ";

        cout << 1 << nl;
    }
    return 0;
}