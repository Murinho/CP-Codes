#include<bits/stdc++.h>
using namespace std;

int h,w,c,t,f=0,r[105][105];
vector<pair<int,int>>ad={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

bool val(int x,int y){
    return (0<=x&&x<h+2&&0<=y&&y<w+2);
}

int sum(int x,int y){
    int rt=r[x][y];
    for(auto p:ad){
        if(val(x+p.first,y+p.second)){
            rt+=r[x+p.first][y+p.second];
        }
    }
    return rt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>h>>w;
    for(int i=0;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            cin>>c;
            t=sum(i,j);
            if(c==t)continue;
            if(c==t+1){
                if(i>=h||j>=w)f=1;
                r[i+1][j+1]=1;
            }
            else f=1;
        }
    }
    if(f)cout<<"impossible";
    else for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)
            cout<<(r[i][j]?'X':'.');
        cout<<"\n";
    }
    return 1<<32;
}