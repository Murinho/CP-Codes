#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long int
using vll = vector<ll>;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int base = max((int)1,n/1000);
    vector<int> bases;
    while(base<n){
        bases.push_back(base);
        base*=2;
    }
    bases.push_back(base);
    int cant = bases.size()%8;
    int saltos = (bases.size()-cant)/8;
    saltos++;
    //cout<<cant<<" "<<saltos<<"\n";
    //for(auto a:bases)cout<<a<<" ";

    int tot = min((int)bases.size(),(int)10);
    cout<<tot<<"\n";
    for(int i=0;i<cant;i++){
        cout<<ceil(bases[i])<<"\n";
        int l=1,r=1;
        while(l<=n){
            r+=bases[i];
            if(r>n)r=n;
            cout<<l<<" "<<r<<"\n";
            l=r+1;
            r=l;
        }
    }
}