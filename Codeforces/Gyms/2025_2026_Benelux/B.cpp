#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s[6];
    for(int i=0;i<6;i++)cin>>s[i];
    char mx='Z'+1;
    vector<char>p(33,mx),q(33);
    p[0]='A';
    for(int i=0;i<16;i++){
        for(int j=0;j<=32;j++)q[j]=mx;
        for(int j=0;j<=30;j++){
            if(s[0][i]>=p[j])q[j]=min(q[j],s[0][i]=='Q'?'U':s[0][i]);
            for(int k=1;k<=4;k++)if(s[k][i]>=p[j])q[j+1]=min(q[j+1],s[k][i]=='Q'?'U':s[k][i]);
            if(s[5][i]>=p[j])q[j+2]=min(q[j+2],s[5][i]=='Q'?'U':s[5][i]);
        }
        swap(p,q);
    }
    for(int i=0;i<=32;i++)if(p[i]!=mx){
        cout<<i<<"\n";
        return 0;
    }
    cout<<"impossible\n";
}