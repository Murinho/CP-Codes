#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a)  a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'

using namespace std;

const ll maxn = 2e5+100;

ll n,sum[maxn];
ll q;

int main(){
    fast;
    cin >> n >> q;
    fore(i,1,n+1){
        char c;
        cin >> c;
        if (c == '4') sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1] + 2;
    }

    while(q--){
        ll l,r,x,y;
        cin >> l >> r >> x >> y;
        x = abs(x);
        y = abs(y);
        ll len = r-l+1;
        if (len < max(x,y)) cout << "NO" << nl;
        else{
            if (sum[r]-sum[l-1] >= x+y) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
    }
}