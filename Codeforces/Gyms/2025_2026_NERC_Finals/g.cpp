#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define fst first
#define snd second
#define pii pair<ll,ll>

using namespace std;

const int C=5e5+5;

ll a[C], v[C];

void sol(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll m1=0,m2=a[0];
    ll n1=0,n2=a[0];

    v[0]=a[0];
    for(int i=1;i<n;i++){
        v[i]=a[i]-v[i-1];
        if(i%2==0){
            m2=max(m2,v[i]);
            n2=min(n2,v[i]);
        } else{
            m1=max(m1,v[i]);
            n1=min(n1,v[i]);
        }
    }


    ll x=-1;
    ll l=(m1+m2)/2;


    if(m1<=m2){
        

        if(n1+l-m1>=0 && n2-l+m1>=0){
            x=l-m1;
        }

        l=(m1+m2+1)/2;

        if(n1+l-m1>=0 && n2-l+m1>=0){
            x=l-m1;
        }

    } 

    if(x==-1){
        l=-n1;
        ll r=n2;

        if(max(m1+l,m2-l)<max(m1+r,m2-r))x=l;
        else x=r;
    }

    if(n%2)x=v[n-1]/2;

    ll mx=0;

    ll s=0;

    for(int i=0;i<n;i++){
        if(i%2)v[i]+=x;
        else v[i]-=x;

        s+=v[i];
        mx=max(mx,v[i]);
    }

    cout<< max((ll) mx, (s+n-2)/(n-1))<< "\n";
    

}

int main(){
    fast;
    int t;
    cin>>t;
    while(t--)sol();
}