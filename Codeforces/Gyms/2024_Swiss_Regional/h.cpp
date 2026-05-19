#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=1e9+7;
const int N=1005;

vector<int>ad[N],on(N);
vector<ll>v(N);
vector<array<ll,4>>ad2[N];

int dis(int u,int p,int d){
    if(u==d)return 1;
    for(int v:ad[u])if(v!=p){
        if(int t=dis(v,u,d))return t+1;
    }
    return 0;
}

bool dfs(int u,int p,int d,int k,int c,int m){
    if(u==d)return 1;
    for(int v:ad[u])if(v!=p){
        if(dfs(v,u,d,k,c+k,m)){
            ad2[u].push_back({v,k,c,m});
            return 1;
        }
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,a,b,x,y,k;
    cin>>n>>m>>a>>b;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    for(int i=0;i<m;i++){
        cin>>x>>y>>k;
        int d=dis(x,0,y)-1;
        dfs(x,0,y,k,0,k*d*2);
        dfs(y,0,x,k,k*d,k*d*2);
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
    q.push({0,a});
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        if(on[t.second])continue;
        on[t.second]=1;
        v[t.second]=t.first;
        for(auto w:ad2[t.second]){
            ll s=t.first+w[1];
            if(t.first%w[3]<=w[2])s+=w[2]-t.first%w[3];
            else s+=w[2]+w[3]-t.first%w[3];
            q.push({s,w[0]});
        }
    }
    cout<<(on[b]?v[b]:-1);
    return 1<<32;
}