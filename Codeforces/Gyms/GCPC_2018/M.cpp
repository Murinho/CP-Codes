#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())
#define ld long double

using namespace std;

const ll maxn = 510;
const ll maxq = 1e5+100;
const ll maxv = 1e6+5;

struct UF{
    int pad,ran;
    set <ll> st;
};

UF uf[maxn*maxn];
ll qans[maxq],curtime=1,n,m,q;
ll a[maxn][maxn];
vector < pii > b[maxv];
int mov[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int bus(int u){
    if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
    return uf[u].pad;
}

void unir(int u, int v){
    u = bus(u);
    v = bus(v);

    if (u == v) return;

    if (uf[u].ran < uf[v].ran) swap(u,v);

    if (uf[u].ran == uf[v].ran) uf[u].ran++;

    uf[v].pad = u;
    if (sz(uf[u].st) < sz(uf[v].st)) swap(uf[u].st, uf[v].st);

    for(auto &elm : uf[v].st){
        if (uf[u].st.count(elm)) qans[elm] = curtime;
        else uf[u].st.insert(elm);
    }
    return;
}

bool inside(int x, int y){
    if (0 <= x && x < n && 0 <= y && y < m) return true;
    return false;
}

void init(){
    fore(i,0,n*m){
        uf[i].pad = i;
        uf[i].ran = 0;
        uf[i].st.clear();
    }
}

int get_index(int x, int y){
    return (x*m) + y;
}

int main(){
    fast;
    cin >> n >> m >> q;
    init();
    fore(i,0,n){
        fore(j,0,m){    
            cin >> a[i][j];
            b[a[i][j]].pb({i,j});
        }
    }

    fore(i,1,q+1){
        ll x,y,x2,y2;
        cin >> x >> y >> x2 >> y2;
        x--, y--;
        x2--, y2--;
        if (x == x2 && y == y2){
            qans[i] = a[x][y];
        }
        else{
            ll pos1 = get_index(x,y);
            ll pos2 = get_index(x2,y2);
            uf[pos1].st.insert(i);
            uf[pos2].st.insert(i); 
        }
    }

    while(curtime < maxv){
        // join the current values of the current time to the rest of the UnionFind.
        for(auto &[x,y] : b[curtime]){
            ll pos1 = get_index(x,y);
            fore(i,0,4){
                int sx = x + mov[i][0];
                int sy = y + mov[i][1];
                if (inside(sx,sy) && a[sx][sy] <= a[x][y]){
                    ll pos2 = get_index(sx,sy);
                    unir(pos1,pos2);
                }
            }
        }
        curtime++;
    }

    fore(i,1,q+1) cout << qans[i] << nl;
    return 0;
}