#include<bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;


const int C=1e5+5;

int n,k;
string s[C];
int g[C];

int val(int a){
    if(a<0)return 0;
    if(a>10000)return 10000;
    return a;
}

int main(){
    fast;
    cin>>n;
    int r=0;
    for(int i=0;i<n;i++){
        cin>>s[i]>>g[i];
        r+=g[i]*100;
    }
    if(r+49*n<10000 || r-50*n>10000){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int m1=99;
    m1=-min(m1,r+49*n-10000);

    int m2=99;
    m2=min(m2,10000-r+50*n);

    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
        cout<<fixed<<setprecision(2)<<(double)(val(100*g[i]+49+m1))/100<<" ";
        cout<<fixed<<setprecision(2)<<(double)(val(100*g[i]-50+m2))/100<<nl;
    }





}
