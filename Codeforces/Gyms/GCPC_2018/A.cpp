#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5,M=1e4+5;
string s[1005];
int h,w,c=1,x[M],y[M];
long long rs=0;
int vs[1005][1005],pd[20][N],pr[N];
vector<int>ad[N];

int dfs1(int x,int y){
    vs[x][y]=c++;
    if(x>1&&!vs[x-1][y]&&s[x-1][y*2-1]==' ')ad[vs[x][y]].push_back(dfs1(x-1,y));
    if(y>1&&!vs[x][y-1]&&s[x][y*2-2]==' ')ad[vs[x][y]].push_back(dfs1(x,y-1));
    if(x<h&&!vs[x+1][y]&&s[x][y*2-1]==' ')ad[vs[x][y]].push_back(dfs1(x+1,y));
    if(y<w&&!vs[x][y+1]&&s[x][y*2]==' ')ad[vs[x][y]].push_back(dfs1(x,y+1));
    return vs[x][y];
}

void dfs2(int u,int p,int t){
    pd[0][u]=p,pr[u]=t;
    for(int v:ad[u]){
        dfs2(v,u,t+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>h>>w;
    getline(cin,s[0]);
    for(int i=0;i<h+1;i++){
        getline(cin,s[i]);
        s[i]+=" ";
    }
    dfs1(1,1);
    dfs2(1,-1,0);
    for(int i=1;i<20;i++)
        for(int j=1;j<c;j++)
            if(pd[i-1][j]==-1)pd[i][j]=-1;
            else pd[i][j]=pd[i-1][pd[i-1][j]];
    cin>>c;
    for(int i=0;i<c;i++)cin>>x[i]>>y[i];
    for(int i=0;i<c-1;i++){
        h=vs[x[i]][y[i]];
        w=vs[x[i+1]][y[i+1]];
        if(pr[h]<pr[w])swap(h,w);
        for(int j=19;j>=0;j--)
            if(pr[h]-(1<<j)>=pr[w])
                rs+=(1<<j),h=pd[j][h];
        for(int j=19;j>=0;j--)
            if(pd[j][h]!=pd[j][w])
                rs+=(1<<j)*2,h=pd[j][h],w=pd[j][w];
        if(h!=w)rs+=2;
    }
    cout<<rs;
    return 1<<32;
}