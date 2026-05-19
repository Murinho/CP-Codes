#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll bp(ll b,ll p,ll m){ll r=1;while(p){if(p&1)r=r*b%m;b=b*b%m,p>>=1;}return r;}

const int N=2e5+5;
vector<pair<int,int>>ad[N];
vector<int>ds(N);
vector<pair<int,int>>ar(N);
vector<vector<int>>var(N);
unordered_map<int,int>mar[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,p,l,a,b,u1;
    cin>>n>>m>>p>>l;
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ar[i]={a,b};
        mp[{a,b}]=i;
        mp[{b,a}]=i;
        ad[a].push_back({i,b});
        ad[b].push_back({i,a});
    }
    for(int i=0;i<p;i++){
        cin>>u1;
        a=u1;
        for(int j=1;j<l;j++){
            cin>>b;
            var[mp[{a,b}]].push_back(j-1);
            a=b;
        }
        var[mp[{u1,a}]].push_back(l-1);
    }
    cin>>a>>b;

    for(int i=0;i<m;i++){
        int p=0;
        sort(var[i].begin(),var[i].end());
        var[i].erase(unique(var[i].begin(),var[i].end()),var[i].end());
        
        for(int j=0;j<var[i].size();j++){
            if(j==var[i][j])p++;
            else break;
        }
        if(p==l){
            for(int j=0;j<l;j++)mar[i][j]=-1;
        }else{
            for(int j=var[i].size()-1;j>=0;j--){
                if(j==var[i].size()-1)mar[i][var[i][j]]=(var[i][j]==l-1?p+1:1);
                else mar[i][var[i][j]]=(var[i][j]+1==var[i][j+1]?mar[i][var[i][j+1]]+1:1);
            }
        }
    }

    int f=1;
    priority_queue<pair<int,int>>pq;
    pq.push({-1,a});
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        if(ds[t.second])continue;
        ds[t.second]=t.first;
        for(auto v:ad[t.second]){
            if(mar[v.first][(-t.first-1)%l]!=-1)
                pq.push({t.first-mar[v.first][(-t.first-1)%l]-1,v.second});
        }
    }
    if(ds[b]!=0){
        cout<<-ds[b]-1<<"\n";
        f=0;
    }
    if(f)cout<<"IMPOSSIBLE\n";
    return 1<<32;
}