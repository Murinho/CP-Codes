#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define vi vector<ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 2e5+100;
const ll inf = 1e18;

ll u[maxn],c[maxn];
vi g[maxn];
ll ans = inf;
ll n;

void dfs(int node, ll curmx){
    ll newmx = c[node] - u[node];
    newmx = max(newmx,curmx - u[node]);
    ans = min(ans,newmx);
    for(auto &signode : g[node]){
        dfs(signode,newmx);
    }
}

int main(){
    fast;
    cin >> n >> c[0];
    fore(i,1,n+1){
        ll x;
        cin >> x >> c[i] >> u[i];
        g[x].pb(i);
    }

    dfs(0,0);

    cout << max(ans,0ll) << nl;
    return 0;
}