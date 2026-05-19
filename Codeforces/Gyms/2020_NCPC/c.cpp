#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define vi vector<ll>
#define fst first
#define snd second

using namespace std;

const int maxn = 1000;
int n,a[maxn];
vector <pii> b;

int main(){
    fast;
    ll n;
    cin >> n;
    ll sum = 0;
    fore(i,1,n+1){
        cin >> a[i];
        sum += a[i];
    }

    if (sum%2 == 1){
        cout << "no" << nl;
        return 0;
    }

    for(;;){
        pii mx = {0,0};
        pii mx2= {0,0};
        fore(i,1,n+1){
            pii cur = {a[i],i};
            if (cur.fst == 0) continue; // la stack esta vacia
            if (cur > mx){
                mx2 = mx;
                mx = cur;
            }
            else if (cur > mx2){
                mx2 = cur;
            }
        }
        if (mx2.fst == 0) break; // no hubo nadie.

        b.pb({mx.snd,mx2.snd});
        a[mx.snd]--;
        a[mx2.snd]--;
    }

    bool ok = true;
    fore(i,1,n+1) if (a[i] > 0) ok = false;

    if (!ok) cout << "no" << nl;
    else{
        cout << "yes" << nl;
        for(auto &[x,y] : b) cout << x << " " << y << nl;
    }
    return 0;
}