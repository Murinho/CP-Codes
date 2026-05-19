#include<bits/stdc++.h>
using namespace std;
using ld=long double;

ld bp(ld b,int p){
    ld r=1;
    while(p){
        if(p&1)r=r*b;
        b=b*b,p>>=1;
    }
    return r;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,p,k;
    cin>>n>>p>>k;
    ld res=bp(ld(p-1)/n,k)*p;
    for(int i=p;i<=n;i++)
        res+=(bp((ld)i/n,k)-bp(ld(i-1)/n,k))*(i+1)/2;
    cout<<fixed<<setprecision(10)<<res;
}
