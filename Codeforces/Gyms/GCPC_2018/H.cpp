#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll p[55];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,l,r,m,v;
    cin>>n;
    l=1,r=1e6;
    while(l<r){
        m=(l+r)/2;
        v=m*(m+1)*(2*m+1)/6;
        if(v<n)l=m+1;
        else r=m;
    }
    v=l*(l+1)*(2*l+1)/6;
    if(n==v)cout<<3<<" "<<l;
    else{
        l=1,r=4e4;
        while(l<r){
            m=(l+r)/2;
            v=m*(m+1)*m*(m+1)/4;
            if(v<n)l=m+1;
            else r=m;
        }
        v=l*(l+1)*l*(l+1)/4;
        if(n==v)cout<<4<<" "<<l;
        else{
            for(int i=0;i<55;i++)p[i]=1;
            r=1;
            for(int i=2;r&&p[2]<n;i++){
                l=1;
                for(int j=1;r&&j<55;j++){
                    if(p[j]>n)break;
                    l*=i;
                    p[j]+=l;
                    if(j>1&&p[j]==n){
                        cout<<j+1<<" "<<i;
                        r=0;
                    }
                }
            }
            if(r)cout<<"impossible";
        }
    }
    return 1<<32;
}