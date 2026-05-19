#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

vector <pii> a;

void read(){
    ll x,b,c,d;
    cin >> x >> b >> c >> d;
    a.pb({x,0});
    a.pb({b,0});
    a.pb({c,1});
    a.pb({d,1});
}

void clean(){
    a.clear(), a.resize(0);
}

void solve(){
    ll ans = 0;
    clean();

    read();

    sort(ALL(a));

    if (a[0].snd == a[3].snd){
        ans = a[2].fst - a[1].fst;
    }
    else if (a[0].snd == a[2].snd){
        ans = a[2].fst - a[1].fst;
    }
    else ans = 0;

    cout << ans << nl;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){ solve(); }
    return 0;
}