#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,p,r=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p;
        vector<ll>x(p),y(p);
        ll rt=0;
        for(int i=0;i<p;i++)cin>>x[i]>>y[i];
        for(int i=0;i<p;i++)rt+=x[i]*y[(i+1)%p]-x[(i+1)%p]*y[i];
        r+=abs(rt);
    }
    cout<<r/2;
    return 1<<32;
}