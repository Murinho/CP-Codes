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
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+5;

struct Edge{
    ll a,b,c;
};

struct UF{
    ll pad,ran,tam;
};

Edge e[maxn];
UF uf[maxn];
ll n,m;

int bus(int u){
    if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
    return uf[u].pad;
}

void join(int u, int v){
    if (u == v) return;
    u = bus(u);
    v = bus(v);
    if (uf[u].ran < uf[v].ran){
        uf[u].pad = v;
        uf[v].tam += uf[u].tam;
    }
    else if (uf[u].ran > uf[v].ran){
        uf[v].pad = u;
        uf[u].tam += uf[v].tam;
    }
    else{
        uf[v].pad = u;
        uf[u].tam += uf[v].tam;
        uf[u].ran++;
    }
}

bool cmp(Edge e1, Edge e2){
    return e1.c < e2.c;
}

void init(){
    fore(i,0,n+1){
        uf[i].pad = i;
        uf[i].ran = 0;
        uf[i].tam = 1;
    }
}

int main(){
    fast;
    cin>>n>>m;
    init();
    fore(i,0,m) cin>>e[i].a>>e[i].b>>e[i].c;

    sort(e,e+m,cmp);

    ll ans=0;
    ll cnt=0;
    for(auto edge : e){
        if (bus(edge.a) == bus(edge.b)) continue;
        cnt++;
        ans += edge.c;
        join(edge.a,edge.b);
    }
    if (cnt == n-1) cout<<ans<<nl;
    else cout<<"IMPOSSIBLE"<<nl;
    return 0;
}