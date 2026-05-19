#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 1e6+5;
ll n,pos=1;
vi a;


int main(){
    fast;
    cin>>n;
    a.resize(n);
    fore(i,0,n) cin>>a[i];

    sort(ALL(a));

    fore(i,0,n){
        if (a[i] > pos) break;
        pos += a[i];
    }
    cout<<pos<<nl;
    return 0;
}