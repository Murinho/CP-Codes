#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string t,s;
    int n;
    cin>>t>>n>>s;
    if(t=="Encode"){
        int z=1;
        for(int i=0;i<n;i++)
            if(s[i]=='1')z=0;
        if(!z)for(int i=0;i<n;i++){
            if(s[i]=='1'){
                s[i]='2';
                break;
            }
            s[i]='2';
        }
        cout<<s;
    }else{
        int z=-1;
        for(int i=0;i<n;i++)
            if(s[i]!='2'&&s[(i+1)%n]=='2')z=(i+1)%n;
        if(z!=-1){
            s=s.substr(z,s.size()-z)+s.substr(0,z);
            for(z=0;z<n;z++){
                if(s[z]!='2')break;
                s[z]='0';
            }
            s[z-1]='1';
        }else if(s[0]=='2'){
            for(int i=0;i<n;i++)s[i]='0';
            s[n-1]='1';
        }
        cout<<s;
    }
}