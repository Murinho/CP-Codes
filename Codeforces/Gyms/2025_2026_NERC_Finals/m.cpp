#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;for(cin>>t;t--;){
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.size(),r=0;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            a[i]=s1[i]-'0';
            b[i]=s2[i]-'0';

            if(i!=0)a[i]^=a[i-1];
            b[i]^=a[i];
        }
        int flip=0;
        for(int i=0;i<n;i++){
            if(!(b[i]^flip))continue;
            r++;
            if(i+1<n&&(b[i+1]^flip))flip^=1;
        }
        cout<<r<<"\n";
    }
}