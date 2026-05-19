#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define pii pair <ll,ll>
#define vi vector<ll>
#define f first
#define s second

using namespace std;

const ll maxn = 1e5+10;

ll n,a[maxn],b[maxn];

int main(){
    fast;
    cin >> n;
    ll sumcost = 0;
    ll sumcont = 0;
    fore(i,1,n+1){
        cin >> a[i] >> b[i];
        sumcost += b[i];
        sumcont += a[i];
    }

    fore(i,1,n+1){
        sumcont -= a[i];

        if (sumcost - sumcont <= b[i]){
            cout << i << nl;
            return 0;
        }

        sumcont += a[i];
    }

    cout << "impossible" << nl;
    return 0;
}