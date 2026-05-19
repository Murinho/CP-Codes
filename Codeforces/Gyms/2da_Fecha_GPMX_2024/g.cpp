#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e6+15;
vi adj[maxn];
ll subt[maxn];

void dfs(int anode, int node){
    subt[node] = 1;
    for(auto au : adj[node]){
        if (au != anode){
            dfs(node,au);
            subt[node] += subt[au];
        }
    }
}

int main(){
    fast;
    ll n;
    cin>>n;
    fore(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,1);
    ll mx = 0, cnt = 1;
    fore(i,1,n+1){
        ll aux = n-subt[i];
        if (aux*subt[i] > mx){
            mx = aux*subt[i];
            cnt = 1;
        }
        else if (aux*subt[i] == mx){
            cnt++;
        }
    }
    cout<<mx<<" "<<cnt<<nl;
    return 0;
}