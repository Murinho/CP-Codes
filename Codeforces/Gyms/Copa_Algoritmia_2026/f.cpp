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
    ll n; cin>>n;
    ll minn = LLONG_MAX, ind = 0;
    for(ll i = 1; i<=n; i++){
        vector<ll> arr(10, 0);
        ll val; cin>>val;
        string s; cin>>s;
        for(auto ch : s){
            arr[ch - '0']++;
        }
        if(arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 2){
            if(minn > val){
                minn = val;
                ind = i;
            }
        }
    }

    cout<<ind<<endl;
}