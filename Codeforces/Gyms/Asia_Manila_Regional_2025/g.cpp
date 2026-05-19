#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fst first
#define snd second
#define nl '\n'

using namespace std;

const ll maxn = 1e5+100;
ll n,cnt=0,tot,a[maxn];

int main(){
    fast;
    cin >> n >> tot;
    fore(i,1,n) cin >> a[i];

    fore(i,1,n){
        if (a[i] >= 0){
            cnt++;
            tot += a[i];
        }
    }

    if (cnt > 0){
        cout << tot << nl;
    }
    else{
        ll mx = -1;
        fore(i,1,n){
            mx = max(tot+a[i],mx);
        }
        cout << mx << nl;
    }
    return 0;
}