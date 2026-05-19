#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>a(N),b(N),v(N*4);
vector<pair<int,int>>h(N*4);
int n;

void bld_h(int nd=1,int l=0,int r=n-1){
    if(l==r){
        h[nd]={a[l],l};
        return;
    }
    int m=(l+r)/2;
    bld_h(nd*2,l,m);
    bld_h(nd*2+1,m+1,r);
    h[nd]=max(h[nd*2],h[nd*2+1]);
}

pair<int,int> qry_h(int p,int q,int nd=1,int l=0,int r=n-1){
    if(q<l||r<p)return {0,0};
    if(p<=l&&r<=q)return h[nd];
    int m=(l+r)/2;
    return max(
        qry_h(p,q,nd*2,l,m),
        qry_h(p,q,nd*2+1,m+1,r)
    );
}

int get_v(int p,int nd=1,int l=0,int r=n-1){
    if(p<l||r<p)return 0;
    if(l==r)return v[nd];
    int m=(l+r)/2;
    return get_v(p,nd*2,l,m)+get_v(p,nd*2+1,m+1,r)+v[nd];
}

void add_v(int p,int q,int nd=1,int l=0,int r=n-1){
    if(q<l||r<p)return;
    if(p<=l&&r<=q){
        v[nd]++;
        return;
    }
    int m=(l+r)/2;
    add_v(p,q,nd*2,l,m);
    add_v(p,q,nd*2+1,m+1,r);
}

void solve(int l,int r){
    if(l>r)return;
    int q=qry_h(l,r).second;
    b[q]=get_v(q);
    int lt=l,rt=r;
    if(lt!=0)lt=(lt+q+1)/2;
    if(rt!=n-1)rt=(rt+q)/2;
    add_v(lt,rt);
    solve(l, q-1);
    solve(q+1, r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    bld_h();
    solve(0,n-1);
    for(int i=0;i<n;i++)cout<<b[i]<<" ";
    return 0;
}