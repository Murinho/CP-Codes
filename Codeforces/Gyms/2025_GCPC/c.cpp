#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,t;
    cin>>n>>t;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;t&&i<n;i+=2){
        if(a[i]!=0){
            for(ll c=a[i]+1,j=i+1;j<n;j++){
                a[j]++,c--;
                if(c==0){
                    if(a[j]==1)break;
                    c=a[j],a[j]=0;
                }
            }
            t--;
        }
        a[i]=t%2;
        if(i+1<n)a[i+1]+=t/2;
        t/=2;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}