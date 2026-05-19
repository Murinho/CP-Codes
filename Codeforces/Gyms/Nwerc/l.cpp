#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,c=0;
    string r;
    cin>>n>>k;
    vector<pair<int,int>>p(k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((i+j)%5==0){
                cout<<i<<" "<<j<<endl;
                cin>>r;
                if(r=="hit")p[c++]={i,j};
            }
    c=0;
    for(int i=0;i<k;i++){
        for(int j=1;j<5;j++){
            for(pair<int,int>q:vector<pair<int,int>>{{0,j},{0,-j},{j,0},{-j,0}}){
                int x=p[i].first+q.first,y=p[i].second+q.second;
                if(1<=x&&x<=n&&1<=y&&y<=n){
                    cout<<x<<" "<<y<<endl;
                    cin>>r;
                    if(r=="sunk")c++;
                    if(c==k)return 1<<32;
                }
            }
        }
    }
    return 1<<32;
}