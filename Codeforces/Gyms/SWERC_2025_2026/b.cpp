#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)


using namespace std;
const int C=6e5+5;
ll n,l,r;
ll a[C];

void solve(){
    cin>>n>>l>>r;
    r-=l;
    ll sm=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]-=l;
        sm+=a[i];
    }

    sort(a,a+n);

    pair<ll,ll>rt={-n,sm};

    ll res=0;
    res=max(res,min(rt.s,rt.f*r + rt.s));

    for(int i=0;i<n;i++){
        rt.f++;
        rt.s-=a[i];
        res=max(res,min(rt.s,rt.f*r + rt.s));
        rt.f++;
        rt.s-=a[i];
        res=max(res,min(rt.s,rt.f*r + rt.s));
    }

    cout << res <<"\n";

}

int main(){
    fast;

    int t;
    cin>>t;
    while(t--)solve();
    
    return 0;
}