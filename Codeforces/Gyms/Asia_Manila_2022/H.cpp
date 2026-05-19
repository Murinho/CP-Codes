#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ll long long
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define nl '\n'

using namespace std;

const ll maxn = 2e5+100;

ll a[maxn],b[maxn],n,x,tope,res[maxn];
vi ca;
ll suma = 0;
vector <pii> difs;

bool check(int mid){
    vi v;
    fore(i,0,sz(difs)){
        if (i < mid){
            v.pb(b[difs[i].snd]);
        }
        else v.pb(a[difs[i].snd]);
    }

    sort(ALL(v));

    ll sum = 0;
    for(auto &elm : v ) sum += elm;

    int tope2 = sz(v)-1;
    while(tope2 >= 0){
        if (sum <= x) break;

        sum -= v[tope2];
        tope2--;
    }

    return tope == tope2;
}

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
        cin >> a[i];
        ca.pb(a[i]);
        suma += a[i];
    }
    fore(i,1,n+1) cin >> b[i];

    sort(ALL(ca));

    tope = n-1;
    while(tope>=0){
        if (suma <= x) break;

        suma -= ca[tope];
        tope--;
    }

    fore(i,1,n+1){
        difs.pb({b[i]-a[i],i});
    }

    sort(ALL(difs));

    int l = 0;
    int r = n;
    while(l < r){
        int mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid-1;
    }

    vector <pii> v;
    fore(i,0,sz(difs)){
        if (i < l){
            v.pb({b[difs[i].snd],difs[i].snd});
        }
        else v.pb({a[difs[i].snd],difs[i].snd});
    }

    sort(ALL(v));

    ll sum = 0;
    for(auto &elm : v ) sum += elm.fst;

    int tope2 = sz(v)-1;
    while(tope2 >= 0){
        if (sum <= x) break;

        sum -= v[tope2].fst;
        tope2--;
    }

    fore(i,0,sz(v)){
        if (a[v[i].snd] == v[i].fst) res[v[i].snd] = 1;
        else if (b[v[i].snd] == v[i].fst) res[v[i].snd] = 2;
    }

    fore(i,1,n+1) cout << res[i] << " ";
    cout << nl;
    return 0;
}