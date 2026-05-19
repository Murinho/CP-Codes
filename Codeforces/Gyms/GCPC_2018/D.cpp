#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long n,c=1e18;
    cin>>n;
    vector<long long>a(n),b(n+1);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)b[i+1]=a[i]-b[i];
    for(int i=0;i<n+1;i+=2)c=min(c,b[i]);
    for(int i=0;i<n+1;i+=2)b[i]-=c;
    for(int i=1;i<n+1;i+=2)b[i]+=c;
    c=1e18;
    for(int i=1;i<n+1;i+=2)c=min(c,b[i]);
    cout<<max(c+1,(long long)0);
    return 1<<32;
}