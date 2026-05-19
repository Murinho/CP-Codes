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
#pragma GCC target("popcnt")

using namespace std;

const ll maxn = 5e4+10;
const ll loga = 16;

vi radj[maxn];
ll indeg[maxn];
bool vis[maxn];
ll n,m;
bitset<maxn>ans[maxn];

void bfs(){
    queue <int> q;
    fore(i,1,n+1) if (!indeg[i]){
        ans[i].set(i);
        q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto signode : radj[node]){
            ans[signode] |= ans[node];
            indeg[signode]--;
            if (!indeg[signode]){
                ans[signode].set(signode);
                q.push(signode);
            }
        }
    }
}

int main(){
    fast;
    cin>>n>>m;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        radj[y].pb(x);
        indeg[x]++;
    }
    bfs();
    fore(i,1,n+1) cout<<ans[i].count()<<" ";
    return 0;
}