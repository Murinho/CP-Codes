#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
 
using namespace std;
 
const ll maxn = 2510;
const ll INF = 1e9;
 
ll n,m,ans=maxn;
ll d[maxn][maxn];
vi adj[maxn];
 
void init(){
    fore(i,0,n+1) fore(j,0,n+1) d[i][j]=INF;
}
 
void bfs(int stnode){
    queue <int> q;
    q.push(stnode);
    d[stnode][stnode]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto signode : adj[node]){
            if (d[stnode][node]+1 == d[stnode][signode]) ans = min(ans,d[stnode][signode] + d[stnode][node]-1);
            else if (d[stnode][node] == d[stnode][signode]) ans = min(ans,(d[stnode][signode]*2)-1);
            else if (d[stnode][signode] == INF){
                d[stnode][signode] = d[stnode][node]+1;
                q.push(signode);
            }
        }
    }
}
 
int main(){
    fast;
    cin>>n>>m;
    init();
    fore(i,1,m+1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
 
    fore(i,1,n+1) bfs(i);
 
    cout<<(ans == maxn ? -1 : ans)<<nl;
    return 0;
}