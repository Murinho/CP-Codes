#include <bits/stdc++.h>
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
#define ld long double

using namespace std;

const ll maxn = 1e5+10;
ll x,y,x2,y2;

ld dis(ld cx, ld cy, ld cx2, ld cy2){
    return sqrt(((cx-cx2)*(cx-cx2)) + ((cy-cy2)*(cy-cy2)));
}

ld f(ld mx){
    return dis(x,y,mx,0) + dis(x2,y2,mx,0);
}


ld ts(ld l, ld r){
    ld eps = 1e-9;
    while(r-l > eps){
        ld m1 = l + (r-l)/3;
        ld m2 = r - (r-l)/3;
        ld f1 = -f(m1);
        ld f2 = -f(m2);
        if (f1 < f2) l = m1;
        else r = m2;
    }
    return f(l);
}

void doit(){
    cin >> x >> y >> x2 >> y2;
    ld ans = ts(min(x,x2),max(x,x2));
    cout << fixed << setprecision(9) << ans << nl;
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