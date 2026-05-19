#include<bits/stdc++.h>
using namespace std;

ostringstream ost;

const int N=1005;
vector<int>p(N);

int f(int x){
  if(p[x]==x)return x;
  return p[x]=f(p[x]);
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n,res=0;
  cin>>n;
  priority_queue<array<int,3>>q;
  for(int i=0;i<n;i++){
    p[i]=i;
    for(int j=0;j<n;j++){
      int p;
      cin>>p;
      q.push({p,i,j});
    }
  }
  while(!q.empty()){
    auto [v,a,b]=q.top();
    q.pop();
    a=f(a);
    b=f(b);
    if(a==b)continue;
    if(a>b)swap(a,b);
    p[b]=a;
    res+=v;
    ost<<a+1<<" "<<b+1<<"\n";
  }
  cout<<res<<"\n"<<ost.str()<<"\n";
}