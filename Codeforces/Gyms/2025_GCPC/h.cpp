#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

const ll maxn = 1e5+100;

ll n,v[maxn][2];
vi g[maxn];
ll m,a,b;

void dfs(int node, int layer){
    v[node][layer] = 1;
    for(auto &signode : g[node]){
        if (v[signode][layer]) continue;
        dfs(signode, layer);
    }
}

int main(){
    fast;
    cin >> n >> m;
    fore(i,0,m){
        ll x,y;
        cin >> x >> y;
        g[x].pb(y);
    }

    cin >> a >> b;
    dfs(a,0);
    dfs(b,1);

    fore(i,1,n+1){
        if (v[i][0] && v[i][1]){
            cout << "yes" << nl;
            cout << i << nl;
            return 0;
        }
    }
    cout << "no" << nl;
    return 0;
}