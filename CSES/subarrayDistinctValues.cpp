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
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+100;

ll n,cnt=0,a[maxn],ans,k;
map <ll,ll> mp;

int main(){
    fast;
    cin>>n>>k;
    fore(i,0,n) cin>>a[i];

    int r = 0;
    fore(i,0,n){
        if (i>0){
            mp[a[i-1]]--;
            if (!mp[a[i-1]]) cnt--;
        }
        while(r < n && cnt<=k){
            if (mp[a[r]]==0){
                if (cnt==k) break;
                cnt++;
            }
            mp[a[r]]++;
            r++;
        }
        //cout<<i<<": "<<r<<nl;
        ans += (r-i);
    }
    cout<<ans<<nl;
    return 0;
}