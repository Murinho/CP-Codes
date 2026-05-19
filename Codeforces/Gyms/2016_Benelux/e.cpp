#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define eb emplace_back
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 1e5+100;
const ll inf = 1e15;

ll n,m,pct;
ll d[maxn];
vector <pii> g[maxn];

void init(){
    fore(i,0,n+1) d[i] = inf;
}

void daikra(ll tope){
    init();
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    d[1] = 0;
    pq.push({0,1});
    while(sz(pq)){
        auto [dis,node] = pq.top();
        pq.pop();

        if (dis != d[node]) continue;

        for(auto &[signode,w] : g[node]){
            if (w > tope) continue;
            if (d[signode] > d[node] + w){
                d[signode] = d[node] + w;
                pq.push({d[signode],signode});
            }
        }
    }
}

int main(){
    fast;
    cin >> n >> m >> pct;
    fore(i,0,m){
        ll x,y,z;
        cin >> x >> y >> z;
        g[x].pb({y,z});
        g[y].pb({x,z});
    }

    daikra(inf);

    ll mindis = d[n];
    ll maxdis = d[n] + ((pct * d[n]) / 100);
    
    ll l = 1;
    ll r = inf;
    while(l < r){
        ll mid = (l+r)/2;
        daikra(mid);
        if (d[n] <= maxdis) r = mid;
        else l = mid+1;
    }

    cout << l << nl;
    return 0;
}