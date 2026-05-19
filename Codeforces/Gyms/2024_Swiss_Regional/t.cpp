#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=1e9+7;

const int N=1e5+5;

int p[N],v[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,r=0;
    cin>>n;
    for(ll i=2;i<=n;i++){
        if(!p[i]){
            r++;
            for(ll j=i*i;j<=n;j+=i)
                p[j]=1;
            for(ll j=i*i;j<=n;j+=i*i)
                v[j]=1;
        }
    }
    cout<<r;
    return 1<<32;
}