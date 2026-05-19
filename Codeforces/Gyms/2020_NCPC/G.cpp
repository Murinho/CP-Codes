#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 105;
const int M=1e9+7;

int n;
ll c0,c1;
ll res;

int main(){
    fast;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            c0++;
            c1++;
        } else if(x==2){
            c1*=2;
            c1%=M;
        } else {
            res+=c1-c0;
            res%=M;
        }
    }
    res%=M;
    if(res<0)res+=M;
    cout<<res;
    return 0;
}