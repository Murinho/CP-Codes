#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace __gnu_pbds;
using namespace std;

set <int> st;

set<int>::iterator goPrev(set<int>::iterator x){
    if (x == st.begin()) x = st.end();
    x = prev(x);
    return x;
}

set<int>::iterator goNext(set<int>::iterator x){
    if (next(x) == st.end()) x = st.begin();
    else x = next(x);
    return x;
}

int main(){
    fast;
    ll n,a,b;
    cin>>n>>a>>b;
    a--, b--;
    vi h;
    fore(i,1,n+1) st.insert(i);
    
    set<int>::iterator x = st.find(1);
    set<int>::iterator y = st.find(n);
    while(sz(st) > 2){
        fore(i,0,a%sz(st)) x = goNext(x);
        fore(i,0,b%sz(st)) y = goPrev(y);
        if (x == y){
            h.pb(*x);
            set<int>::iterator aux = x;
            x = goNext(x);
            y = goPrev(y);
            st.erase(*aux);
        }
        else if (goNext(x) == y){
            set<int>::iterator aux = x;
            set<int>::iterator aux2 = y;
            x = goNext(x);
            x = goNext(x);
            y = goPrev(y);
            y = goPrev(y);
            st.erase(*aux);
            st.erase(*aux2);
        }
        else{
            set<int>::iterator aux = x;
            set<int>::iterator aux2 = y;
            x = goNext(x);
            y = goPrev(y);
            st.erase(*aux);
            st.erase(*aux2);
        }
        //cout<<"end --> x: "<<*x<<" , y: "<<*y<<nl;
    }
    for(auto au : st) h.pb(au);
    sort(ALL(h));
    for(auto au : h) cout<<au<<" ";
    cout<<nl;
    return 0; 
}