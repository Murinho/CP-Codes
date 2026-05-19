#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>a(n),b1(n),b2(n);
    int s=0;
    for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
    s/=n;
    for(int i=0;i<n;i++)b1[i]=b2[i]=a[i]-s;
    long long r1=0,r2=0;
    int c1=0,c2=0;
    reverse(b2.begin(),b2.end());
    for(int it=0;it<2;it++)
        for(int i=0;i<n;i++){
            if(b1[i]>0)c1+=b1[i],b1[i]=0;
            else if(b1[i]+c1>=0)c1+=b1[i],b1[i]=0;
            else b1[i]+=c1,c1=0;
            r1+=c1;
            
            if(b2[i]>0)c2+=b2[i],b2[i]=0;
            else if(b2[i]+c2>=0)c2+=b2[i],b2[i]=0;
            else b2[i]+=c2,c2=0;
            r2+=c2;
        }
    cout<<min(r1,r2)<<"\n";
    return 0;
}