#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pb push_back
#define vi vector <ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define ppb pop_back

using namespace std;

const ll maxn = 2e5+100;

set <ll> sta,stb;
bool vis[maxn];
vi path,g[maxn];
bool ok = false;
ll n,m;

void init(){
    ok = false;
    fore(i,1,n+1) sta.insert(i);
}

void dfs(int node){
    vis[node] = true;
    if (!ok){
        path.pb(node);
        sta.erase(node);
    }

    //cout << node << ": " << sz(sta) << " " << sz(stb) << nl;

    if (sz(sta) == sz(stb) && !ok){
        //cout << "here: " << sz(sta) << nl;
        ok = true;
    }

    for(auto &elm : g[node]){
        if (!vis[elm] && !ok){
            dfs(elm);
            if (sz(sta) == sz(stb) && !ok){
                //cout << "here: " << sz(sta) << nl;
                ok = true;
            }
        }
    }

    if (!ok){
        path.ppb();
        stb.insert(node);
    }
    return;
}

int main(){
    fast;
    cin >> n >> m;
    init();

    fore(i,0,m){
        ll x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1);

    cout << sz(path) << " " << sz(sta) << nl;
    for(auto &elm : path) cout << elm << " ";
    cout << nl;

    if (sz(sta)){
        for(auto &elm : sta) cout << elm << " ";
        cout << nl;
    }
    if (sz(stb)){
        for(auto &elm : stb) cout << elm << " ";
        cout << nl;
    }
    return 0;
}