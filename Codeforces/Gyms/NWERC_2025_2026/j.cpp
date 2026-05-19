#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,q,cur=0,mx=0;
    cin>>n>>k>>q;
    vector<int>key(q);
    vector<array<int,3>>q1;
    q1.reserve(q*2);
    for(int i=0;i<q;i++){
        int p,l,r;
        cin>>p>>l>>r;
        q1.push_back({l,i,-1});
        q1.push_back({r,i,1});
    }
    sort(q1.begin(),q1.end());
    for(int i=0;i<q*2;i++){
        auto [p,j,v]=q1[i];
        if(v==-1){
            n--;
        }else{
            n++;
            if(n==1)key[j]=1;
        }
    }
    for(int i=0;i<q*2;i++){
        auto [p,j,v]=q1[i];
        if(v==-1){
            n--;
            if(key[j]){
                cur++;
                mx=max(mx,cur);
            }
        }else{
            n++;
            if(key[j])cur--;
        }
    }
    if(mx>k){
        cout<<"impossible\n";
        return 0;
    }
    for(int i:key)cout<<i;
    cout<<"\n";
}