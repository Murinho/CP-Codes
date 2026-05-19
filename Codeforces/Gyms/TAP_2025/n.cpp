#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define ppb pop_back
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())

using namespace std;

struct Point{
    ll x,y;

    Point operator -(const Point &b) const { return Point{x-b.x, y-b.y}; }
    ll operator *(const Point &b) const { return x * b.y - y * b.x; }
    bool operator <(const Point &b) const { return x == b.x ? y < b.y : x < b.x; }
    bool operator ==(const Point &b){
        if (b.x == (*this).x && b.y == (*this).y) return true;
        return false;
    }
    ll cross(const Point &b, const Point &c) const {
        ll cruz = (b - *this) * (c - *this);
        if (cruz < 0) return -1;
        if (cruz > 0) return +1;
        return 0;
    }
};

vector <Point> calculateHull(vector <Point> &p, int n){
    if (n <= 2) return p;
    vector <Point> hull;
    int tam = 0;
    sort(ALL(p));

    fore(t,0,2){
        fore(i,0,n){
            while(sz(hull)-tam >= 2){
                Point p1 = hull[sz(hull)-2];
                Point p2 = hull[sz(hull)-1];

                if (p1.cross(p2,p[i]) <= 0) break;
                hull.ppb();
            }
            hull.pb(p[i]);
        }
        hull.ppb();
        tam = sz(hull);
        reverse(ALL(p));
    }
    return hull;
}

int mov[4][2] = {{1,1},{-1,-1},{-1,1},{1,-1}};

int main(){
    fast;
    ll n;
    cin >> n;
    vector <Point> pts;
    fore(i,0,n){
        ll x,y;
        cin >> x >> y;
        fore(j,0,4){
            Point p;
            p.x = x + mov[j][0];
            p.y = y + mov[j][1];
            pts.pb(p);
        }
    }

    sort(ALL(pts));
    pts.erase(unique(ALL(pts)),pts.end());

    vector <Point> res = calculateHull(pts,sz(pts));

    ll ans = 0;

    fore(i,0,sz(res)){
        int j = (i+1)%sz(res);
        ans += abs(res[i].x - res[j].x);
        ans += abs(res[i].y - res[j].y);
    }

    cout << ans << nl;
    return 0;
}