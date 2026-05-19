#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;

vector<int>c(5000);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int _t;for(cin>>_t;_t--;){
        int n,a,l;
        cin>>n>>l;
        fill(c.begin(),c.end(),0);
        for(int i=1;i<n;i++){
            cin>>a;
            if(a<=l){
                for(int j=a;j<l;j++)c[j]=c[l];
                l=a;
                continue;
            }
            for(int j=a+1;j<=5000;j++)c[a]=min(c[a],c[j]),c[j]+=a-l;
            for(int j=l;j<a;j++)c[j]+=a-j;
        }
        a=c[l];
        for(int i=l;i<=5000;i++)a=min(a,c[i]);
        cout<<a<<"\n";
    }
    return 1<<32;
}