#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <utility>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

const ll maxn = 1e5+10;

ll n,a[maxn],q;
vi f[maxn];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r){ return uniform_int_distribution<int>(l,r)(rng); }

ll solve(ll &l, ll &r){
    ll tam = r-l+1;


    fore(v,0,60){
        ll i = rd(l,r);
        ll lwb = lower_bound(ALL(f[a[i]]),l) - f[a[i]].begin();
        ll upb = upper_bound(ALL(f[a[i]]),r) - f[a[i]].begin();
        if (tam/2 < upb-lwb){
            ll me = (upb-lwb);
            ll ot = tam-me;
            return max(tam%2,me-ot);
        }
    }
    return tam%2;
}

void doit(){
    cin >> n;
    fore(i,1,n+1){
        cin >> a[i];
        f[a[i]].pb(i);
    }
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << solve(l,r) << nl;
    }
    fore(i,1,n+1){
        f[a[i]].pop_back();
    }
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        doit();
    }

    return 0;
}