#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ppb pop_back
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define vi vector<ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 2e5+100;

map <ll,ll> mp[maxn];
pii ans = {0,0};
ll n,a[maxn];
vi g[maxn];

void dfs(int anode, int node, int dep){
    for(auto &signode : g[node]){
        if (signode == anode) continue;
        dfs(node,signode,dep+1);

        if (node != 1){ // make small to large.
            if (sz(mp[node]) < sz(mp[signode])) swap(mp[node],mp[signode]);

            for(auto &au : mp[signode]){
                mp[node][au.fst] += au.snd;
                if (mp[node][au.fst] > ans.fst){
                    ans.fst = mp[node][au.fst];
                    ans.snd = au.fst - dep;
                }
                else if (mp[node][au.fst] == ans.fst && au.fst - dep < ans.snd){
                    ans.snd = au.fst - dep;
                }
            }
        }
    }
    mp[node][dep] += a[node];
    if (node != 1 && mp[node][dep] >= ans.fst){
        ans.fst = mp[node][dep];
        ans.snd = 0;
    }
}

int main(){
    fast;
    cin >> n;
    fore(i,2,n+1) cin >> a[i];

    fore(i,1,n){
        ll x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1,1,0);

    cout << ans.fst << " " << ans.snd + 1 << nl;

    return 0;
}