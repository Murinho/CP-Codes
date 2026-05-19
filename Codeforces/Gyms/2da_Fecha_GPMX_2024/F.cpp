#include<bits/stdc++.h>

#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;

int32_t main(){

    fast;

    int n,p;

    cin>>n>>p;

    int ans=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>ans && x<=p)ans=x;
    }
    cout<<ans;
}