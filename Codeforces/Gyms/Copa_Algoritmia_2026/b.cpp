#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>

using namespace std;

ll n;

void bfs(vector<vector<ll>> &mat, vector<ll> &cont, vector<ll> &maxx){
    queue<ll> q;
    
    for(ll i = 0; i<n; i++){
        if(cont[i] == 0){
            q.push(i);
            maxx[i] = 1;
        }
    }

    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        for(auto next : mat[curr]){
            cont[next]--;
            maxx[next] = max(maxx[next], maxx[curr] + 1);
            if(cont[next] == 0){
                q.push(next);
            }
        }
    }
}

int main(){
    fast;
    cin>>n;
    vector<vector<ll>> mat(n);
    vector<ll> p(1e5, -1), cont(n, 0), maxx(n, 0);
    for(ll i = 0; i<n; i++){
        ll k; cin>>k;
        while(k--){
            ll m; cin>>m;
            m--;
            if(p[m] != -1){
                mat[i].pb(p[m]);
                cont[p[m]]++;
            }
            p[m] = i;
        }
    }

    bfs(mat, cont, maxx);
    ll ans = 0;
    for(auto i:maxx){
        ans = max(ans, i);
    }

    cout<<ans<<endl;
}