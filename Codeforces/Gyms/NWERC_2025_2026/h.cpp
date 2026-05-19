#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;

ull a[65][65];

ull pos(ull id,int bt,int mb=63){
    if(id<(1ull<<bt))return 0;
    while((id&(1ull<<mb))==0)mb--;
    cout<<id<<" "<<bt
    return a[mb+1][bt]-pos(id-(1<<mb),bt-1,mb-1)-(__popcount(id)==bt);
}

ull find(ull p,int bt){
    cout<<p<<" "<<bt<<"\n";
    ull l=0,r=-1;
    while(l<r){
        ull m=l/2+r/2;
        if(l%2||r%2)m++;
        cout<<l<<" "<<r<<"\n";
        if(pos(m,bt)<=p)l=m;
        else r=m-1;
    }
    return l;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=64;i++){
        a[i][0]=1;
        for(int j=1;j<=i;j++)a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
    cout<<find(0,5)<<"\n";
    cout<<find(1,5)<<"\n";
    cout<<find(2,5)<<"\n";
    cout<<find(3,5)<<"\n";
    cout<<find(4,5)<<"\n";
    cout<<find(5,5)<<"\n";
    cout<<find(6,5)<<"\n";
    int t;for(cin>>t;t--;){
        int h,w,k;
        string s;
        cin>>h>>w>>k;
        ull id=0;
        for(int i=0;i<h;i++){
            cin>>s;
            for(int j=0;j<w;j++){
                if(s[j]=='#')id|=1ull<<(i*w+j);
            }
        }
        if(a[h*w][k]%2){
            cout<<"risky\n";
            continue;
        }
        ull p=pos(id,k);
        ull nid=find(p^1,k);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(((id>>i*w+j)&1)==1&&((nid>>i*w+j)&1)==0){
                    cout<<i<<" "<<j<<"\n";
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(((id>>i*w+j)&1)==0&&((nid>>i*w+j)&1)==1){
                    cout<<i<<" "<<j<<"\n";
                }
            }
        }
    }
}