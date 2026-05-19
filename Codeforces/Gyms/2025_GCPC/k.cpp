#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b==2||a+b>n+1){
        cout<<"no";
        return 0;
    }
    cout<<"yes\n";
    vector<int>r(n);
    int j=0;
    if(b==1){
        swap(a,b);
        for(int i=n-a+1;i<=n;i++)r[j++]=i;
        for(int i=1;i<n-a-b+2;i++)r[j++]=i;
        for(int i=n-a;i>n-a-b+1;i--)r[j++]=i;
        reverse(r.begin(),r.end());
    }else{
        for(int i=n-a+1;i<=n;i++)r[j++]=i;
        for(int i=1;i<n-a-b+2;i++)r[j++]=i;
        for(int i=n-a;i>n-a-b+1;i--)r[j++]=i;
    }
    for(int i:r)cout<<i<<" ";
}