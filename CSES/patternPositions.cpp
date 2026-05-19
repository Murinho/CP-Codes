#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;
 
const int MAXN = 1e6+10;
const int INF = 1e9+7;
 
map<char, int> to[MAXN];
string a[MAXN];
int lnk[MAXN],vis[MAXN],leaf[MAXN],mynode[MAXN];
ll que[MAXN];
ll sz = 1;
ll endlink[MAXN]; 

int add_str(string s) {
    int v = 0;
    for(char c: s) {
        if(!to[v].count(c)) to[v][c] = sz++;
        v = to[v][c];
    }
    leaf[v]++;
    return v;
}
void push_links() {
    queue<int> q({0});
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto [c,u]: to[v])
        {
            int j = lnk[v];
            while(j && !to[j].count(c)) j=lnk[j];
            if(to[j].count(c) && to[j][c]!=u) lnk[u] = to[j][c];
            endlink[u] = leaf[lnk[u]]>0?lnk[u]:endlink[lnk[u]];
            q.push(u);
        }
    }
}
void walk(string s) { 
    int v=0;
    fore(i,0,sz(s)) {
        char c=s[i];
        while(v && !to[v].count(c)) v=lnk[v];
        if(to[v].count(c)) v=to[v][c]; 
        for(int u=v;u;u=endlink[u]){
            //i: donde termina la palabra.
            if (vis[u] == -1) vis[u] = i; //save the first moment that the Aho-node is reached.
        }  
    }
}
 
 
int main() {
    fast;
    string s;
    int n;
    cin>>s;
    cin>>n;
    //set all visited as -1
    fore(i,1,MAXN) vis[i] = -1;
    for (int i = 1; i<=n; i++){
        cin>>a[i];
        mynode[i] = add_str(a[i]);
    }
    push_links();
    walk(s);

    fore(i,1,n+1){
        if (vis[mynode[i]] == -1) cout<<-1<<nl;
        else cout<<vis[mynode[i]]-sz(a[i])+2<<nl;
    }
    return 0;
}
