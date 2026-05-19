#include <bits/stdc++.h>

using namespace std;

int32_t main(){

    int l,r,k;
    cin>>l>>r>>k;

    int ans=0;

    for(int i=l;i<=r;i++){
        if(i%k==0)ans++;
    }

    cout<<ans;

    return 0;
}