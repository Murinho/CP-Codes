#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using T=array<ll,2>;

const int N=1e5+5;
vector<int>p(N),vs(N);
vector<pair<int,int>>ad[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<m;i++){
        int u,v,q;
        cin>>u>>v>>q;
        u--,v--;
        ad[u].push_back({v,q});
        ad[v].push_back({u,q});
    }
    priority_queue<T,vector<T>,greater<T>>q;
    q.push({0,0});
    ll r=0;
    while(!q.empty()){
        auto [s,u]=q.top();
        q.pop();
        if(vs[u])continue;
        vs[u]=1;
        r+=s*p[u];
        for(auto [v,w]:ad[u])q.push({s+w,v});
    }
    cout<<r<<"\n";
}