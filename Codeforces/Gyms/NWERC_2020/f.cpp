#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct frac{
    ll a,b,i,j;
    frac(ll a,ll b,ll i,ll j):a(a),b(b),i(i),j(j){}

    bool operator<(const frac f)const{
        if(a*f.b==f.a*b)return i<f.i;
        return a*f.b<f.a*b;
    }
};

const int N=1e5+5;
int x[N],v[N],l[N],r[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>v[i];
        l[i]=i-1,r[i]=i+1;
    }
    x[0]=-1e9-1,x[n+1]=1e9+1;
    v[0]=-1e9-1,v[n+1]=1e9+1;
    r[0]=1,l[n+1]=n;
    set<frac>q;
    for(int i=0;i<=n;i++){
        if(v[i]-v[i+1]<0)q.insert(frac(x[i+1]-x[i],0,i,i+1));
        else q.insert(frac(x[i+1]-x[i],v[i]-v[i+1],i,i+1));
    }
    while(!q.empty()){
        auto f=q.begin();
        if(f->b==0)break;
        int i=l[f->i],j=r[f->j];
        r[i]=j;
        l[j]=i;
        if(v[i]-v[f->i]<0)q.erase(frac(x[f->i]-x[i],0,i,f->i));
        else q.erase(frac(x[f->i]-x[i],v[i]-v[f->i],i,f->i));
        if(v[f->j]-v[j]<0)q.erase(frac(x[j]-x[f->j],0,f->j,j));
        else q.erase(frac(x[j]-x[f->j],v[f->j]-v[j],f->j,j));
        if(v[i]-v[j]<0)q.insert(frac(x[j]-x[i],0,i,j));
        else q.insert(frac(x[j]-x[i],v[i]-v[j],i,j));
        q.erase(f);
    }
    int c=0,p=r[0];
    while(p!=n+1)c++,p=r[p];
    cout<<c<<"\n";
    p=r[0];
    while(p!=n+1)cout<<p<<" ",p=r[p];
    cout<<"\n";
}