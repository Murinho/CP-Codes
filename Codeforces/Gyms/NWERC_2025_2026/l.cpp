#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    map<string,array<int,11>>mp;
    for(int i=0;i<n;i++){
        for(int j=1;j<=10;j++){
            string s;
            cin>>s;
            if(!mp.count(s))mp[s];
            mp[s][0]++;
            mp[s][j]++;
        }
    }
    string res="";
    array<int,11>mx{0,0,0,0,0,0,0,0,0,0,0};
    for(auto [k,v]:mp){
        if(v==mx)res="tie";
        if(v>mx)mx=v,res=k;
    }
    cout<<res<<"\n";
}