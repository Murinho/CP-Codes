#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5+5;
vector<int>ad[N];
vector<vector<int>>vs(N);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,t,a,b;
    cin>>n>>m>>t;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ad[b].push_back(a);
    }
    queue<pair<int,int>>q;
    for(int u:ad[t])q.push({u,u});
    while(!q.empty()){
        auto [u,g]=q.front();
        q.pop();
        if(u==t||vs[u].size()==2||
            (vs[u].size()==1&&vs[u][0]==g))continue;
        vs[u].push_back(g);
        for(int v:ad[u]){
            q.push({v,g});
        }
    }
    set<int>st;
    for(int u:ad[t])
        if(vs[u].size()==1)st.insert(u);
    cout<<st.size()<<"\n";
    for(int u:st)cout<<u<<"\n";
    return 1<<32;
}