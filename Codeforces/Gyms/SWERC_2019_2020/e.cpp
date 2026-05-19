#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k,l,inv=0;
    cin>>k>>l;
    if(l<k)swap(k,l),inv=1;
    vector<vector<int>>a(k,vector<int>(l));
    for(int i=0;i<k;i++)
        for(int j=0;j<l;j++){
            if(inv)cin>>a[i][j];
            else cin>>a[j][i];
        }
    vector<vector<int>>A(k,vector<int>(k));
    vector<int>B(k),b1(k),b2(k);
    for(int t=0;t<k;t++){
        fill(b1.begin(),b1.end(),0);
        b1[t]=1;
        for(int i=1;i<l;i++){
            for(int j=0;j<k;j++)b1[j]^=a[j][i-1];
            for(int j=0;j<k;j++){
                b2[j]=b1[j];
                if(j-1>=0)b2[j]^=b1[j-1];
                if(j+1<k)b2[j]^=b1[j+1];
            }
            swap(b1,b2);
        }
        A[t]=b1;
    }
    fill(b1.begin(),b1.end(),0);
    for(int i=1;i<l;i++){
        for(int j=0;j<k;j++)b1[j]^=a[j][i-1];
        for(int j=0;j<k;j++){
            b2[j]=b1[j];
            if(j-1>=0)b2[j]^=b1[j-1];
            if(j+1<k)b2[j]^=b1[j+1];
        }
        swap(b1,b2);
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++)A[i][j]^=b1[j];
    for(int i=0;i<k;i++)
        B[i]=a[l-1][i];
    int cur=0;
    for(int i=0;i<k;i++){
        if(A[i][cur]==0){}
    }
    return 1<<32;
}