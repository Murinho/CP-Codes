#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

const ll maxn = 4e5+100;
map <char,int> to[maxn];
string a[maxn];
int lnk[maxn],sz=1;
ll que[maxn],endlink[maxn];
vi leaf[maxn],ans[maxn];
ll len[maxn];
bool vis[maxn];
vi g[maxn];

void add_str(string &s, int id)
{
    int v = 0;
    for(char c : s){
        if (!to[v].count(c)) to[v][c] = sz++;
        v = to[v][c];
    }
    leaf[v].pb(id);
}

void push_links(){
    queue <int> q({0});
    while(sz(q)){
        int v = q.front();
        q.pop();
        for(auto [c,u] : to[v]){
            int j = lnk[v];
            while(j && !to[j].count(c)) j = lnk[j];
            if (to[j].count(c) && to[j][c] != u) lnk[u] = to[j][c];

            endlink[u] = leaf[lnk[u]].size() > 0 ? lnk[u] : endlink[lnk[u]];
            q.push(u);
        }
    }
}

void walk(string &s){
    int v = 0;
    fore(i,0,sz(s)){
        char c = s[i];
        while(v && !to[v].count(c)) v = lnk[v];
        if (to[v].count(c)) v = to[v][c];
        for(int u=v; u; u=endlink[u]) for (auto &x : leaf[u]){
            g[i-len[x]+1].pb(i+1);
        }
    }
}

void dfs(int node){
    vis[node] = true;
    for(auto &signode : g[node]){
        if (!vis[signode]){
            dfs(signode);
        }
    }
}

int main(){
    fast;
    string s;
    cin >> s;
    ll n;
    cin >> n;
    fore(i,0,n){
        cin >> a[i];
        add_str(a[i],i);
        len[i] = sz(a[i]);
    }
    push_links();
    walk(s);

    dfs(0);

    if (vis[sz(s)]) cout << "yes" << nl;
    else cout << "no" << nl;
    return 0;
}