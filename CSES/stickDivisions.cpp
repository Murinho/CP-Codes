#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
#pragma GCC target("popcnt")

using namespace std;

vi a;
ll n,k,ans=0;
priority_queue <ll, vi, greater <ll> > pq;

int main(){
    fast;
    cin>>k>>n;
    fore(i,0,n){
        ll x;
        cin>>x;
        pq.push(x);
    }
    while(sz(pq)>1){
        ll sm = pq.top();
        pq.pop();
        ll sm2 = pq.top();
        pq.pop();
        ans += sm+sm2;
        pq.push(sm+sm2);
    }
    cout<<ans<<nl;
    return 0;
}