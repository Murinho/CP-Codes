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

const ll maxn = 2e5+5;

ll n,a[maxn],b[maxn];
set <ll> st;
vector < pii > e;

int main(){
    fast;
    cin>>n;
    fore(i,0,n-2){
        cin>>a[i];
        b[a[i]]++;
    }
    fore(i,1,n+1) if (!b[i]) st.insert(i);

    fore(i,0,n-2){
        e.pb({*st.begin(),a[i]});
        st.erase(*st.begin());
        b[a[i]]--;
        if (!b[a[i]]) st.insert(a[i]);
    }

    e.pb({*st.begin(),*st.rbegin()});
    for(auto au : e) cout<<au.fst<<" "<<au.snd<<nl;
    return 0;
    
}