#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
vector<int>dv[N],p(N),vl(1<<18);

void add(int v,int p,int nd,int l,int r){
    vl[nd]=max(vl[nd],v);
    if(l==r)return;
    int m=(l+r)/2;
    if(p<=m)add(v,p,nd*2,l,m);
    else add(v,p,nd*2+1,m+1,r);
}

int qry(int p,int q,int nd,int l,int r){
    if(p<=l&&r<=q)return vl[nd];
    if(r<p||q<l)return 0;
    int m=(l+r)/2;
    return max(qry(p,q,nd*2,l,m),qry(p,q,nd*2+1,m+1,r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i);
        }
    }
    int n,m;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    vector<array<int,3>>q(m);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        q[i]={l-1,r-1,i};
    }
    sort(q.begin(),q.end());
    for(int i=n-1,j=m-1;i>=0;i--){
        for(int d:dv[a[i]]){
            if(p[d])add(d,p[d],1,0,n-1);
            p[d]=i;
        }
        while(j>=0&&q[j][0]==i){
            q[j]={q[j][2],qry(q[j][0],q[j][1],1,0,n-1)};
            j--;
        }
    }
    sort(q.begin(),q.end());
    for(int i=0;i<m;i++)cout<<q[i][1]<<"\n";
}