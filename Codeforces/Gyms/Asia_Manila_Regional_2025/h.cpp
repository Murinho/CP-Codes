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

const ll maxn = 1e7+10;
const ll mod = 104206969;
const ll tope = 1e7;

vi p,pp;  
bool c[maxn];
ll t3[maxn],t2[maxn];

// void compute_fours(){ // only 2, 3, 2 works here.
//     ll cnt=0;
//     for(auto &elm : p){
//         if (!c[elm+2] && !c[elm+4]){
//             // cout << 2 << " " << elm << " " << 2 << nl;
//             cnt++;
//         }
//     }
//     cout << "cnt4s: " << cnt << nl;
// }

void sieve(){
    c[1] = true;
    ll cnt=0;
    fore(i,2,maxn){
        if (!c[i]){
            t2[cnt] = (tope-i);
            if (cnt > 0) t2[cnt] += t2[cnt-1];
            t2[cnt] %= mod;
            p.pb(i);
            cnt++;

            for(int j = 2; i*j < maxn; j++) c[i*j] = true;
        }
    }
}

void compute_threes(){
    ll cnt = 0;
    for(auto &elm : p){
        if (elm+2 <= tope && !c[elm+2]){
            t3[cnt] = (tope-(elm+2));
            if (cnt > 0) t3[cnt] += t3[cnt-1];
            t3[cnt] %= mod;
            pp.pb(elm+2);
            cnt++;
            
            t3[cnt] = (tope-(elm+2));
            if (cnt > 0) t3[cnt] += t3[cnt-1];
            t3[cnt] %= mod;
            pp.pb(elm+2);
            cnt++;
        }
    }
}

void solve(){
    ll n,k;
    cin >> n >> k;
    if (k == 1){
        cout << n << nl;
    }
    else if (k == 2){
        if (n <= 2) cout << 0 << nl;
        else{
            int l = 0;
            int r = sz(p)-1;
            while(l < r){
                ll mid = (l+r+1)/2;
                if (p[mid] <= n) l = mid;
                else r = mid-1;
            }

            ll elms = l+1;
            ll dif = tope-n;

            ll sub = dif*elms;
            sub %= mod;

            ll ans = t2[l];
            ans -= sub;
            ans += mod;
            ans %= mod;

            cout << ans << nl;
        }
    }
    else if (k == 3){
        if (n <= 5) cout << 0 << nl;
        else{
            int l = 0;
            int r = sz(pp)-1;
            while(l < r){
                ll mid = (l+r+1)/2;
                if (pp[mid] <= n) l = mid;
                else r = mid-1;
            }

            ll elms = l+1;
            ll dif = tope-n;

            ll sub = dif*elms;
            sub %= mod;

            ll ans = t3[l];
            ans -= sub;
            ans += mod;
            ans %= mod;

            cout << ans << nl;
        }
    }
    else if (k == 4){
        if (n <= 7) cout << 0 << nl;
        else{
            cout << n-7 << nl;
        }
    }
    else{
        cout << 0 << nl;
    }
    return;
}

int main(){
    fast;
    sieve();
    compute_threes();
    // compute_fours();
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}