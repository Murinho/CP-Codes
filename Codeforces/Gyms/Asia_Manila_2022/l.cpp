#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll bp(ll b,ll p,ll m){ll r=1;while(p){if(p&1)r=r*b%m;b=b*b%m,p>>=1;}return r;}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int _t;cin>>_t;for(int _i=0;_i<_t;_i++)
    {
        ll a,b,s,p,v,f=1;
        cin>>a>>b>>s>>p>>v;
        ll rt=sqrt(p);
        ll p1=bp(a,p-2,p),p2=bp(a,rt,p),p3=((bp(a,rt,p)-1)*bp(a-1,p-2,p)%p*b%p+p)%p;
        if(a==1)p3=b*rt;
        unordered_map<int,int>mp;
        for(int i=0;i<rt;i++){
            if(mp.count(v))
                break;
            mp[v]=i;
            v=(v-b+p)*p1%p;
        }
        for(int i=0;i*rt<p;i++){
            if(mp.count(s)){
                cout<<mp[s]+rt*i<<"\n";
                f=0;
                break;
            }
            s=(s*p2+p3)%p;
        }
        if(f)cout<<"IMPOSSIBLE\n";
    }
    return 1<<32;
}