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

const ll maxn = 3e5+100;

ll n,lab[maxn],cnt=3,na=-1,nb=-1,nc=-1;
vi adj[maxn];

void dfs(int anode, int node){
    if (!lab[node]){
        lab[node]=cnt;
        cnt++;
    }
    for (auto au : adj[node]){
        if (au != na && au != nc && anode != au) dfs(node,au);
    }
}   

int main(){
    fast;
    cin>>n;
    fore(i,1,n){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll mx=0;
    //find two non-leaf nodes:
    fore(i,1,n+1){
        mx = max(mx,sz(adj[i]));
        if (sz(adj[i]) <= 1) continue;
        for(auto au : adj[i]){
            if (sz(adj[au]) > 1){
                na=i;
                nb=au;
                break;
            }
        }
    }
    if (mx == n-1) cout<<"NO"<<nl;
    else{
        for(auto au : adj[na]){
            if (au != nb){
                nc = au;
                break;
            }
        }
        //cout<<na<<" "<<nb<<" "<<nc<<nl;
        lab[na]=1;
        lab[nc]=2;
        cnt=3;
        dfs(na,na);
        dfs(nc,nc);
        cout<<"YES"<<nl;
        fore(i,1,n+1) cout<<lab[i]<<" ";
        cout<<nl;
    }
    return 0;
}