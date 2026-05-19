#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5+5;
ll res=0;
vector<int>c(N);
vector<pair<int,int>>ad[N];

void dfs(int u,int p){
    for(auto [v,w]:ad[u]){
        if(v==p)continue;
        dfs(v,u);
        if(c[v])res+=w,c[u]^=1;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        ad[a].push_back({b,w});
        ad[b].push_back({a,w});
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        c[a]^=1;
        c[b]^=1;
    }
    dfs(1,0);
    cout<<res<<"\n";
}