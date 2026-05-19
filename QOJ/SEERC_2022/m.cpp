#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using T=pair<pair<ll,ll>,int>;

struct st{
    bool operator()(const T&x, const T&y) const {
        __int128_t a,s;
        
        a=x.first.first,s=x.first.second;
        __int128_t n1=s-a,d1=a*(s+1);
        
        a=y.first.first,s=y.first.second;
        __int128_t n2=s-a,d2=a*(s+1);
        
        return n1*d2<n2*d1;
    }
};

const int N=2e5+5;
int n,x;
vector<int>ad[N],c(N),res(N);
priority_queue<T,vector<T>,st>q;

int dfs(int u,int p){
    if(u==n)return 1;
    int f=0;
    ll a=0,s=0;
    for(int v:ad[u]){
        if(v==p)continue;
        if(dfs(v,u)){
            a=c[v];
            f=v;
        }
        s+=c[v];
    }
    if(f){
        q.push({{a,s},f});
        return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n-1;i++){
        int u,v;  
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    dfs(1,0);
    for(;x--;){
        auto [v,p]=q.top();
        q.pop();
        q.push({{v.first+1,v.second+1},p});
        res[p]++;
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";
    cout<<"\n";
}