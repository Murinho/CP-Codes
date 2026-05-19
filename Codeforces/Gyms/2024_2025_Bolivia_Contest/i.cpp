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

const ll maxn = 1e5+10;
const ll mod = 1e9+7;

ll n,m,v[maxn],ans=1,cnt;
vi adj[maxn];

void dfs(int node){
    cnt++;
    v[node]=1;
    for(auto au : adj[node]){
        if (!v[au]) dfs(au);
    }
}

int main(){
    fast;
    cin>>n>>m;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fore(i,1,n+1) if (!v[i]){
        cnt=0;
        dfs(i);
        ans = (ans*cnt)%mod;
    }
    cout<<ans<<nl;
    return 0;
}