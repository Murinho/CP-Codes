#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define pii pair <ll,ll>
#define vi vector<ll>
#define f first
#define s second

using namespace std;

int main(){
    fast;
    int n;
    cin>>n;

    if(n%2){
        cout << n/2<<"\n";
    } else if(n%4==0){
        cout << n/2 - 1<<"\n";
    } else{
        cout << n/2 - 2<<"\n";
    }
}