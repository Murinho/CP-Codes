#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 5005;
vector <pii> g[maxn];
ll deg[maxn],dp[maxn];
ll n,m;

void bfs(){
    queue < ll > q;
    fore(i,1,n+1){
        if (deg[i] == 0){
            q.push(i);
            dp[i] = 0;
        }
    }

    while(sz(q)){
        ll node = q.front();
        q.pop();

        for(auto &[signode, w] : g[node]){
            dp[signode] = max(dp[signode],dp[node] + w);
            deg[signode]--;
            if (deg[signode] == 0){
                q.push(signode);
            }
        }
    }
}

int main(){
    fast;
    cin >> n >> m;

    fore(i,0,m){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].pb({y,z});
        deg[y]++;
    }

    bfs();

    ll ans = 0;

    fore(i,1,n+1) ans = max(ans,dp[i]);

    cout << ans << nl;
    return 0;
}