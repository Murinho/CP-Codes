#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long l,r;
    cin>>l>>r;
    if(l==r)cout<<r*3;
    else if(l==r+1)cout<<r*2+1;
    else if(l==r+2)cout<<(r+1)*3;
    else cout<<(l+r)*2;
}