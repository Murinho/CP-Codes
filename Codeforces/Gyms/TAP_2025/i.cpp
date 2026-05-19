#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define ppb pop_back
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 105;

ll n,m;
ll x,y;
ll a[maxn],b[maxn];
ll cnt[3];

int main(){
    fast;
    cin >> n >> m;
    fore(i,0,m){
        cin >> x >> y;
        cnt[1] = cnt[2] = 0;
        fore(j,0,n){
            cin >> a[j];
            cnt[a[j]]++;
        }
        if (x/(cnt[1]+1) >= y){
            a[n] = 1;
            cnt[1]++;
        }
        else{
            a[n] = 2;
        }

        fore(j,0,n+1){
            if (a[j] == 1) b[j] += x/cnt[1];
            else b[j] += y;
        }
    }

    fore(i,0,n+1) cout << b[i] << " ";
    cout << nl;

    return 0;
}