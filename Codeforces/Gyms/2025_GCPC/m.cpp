#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

const ll maxn = 1e5+100;

vi ids[maxn];
ll n,d,a[maxn];

bool check(ll val){
    ll fav = 1;
    ll pos = 0;
    while(pos < sz(ids[val])){
        if (ids[val][pos] < fav) return false;
        ll pos2 = pos;
        while(pos2 < sz(ids[val]) && ids[val][pos2] - ids[val][pos] + 1 <= d) pos2++;
        pos2--;

        ll dif = ids[val][pos2] - ids[val][pos] + 1;
        ll sobra = d - dif;

        ll diffav = ids[val][pos] - fav;
        if (diffav >= sobra){
            fav = ids[val][pos2] + d + 1;
        }
        else{
            sobra -= diffav;
            fav = ids[val][pos2] + sobra + d + 1;
        }
        pos = pos2+1;
    }
    return true;
}

int main(){
    fast;
    cin >> n >> d;
    fore(i,1,n+1){
        cin >> a[i];
        ids[a[i]].pb(i);
    }

    fore(i,0,n){
        if (check(i)){
            cout << i << nl;
            return 0;
        }
    }
    cout << n << nl;
    return 0;
}