#include<bits/stdc++.h>
using namespace std;
using ld=long double;

const int N=1e5+5,K=30;
int a[N];
ld v[K+1][K+1],p[N][K+1],q[N][K+1];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i],
        p[i][1]=(ld)a[i]/100,q[i][1]=1-p[i][1];
    
    for(int j=0;j<n;j++){
        p[j][0]=1;
        q[j][0]=1;
    }
    for(int i=2;i<=k;i++){
        for(int j=0;j<n;j++){
            p[j][i]=p[j][i-1]*p[j][1];
            q[j][i]=q[j][i-1]*q[j][1];
        }
    }
    for(int i=0;i<=k;i++)v[k][i]=1;
    for(int i=k-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            ld x=0,y=0;
            for(int k=0;k<n;k++){
                ld pr=p[k][j]*q[k][i-j];
                x+=pr*p[k][1];
                y+=pr;
            }
            x/=y;
            x=min(x,(ld)1);
            x=max(x,(ld)0);
            v[i][j]=max(x*v[i+1][j+1]+(1-x)*v[i+1][j],x*2*v[i+1][j+1]);
        }
    }
    cout<<fixed<<setprecision(10)<<(v[0][0]-1)*1000<<"\n";
}