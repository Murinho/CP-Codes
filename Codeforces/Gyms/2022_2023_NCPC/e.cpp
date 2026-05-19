#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
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

const ll INF = 1e18;
const ll maxn = 3010;
ll n,m,ans=0;
ll mn=INF;
vi adj[maxn];

void bfs1(int x){
    vi dist(n+1,INF);
    dist[x]=0;
    queue <ll> q;
    q.push(x);
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for (auto au : adj[node]){
            if (dist[au] == INF){
                dist[au] = dist[node] + 1;
                q.push(au);
            }
            else{
                if (dist[au] >= dist[node]){
                    mn=min(mn,dist[au] + dist[node] + 1);
                }
            }
        }
    }
}

void bfs2(int x){
    vi dist(n+1,INF);
    dist[x]=0;
    queue <int> q;
    q.push(x);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto au : adj[node]){
            if (dist[au] == INF){
                dist[au] = dist[node] + 1;
                q.push(au);
            }
        }
    }
    if (mn%2 == 0){ //find a node at mn/2 distance.
        fore(i,1,n+1){
            if (dist[i] == mn/2){
                ll res = 0;
                for(auto au : adj[i]){
                    if (dist[au] == dist[i]-1) res++;
                }
                ans += res*res-res;
            }
        }
    }
    else{
        fore(i,1,n+1){
            if (dist[i] == mn/2){
                ll res = 0;
                for(auto au : adj[i]){
                    if (dist[i] == dist[au]) res++;
                }
                ans += res;
            }
        }
    }
}

int main() {
    fast;
    cin>>n>>m;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fore(i,1,n+1) bfs1(i);
    fore(i,1,n+1) bfs2(i);

    ans /= (2*mn);
    cout<<ans<<nl;
    return 0;
}