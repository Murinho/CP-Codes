#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=1e18;

const int N=5e4;
vector<ll>a(N);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,q,k,u=0,v=M;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(u*a[i]<v*i)
            v=a[i],u=i;
    }
    for(int i=n+1;i<N;i++){
        a[i]=M;
        for(int j=1;j<=n;j++)
            a[i]=min(a[i],a[j]+a[i-j]);
    }
    for(int i=0;i<q;i++){
        cin>>k;
        ll r=0;
        if(k>=N){
            ll l=(k-N)/u+1;
            k-=u*l;
            r+=v*l;
        }
        cout<<r+a[k]<<"\n";
    }
    return 0;
}