#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t,b[10];
    vector<ll>p;
    for(int c7=0;c7<=18;c7++)
    for(int c5=0;c7+c5<=18;c5++)
    for(int c3=0;c7+c5+(c3+1)/2<=18;c3++)
    for(int c2=0;c7+c5+(c3+1)/2+(c2+1)/3<=18;c2++){
        b[2]=(c2%3==1);
        b[3]=c3%2;
        b[4]=(c2%3==2);
        b[5]=c5;
        b[6]=0;
        b[7]=c7;
        b[8]=c2/3;
        b[9]=c3/2;
        t=0;
        for(int i=2;i<10;i++)
            for(int j=0;j<b[i];j++)
                t=t*10+i;
        p.push_back(t);
        if(c2==0||c3==0)continue;
        b[2]=((c2-1)%3==1);
        b[3]=(c3-1)%2;
        b[4]=((c2-1)%3==2);
        b[5]=c5;
        b[6]=1;
        b[7]=c7;
        b[8]=(c2-1)/3;
        b[9]=(c3-1)/2;
        t=0;
        for(int i=2;i<10;i++)
            for(int j=0;j<b[i];j++)
                t=t*10+i;
        p.back()=min(p.back(),t);
    }
    p.push_back(10);
    sort(p.begin(),p.end());
    int _t;for(cin>>_t;_t--;){
        ll n;
        cin>>n;
        cout<<upper_bound(p.begin(),p.end(),n)-p.begin()<<"\n";
    }
    return 1<<32;
}