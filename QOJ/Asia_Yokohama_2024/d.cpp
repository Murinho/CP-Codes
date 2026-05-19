#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=3e5,M=998244353;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),cur=0;
    ll res=1;
    vector<pair<int,int>>p,q(3e5);
    for(int i=0;i<n;i++){
        if(s1[i]=='(')continue;
        if(s1[i]=='1')p.push_back({cur++,1});
        else{
            auto [n2,c2]=p.back();
            p.pop_back();
            auto [n1,c1]=p.back();
            p.back().second+=c2;
            q[n2-1]={c1,c2};
        }
    }
    p.pop_back();
    cur=0;
    for(int i=0;i<n;i++){
        if(s2[i]=='(')continue;
        if(s2[i]=='1')p.push_back({cur++,1});
        else{
            auto [n2,c2]=p.back();
            p.pop_back();
            auto [n1,c1]=p.back();
            p.back().second+=c2;
            auto [z1,z2]=q[n2-1];
            res=res*min(c1,z1)%M*min(c2,z2)%M;
        }
    }
    cout<<res<<"\n";
}