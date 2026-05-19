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
const ll mod = 1006903069;

ll n,k,ans=0;
map <ll,ll> mpr[maxn];
map <ll,ll> mpc[maxn];

int main(){
    fast;
    cin >> n;
    cin >> k;
    fore(i,0,k){
        ll x,y,c;
        cin >> x >> y >> c;
        mpr[x][y] = c;
    }
    cin >> k;
    fore(i,0,k){
        ll x,y,c;
        cin >> x >> y >> c;
        mpc[y][x] = c;
    }

    // compute the answer:
    fore(i,1,n+1){
        // compute intersection of mpr[i] and mpc[i]
        for(auto [col,val] : mpr[i]){
            if (mpc[i].count(col)){
                ll aux = val*mpc[i][col];
                aux %= mod;
                ans += aux;
                ans %= mod;
            }
        }
    }

    cout << ans << nl;
    return 0;
}