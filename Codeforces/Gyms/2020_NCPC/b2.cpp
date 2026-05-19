#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x1,y1,x2,y2;
    ll r=0;
    cin>>n>>x1>>y1;
    vector<pair<ld,ld>>q;
    vector<array<ll,4>>p;
    for(int i=1;i<n;i++){
        cin>>x2>>y2;
        p.push_back({x1,y1,x2,y2});
        while(p.size()>1){
            auto a=p[p.size()-2];
            auto b=p[p.size()-1];
            if((a[2]-a[0])*(b[3]-b[1])-(a[3]-a[1])*(b[2]-b[0])<=0)break;
            auto t=p.back();
            p.pop_back();
            p.pop_back();
            p.push_back(t);
        }
    }
    for(int i=0;i<p.size();i++){
        auto a=p[i];
        auto b=p[(i+1)%p.size()];
        ld x1=a[0],y1=b[1],x2=a[2],y2=b[3];
        ld x3=a[0],y3=b[1],x4=a[2],y4=b[3];
        ld m1=(x2-x1)/(y2-y1),m2=(x4-x3)/(y4-y3);
        ld b1=y1-m1*x1,b2=y3-m2*x3;
        ld x=(b2-b1)/(m1-m2),y=m1*x+b1;
        q.push_back({x,y});
        cout<<x1<<" "<<y1<<"\n";
    }
    for(int i=0;i<q.size()-1;i++)
        r+=q[i].first*q[i+1].second-q[i].second*q[i+1].first;
    cout<<r;
}
