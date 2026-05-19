#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=1e9+7;

ll bp(ll b,ll p=M-2){
    ll r=1;
    while(p){
        if(p&1)r=r*b%M;
        b=b*b%M,p>>=1;
    }
    return r;
}

const int N=1e6+5;
vector<ll>f(N*2),in(N*2);
vector<int>a[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    f[0]=1;
    for(int i=1;i<=2*n;i++)f[i]=f[i-1]*i%M;
    in[2*n]=bp(f[2*n]);
    for(int i=2*n-1;i>=0;i--)in[i]=in[i+1]*(i+1)%M;
    vector<pair<int,int>>b={{-1,0}};
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        while(b.back().first>=t)b.pop_back();
        a[b.back().second].push_back(t);
        b.push_back({t,i});
    }
    ll r=1;
    for(int i=0;i<n;i++){
        int c=1;
        for(int j=1;j<=a[i].size();j++){
            if(j==a[i].size()||a[i][j]!=a[i][j-1]){
                r=r*f[2*c]%M*in[c]%M*in[c]%M*bp(c+1)%M;
                c=0;
            }
            c++;
        }
    }
    cout<<r;
    return 1<<32;
}