#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>

using namespace std;

const ll maxn = 1e6+100;

ll n,a[maxn],b[maxn];
ll sa = 0, sb = 0, ans = 0;

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
        cin >> a[i] >> b[i];

        sa += a[i];
        sb += b[i];
    }

    fore(i,1,n+1){
    	ans = max(ans, max(0ll, a[i] - (sb-b[i])) + max(0ll, b[i] - (sa-a[i])));
    }

    ans = max(ans,abs(sa-sb));

    cout << ans << nl;
    return 0;
}
