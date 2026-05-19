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

const ll maxn = 2e5+100;

ll n,m,k,p;
vi g[maxn];
int mk[maxn];
int deg[maxn];

void dfs(int node){
    mk[node] = 1;
    for(auto &signode : g[node]){
        deg[signode]++;
        if (mk[signode] == 1) continue;
        if (deg[signode] >= sz(g[signode])/2 + sz(g[signode])%2){
            dfs(signode);
        }
    }
}

int main(){
    fast;
    cin >> n >> m >> k >> p;
    fore(i,0,m){
        ll x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(p);

    if (mk[k]) cout << "leave" << nl;
    else cout << "stay" << nl;
}