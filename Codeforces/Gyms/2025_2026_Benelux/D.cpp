#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,t;
    cin>>n;
    map<int,int>mp;
    vector<int>x[n];
    for(int i=0;i<n;i++){
        cin>>k;
        x[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>t;
            mp[t]=0;
            x[i][j]=t;
        }
    }
    t=0;
    for(auto [k,v]:mp)mp[k]=t++;
    vector<int>v[t],inv(t),b(n,-1);
    for(auto [k,v]:mp)inv[v]=k;
    for(int i=0;i<n;i++){
        for(int j:x[i]){
            j=mp[j];
            for(int k:v[j]){
                if(b[k]!=-1){
                    cout<<inv[b[k]]<<" "<<inv[j]<<" "<<k+1<<" "<<i+1<<"\n";
                    return 0;
                }
                b[k]=j;
            }
            v[j].push_back(i);
        }
        for(int j:x[i]){
            j=mp[j];
            for(int k:v[j])b[k]=-1;
        }
    }
    cout<<"impossible\n";
}
