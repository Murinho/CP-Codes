#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>

using namespace std;


int main(){
    fast;
    ll tt; cin>>tt;
    while(tt--){
        int w; cin>>w;
        if(w == 1)cout<<7<<endl;
        else cout<<(w + 7 - 1)%7<<endl;
    }
}