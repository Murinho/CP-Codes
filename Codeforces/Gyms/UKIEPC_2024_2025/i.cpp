#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n' 
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define ld long double
#define eb emplace_back

using namespace std;

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    ll sb=0;
    ll sd=0;
    cout<<2<<" "<<m-n+1<<" ";
    sb += m-n+1;
    ll denom = (m-n+1)/2;
    denom++;
    cout<<1<<" "<<denom<<nl;
    sd += denom;

    fore(i,2,n){
        cout<<"1 1 1 2"<<nl;
        sb++;
        sd += 2;
    }

    cout<<1<<" "<<1<<" ";
    ll dif = m-sd;
    cout<<dif-1<<" "<<dif<<nl;

    return 0;
}