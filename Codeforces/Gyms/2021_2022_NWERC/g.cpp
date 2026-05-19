#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int mx[N][N],a[N];
string s[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
        mx[i][i]=s[i].size();
        for(int j=i+1;j<=n;j++)
            mx[i][j]=max(mx[i][j-1],(int)s[j].size());
    }
    int lo=1,hi=n;
    a[0]=-1;
    while(lo<hi){
        int m=(lo+hi)/2;
        for(int i=1;i<=n;i++){
            a[i]=mx[i][i]+a[i-1]+1;
            for(int j=max(0,i-m);j<i;j++)
                a[i]=min(a[i],mx[j+1][i]+a[j]+1);
        }
        
        if(a[n]<=w)hi=m;
        else lo=m+1;
    }
    for(int i=1;i<=n;i++){
        a[i]=mx[i][i]+a[i-1]+1;
        for(int j=max(0,i-lo);j<i;j++)
            a[i]=min(a[i],mx[j+1][i]+a[j]+1);
    }
    vector<int>d;
    vector<vector<int>>v;
    for(int i=n;i>0;){
        int j=i-1;
        while(mx[j+1][i]+a[j]+1!=a[i])j--;
        v.push_back({});
        d.push_back(mx[j+1][i]);
        for(int k=j+1;k<=i;k++)
            v.back().push_back(k);
        i=j;
    }
    reverse(d.begin(),d.end());
    reverse(v.begin(),v.end());
    cout<<lo<<" "<<d.size()<<"\n";
    for(int i:d)cout<<i<<" ";
    cout<<"\n";
    for(int i=0;i<lo;i++){
        for(int j=0;j<d.size();j++){
            int t=0;
            if(i<v[j].size()){
                cout<<s[v[j][i]];
                t=s[v[j][i]].size();
            }
            for(;t<=d[j];t++)cout<<" ";
        }
        cout<<"\n";
    }
}
