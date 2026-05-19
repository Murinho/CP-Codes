#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>s(n),vs(n);
    priority_queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        cin>>s[i];
        q.push({s[i],i});
    }
    while(!q.empty()){
        auto [v,p]=q.top();
        q.pop();
        if(s[p]<v||s[p]==v&&!vs[p]){
            s[p]=v;
            vs[p]=1;
            if(p+1<n)q.push({s[p]-m,p+1});
            if(p-1>=0)q.push({s[p]-m,p-1});
        }
    }
    for(int i=0;i<n;i++)cout<<s[i]<<" ";
    cout<<"\n";
}