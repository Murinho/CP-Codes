#include <bits/stdc++.h>
using namespace std;

double p[105][105];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin>>n>>s;
    vector<int>a(3);
    for(char c:s){
        if(c=='r')a[0]++;
        if(c=='g')a[1]++;
        if(c=='b')a[2]++;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<=n;i++)p[i][n-i]=min(i,n-i)*3;
    for(int i=n-1;i>=0;i--){
        for(int j=n-i-1;j>=0;j--){
            p[i][j]=(p[i+1][j]+p[i][j+1]+3)/2;
        }
    }
    cout<<fixed<<setprecision(10)<<p[a[2]][a[1]]<<"\n";
}