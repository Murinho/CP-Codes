#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int>ad[N],v(N),in(N),r,vl,vt;
vector<vector<int>>val;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,c,p;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>c;
        if(c==0){
            cin>>p;
            r.push_back(i+1);
            vl.push_back(p);
        }
        for(int j=0;j<c;j++){
            cin>>p;
            ad[i+1].push_back(p);
        }
    }
    for(int i=0;i<n;i++){
        v[i+1]=1;
        queue<int>q;
        q.push(i+1);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            for(int u:ad[t]){
                if(in[u]==0)q.push(u);
                in[u]++;
            }
        }
        q.push(i+1);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            for(int u:ad[t]){
                in[u]--;
                v[u]=min((int)2e8,v[u]+v[t]);
                if(in[u]==0)q.push(u);
            }
            if(ad[t].size()>0)v[t]=0;
        }
        for(auto p:r){
            vt.push_back(v[p]);
            v[p]=0;
        }
        val.push_back({});
        swap(val.back(),vt);
    }
    int res=0;
    for(int i=0;i<(1<<n);i++){
        vector<long long>tt(vl.size(),0);
        for(int j=0;j<n;j++)
            if((i>>j)&1)
                for(int k=0;k<vl.size();k++)
                    tt[k]+=val[j][k];
        int f=1;
        for(int j=0;j<vl.size();j++)
            if(vl[j]<tt[j])f=0;
        if(f)res=max(res,__builtin_popcount(i));
    }
    cout<<res;
    return 1<<32;
}