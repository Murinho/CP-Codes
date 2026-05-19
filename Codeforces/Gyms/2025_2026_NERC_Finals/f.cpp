#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;for(cin>>t;t--;){
        int n,c=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            c+=(t==1);
        }
        if((c&1)^(n-c>0))cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}