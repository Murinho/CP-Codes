#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fst first
#define snd second
#define pb push_back

using namespace std;

const ll maxn = 1e6+100;

struct UF{
    ll pad,ran,tam;
};

UF uf[maxn];
ll n,m,res[maxn];
vi g[maxn];

ll bus(int u){
    if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
    return uf[u].pad;
}

void join(int u, int v){
    u = bus(u);
    v = bus(v);

    if (u == v) return;

    if (uf[u].ran < uf[v].ran) swap(u,v);

    if (uf[u].ran == uf[v].ran) uf[u].ran++;
    uf[v].pad = u;
    uf[u].tam += uf[v].tam;

    return;
}

void init(){
    fore(i,0,n){
        uf[i].pad = i;
        uf[i].ran = 0;
        uf[i].tam = 1;
    }
}

ll og[maxn];
vector <pii> a;

int main(){
    fast;
    cin >> n >> m;
    init();
    fore(i,0,n){
        ll x;
        cin >> og[i];
        a.pb({og[i],i});
    }

    fore(i,0,m){
        ll x,y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    sort(ALL(a));

    for(int i = 0; i<n; i++){
        int pos = i;
        while(pos < n && a[pos].fst == a[i].fst) pos++;

        for(int j = i; j<pos; j++){
            ll id = a[j].snd;

            for(auto &signode : g[id]){
                if (og[signode] <= og[id]) join(id,signode);
            }
        }

        for(int j = i; j<pos; j++){
            ll id = a[j].snd;
            res[id] = uf[bus(id)].tam;
        }

        i = pos-1;
    }

    fore(i,0,n) cout << res[i] << nl;
    return 0;
}