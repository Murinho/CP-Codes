#include<bits/stdc++.h>
using namespace std;
using ll=long long;

inline bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.first<b.first||a.first==b.first&&a.second>b.second;
}

const int N=2e5+5,M=1<<20;
vector<int>v(N),c(N);
vector<pair<int,int>>a(M,{-1,0}),b(M,{-1,0});

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='Y')v[i]|=(1<<j),c[i]++;
        }

        int t=v[i];
        if(a[t].first==-1)a[t]={c[i],i+1};
        else if(b[t].first==-1)b[t]={c[i],i+1};
    }
    int x=(1<<m)-1;
    for(int i=x;i>=0;i--){
        for(int j=0;j<m;j++){
            int k=(i|(1<<j));
            if(a[k].second!=a[i].second&&a[k].second!=b[i].second){
                if(comp(a[i],a[k]))b[i]=a[i],a[i]=a[k];
                else if(comp(b[i],a[k]))b[i]=a[k];
            }
            if(b[k].second!=a[i].second&&b[k].second!=b[i].second){
                if(comp(a[i],b[k]))b[i]=a[i],a[i]=b[k];
                else if(comp(b[i],b[k]))b[i]=b[k];
            }
        }
    }
    int r1,r2,v1=-1;
    for(int i=0;i<n;i++){
        int t=v[i]^x;
        if(a[t].first!=-1){
            int pop=0;
            for(int j=0;j<m;j++){
                if((t>>j)&1)pop++;
            }
            if(a[t].second!=i+1){
                if(a[t].first-pop>v1){
                  v1=a[t].first-pop;
                  r1=i+1,r2=a[t].second;
                }
            }else if(b[t].first!=-1&&b[t].second!=i+1){
                if(b[t].first-pop>v1){
                  v1=b[t].first-pop;
                  r1=i+1,r2=b[t].second;
                }
            }
        }
    }
    if(v1==-1)cout<<"No\n";
    else cout<<r1<<" "<<r2<<"\n";
}