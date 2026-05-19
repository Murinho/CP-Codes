#include<bits/stdc++.h>
using namespace std;

const long long N=1e5;
long long a,b,x,y,n;
long long res=1e15;

int main(){
    cin>>x>>y>>n;
    vector<pair<long long,long long>>c1(N,{N,-1}),c2,c3;;
    for(long long i=0;i<n;i++){
        cin>>a>>b;
        c1[a].first=min(c1[a].first,b);
        c1[a].second=max(c1[a].second,b);
    }
    for(long long i=0;i<N;i++)
        if(c1[i].first!=N)
            c2.push_back({c1[i].first,0}),
            c3.push_back({c1[i].second,0});
    n=c2.size();
    sort(c2.begin(),c2.end());
    sort(c3.begin(),c3.end());
    reverse(c3.begin(),c3.end());
    for(long long i=1,b=0;i<n;i++){
        b+=(c2[i].first-c2[i-1].first)*i;
        c2[i].second=b;
    }
    for(long long i=1,b=0;i<n;i++){
        b+=(c3[i-1].first-c3[i].first)*i;
        c3[i].second=b;
    }
    reverse(c3.begin(),c3.end());
    for(long long i=0,j=0;i<n;i++){
        while(j!=n&&c3[j].first<c2[i].first)j++;
        res=min(res,(c2[i].second+c3[j].second+(c3[j].first-c2[i].first)*(n-j))*2+x-1);
    }
    for(long long i=0,j=0;i<n;i++){
        while(j+1!=n&&c2[j+1].first<c3[i].first)j++;
        res=min(res,(c3[i].second+c2[j].second+(c3[i].first-c2[j].first)*(j+1))*2+x-1);
    }
    cout<<res;
    return 1<<32;
}