#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,L;
    cin>>n>>m>>L;
    vector<int>p(n),l(m);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<m;i++)cin>>l[i];
    sort(p.begin(),p.end());
    int v=max(p[0],L-p[n-1]),r=M;
    for(int i=1;i<n;i++)
        v=max(v,(p[i]-p[i-1]+1)/2);
    for(int i=0;i<m;i++)
        if(l[i]>=v)r=min(r,l[i]);
    cout<<(r==M?-1:r);
    return 1<<32;
}