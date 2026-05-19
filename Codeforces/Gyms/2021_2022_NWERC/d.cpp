#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,y;
    cin>>n;
    set<int>xc,yc,d1,d2;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        xc.insert(x);
        yc.insert(y);
        d1.insert(x+y);
        d2.insert(x-y);
    }
    if(n==1){
        cout<<4;
        return 0;
    }
    if(d1.size()==1){
        cout<<(*--d2.end()-*d2.begin())+5;
        return 0;
    }
    if(d2.size()==1){
        cout<<(*--d1.end()-*d1.begin())+5;
        return 0;
    }
    
    vector<pair<int,int>>p;
    
    x=*xc.begin();
    y=*d1.begin()-x;
    p.push_back({x,y});
    
    y=*yc.begin();
    x=*d1.begin()-y;
    p.push_back({x,y});
    
    y=*yc.begin();
    x=y+*--d2.end();
    p.push_back({x,y});
    
    x=*--xc.end();
    y=x-*--d2.end();
    p.push_back({x,y});
    
    x=*--xc.end();
    y=*--d1.end()-x;
    p.push_back({x,y});
    
    y=*--yc.end();
    x=*--d1.end()-y;
    p.push_back({x,y});
    
    y=*--yc.end();
    x=y+*d2.begin();
    p.push_back({x,y});
    
    x=*xc.begin();
    y=x-*d2.begin();
    p.push_back({x,y});

    int res=0;
    for(int i=0;i<8;i++){
        int v=abs(p[(i+1)%8].first-p[i].first);
        v+=abs(p[(i+1)%8].second-p[i].second);
        if(i%2==0)v/=2;
        res+=v;
    }
    cout<<res+4;
}
