#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) a.size()
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+5;
const ll mod = 1e9+7;
const ll INF = 1e12;

vector < pii > adj[maxn];
ll n,m,k,f[maxn];
vi d;

void facts(){
    f[0]=1;
    fore(i,1,maxn) f[i] = (f[i-1]*i)%mod;
}

ll expo(ll x, ll pw){
    ll res = 1;
    while(pw > 0){
        if (pw&1) res = (res*x)%mod;
        x = (x*x)%mod;
        pw >>=1;
    }
    return res;
}

ll nCk(ll a, ll b){
    if (a-b < 0) return 0;
    b = (f[b]*f[a-b])%mod;
    ll inverse = expo(b,mod-2);
    ll res = (f[a]*inverse)%mod;
    return res;
}

void daikra(){
    d.resize(n,INF);
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    d[0]=0;
    pq.push({d[0],0});
    while(!pq.empty()){
        ll w = pq.top().fst;
        ll node = pq.top().snd;
        pq.pop();
        if (d[node] != w) continue;
        for(auto au : adj[node]){
            ll signode = au.fst;
            ll sigw = au.snd;
            if (d[signode] > d[node] + sigw){
                d[signode] = d[node] + sigw;
                pq.push({d[signode],signode});
            }
        }
    }
}


int main(){
    fast;
    cin>>n>>m>>k;
    facts();
    fore(i,0,m){
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }

    daikra();

    sort(ALL(d));

    ll ans=0;
    ll denom = nCk(n-1,k); // n-1 nodos, puedo poner k amigos.
    //cout<<"Denom: "<<denom<<nl;
    ll denom_inve = expo(denom,mod-2);
    fore(i,1,sz(d)){
        ll rems = sz(d)-i-1;
        ll nume = nCk(rems,k-1);
        ll aux = (nume*denom_inve)%mod;
        aux = (aux*d[i]);
        ans += aux;
        ans %= mod;
    }
    cout<<ans<<nl;
    return 0;
}