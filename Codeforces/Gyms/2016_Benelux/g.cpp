#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define x first
#define y second
 
using namespace std;

const ll inf = 1e9+7;

struct rect{
    ll x1,y1,x2,y2;
    rect() {};

    rect(ll x1, ll y1, ll x2, ll y2): x1(x1), x2(x2), y1(y1), y2(y2) {};

    rect inter (rect other){
        ll x3 = max(x1, other.x1);
        ll y3 = max(y1, other.y1);
        ll x4 = min(x2, other.x2);
        ll y4 = min(y2, other.y2);
        return rect(x3, y3, x4, y4);
    }
};

int valid(int a, int b){
    return (a+b)%2 == 0;
}

pii rotate45(int x, int y){
    return {x+y, y-x};
}

pii undorotate45(int x, int y){
    return {(x-y)/2, (y+x)/2};
}

vector <pair <pii,int> > u;

int dist(pii a, pii b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool ok(pii a){
    fore(i,0,sz(u)){
        if (dist(u[i].x, a) != u[i].y) return false;
    }
    return true;
}

int main(){
    fast;
    int n;
    cin >> n;
    rect inter;
    fore(i,0,n){
        int a,b,d;
        cin >> a >> b >> d;
        u.eb(pii{a,b},d);
        if (n == 1 && d > 0){
            cout << "uncertain" << nl;
            return 0;
        }

        vector <pii> pts;
        pts.eb(rotate45(a-d,b));
        pts.eb(rotate45(a+d, b));
        pts.eb(rotate45(a, b-d));
        pts.eb(rotate45(a, b+d));
        rect r(inf,inf,-inf,-inf);

        for(auto u : pts){
            r.x1 = min(r.x1, u.x);
            r.x2 = max(r.x2, u.x);
            r.y1 = min(r.y1, u.y);
            r.y2 = max(r.y2, u.y);
        }
        if (i == 0) inter = r;
        else inter = inter.inter(r);
    }

    set <pii> ans;
    if (inter.x1 <= inter.x2 && inter.y1 <= inter.y2){
        if (valid(inter.x1, inter.y1)){
            if (ok(undorotate45(inter.x1, inter.y1))){
                ans.insert(undorotate45(inter.x1, inter.y1));
            }
        }
        if (valid(inter.x1, inter.y2)){
            if (ok(undorotate45(inter.x1, inter.y2))){
                ans.insert(undorotate45(inter.x1, inter.y2));
            }
        }
        if (valid(inter.x2, inter.y1)){
            if (ok(undorotate45(inter.x2, inter.y1))){
                ans.insert(undorotate45(inter.x2, inter.y1));
            }
        }
        if (valid(inter.x2, inter.y2)){
            if (ok(undorotate45(inter.x2, inter.y2))){
                ans.insert(undorotate45(inter.x2, inter.y2));
            }
        }
    }
    if (sz(ans) == 0) cout << "impossible" << nl;
    else if (sz(ans) > 1) cout << "uncertain" << nl;
    else{
        cout << ans.begin()->x << " " << ans.begin()->y << nl;
    }
    return 0;
}