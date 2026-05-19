#include <bits/stdc++.h>
using namespace std;

int n,m;
int mem[4000][4000][2];
vector<int>a(4000),b(4000);

bool solve(int i,int j,int p){
    if(i==n&&j==m)return true;
    if(j==m&&p)return true;
    if(j==m||i==n)return false;
    if(mem[i][j][p]!=-1)return mem[i][j][p];
    if(a[i]==b[j]&&solve(i+1,j+1,0))return mem[i][j][p]=true;
    if(i+b[j]<=n&&solve(i+b[j],j+1,1))return mem[i][j][p]=true;
    if(p)return mem[i][j][p]=solve(i+1,j,1);
    return mem[i][j][p]=false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;for(cin>>t;t--;){
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mem[i][j][0]=mem[i][j][1]=-1;
        if(solve(0,0,0))cout<<"YES\n";
        else cout<<"NO\n";
    }
}