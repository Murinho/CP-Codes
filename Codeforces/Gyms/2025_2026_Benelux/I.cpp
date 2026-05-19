#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,w;
    cin>>n>>w;
    vector<int>p(n),t(n);
    for(int i=0;i<n;i++)cin>>p[i]>>t[i];
    long double lo=0,hi=1e10,md,res;
    while(lo+1e-7<hi){
        md=(lo+hi)/2;
        res=0;
        for(int i=0;i<n;i++)
            res+=(md>t[i]*2?(md-t[i]*2)*p[i]:0);
        if(res>w)hi=md;
        else lo=md;
    }
    cout<<fixed<<setprecision(10)<<lo<<"\n";
}