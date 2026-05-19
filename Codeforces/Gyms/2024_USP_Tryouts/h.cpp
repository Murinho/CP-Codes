#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(), u.end()
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second;

using namespace std;

const ll INF = 1e18;
const ll maxn = 2e5+100;

struct Edge{
    ll x,y;
};

vector < pii > adj[maxn];
ll n,m,k,d[maxn];
Edge e[maxn];


void daikra(){
    d[1] = k;
    fore(i,2,n+1) d[i]=INF;
    priority_queue < pii, vector < pii >, greater < pii > > pq;
    pq.push({d[1],1}); //{dist,node}.
    while(!pq.empty()){
        pii p = pq.top();
        ll w = p.fst;
        ll node = p.snd;
        pq.pop();
        if (d[node] != w) continue;
        for(auto au : adj[node]){
            ll signode = au.fst;
            ll ed = au.snd;
            ll cylen = e[ed].x + e[ed].y;
            ll arv;
            if ((w%cylen) < e[ed].x) arv = d[node];
            else arv = d[node] + (cylen - (w%cylen));
            if (d[signode] > arv){
                d[signode] = arv;
                pq.push({d[signode],signode});
            }
        }
    }
}

int main(){
    fast;
    cin>>n>>m>>k;
    fore(i,0,m){
        ll na,nb,x,y;
        cin>>na>>nb>>x>>y;
        adj[na].pb({nb,i}); //next node and edge index.
        adj[nb].pb({na,i});
        e[i] = {x,y};
    }
    daikra();
    cout<<d[n]<<nl;
    return 0;
}   