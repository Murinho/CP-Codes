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
#define ld long double
#define ALL(a) a.begin(), a.end()

using namespace std;//

const ld eps = 1e-9, inf = 1e9;

struct Point{
    ld x,y;
    Point() {}
    Point(ld x, ld y): x(x), y(y) {}
    Point operator +(const Point &b) const { return Point{x+b.x, y+b.y};}
    Point operator -(const Point &b) const { return Point{x-b.x, y-b.y};}
    ld operator *(const Point &b) const { return (ld)x * b.y - (ld)y * b.x;}
    Point operator *(const ld k) const { return Point{x*k,y*k}; }
    ld dot(const Point &b){ return (x*b.x) + (y*b.y);}
};

struct Halfplane{
    Point p,pq;
    ld angle;

    Halfplane(const Point &a, const Point &b): p(a), pq(b-a){
        angle = atan2l(pq.y, pq.x);
    }

    bool out(const Point &r){
        Point ot = r-p;
        return (pq*ot) < -eps;
    }

    bool operator < (const Halfplane &e) const {
        return angle < e.angle;
    }

    friend Point inter(const Halfplane &s, const Halfplane &t){
        Point ot = t.p - s.p;
        ld alpha = (ot*t.pq) / (s.pq*t.pq);
        return s.p + (s.pq * alpha);
    }
};

vector <Point> hp_intersect(vector<Halfplane>& H){
    Point box[4] = {
        Point(inf,inf),
        Point(-inf,inf),
        Point(-inf,-inf),
        Point(inf,-inf)
    };

    for(int i = 0; i<4; i++){
        Halfplane aux(box[i], box[(i+1)%4]);
        H.pb(aux);
    }

    sort(ALL(H));
    deque <Halfplane> dq;

    int len = 0;
    for(int i = 0; i<sz(H); i++){
        while(len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))){
            dq.pop_back();
            --len;
        }

        while(len > 1 && H[i].out(inter(dq[0], dq[1]))){
            dq.pop_front();
            --len;
        }

        if (len > 0 && fabsl((H[i].pq*dq[len-1].pq)) < eps){

            if (H[i].pq.dot(dq[len-1].pq) < 0.0) return vector<Point>();

            if (H[i].out(dq[len-1].p)){
                dq.pop_back();
                --len;
            }
            else continue;
        }
        
        dq.push_back(H[i]);
        ++len;
    }

    while(len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))){
        dq.pop_back();
        --len;
    }

    while(len > 2 && dq[len-1].out(inter(dq[0], dq[1]))){
        dq.pop_front();
        --len;
    }

    if (len < 3) return vector<Point>();

    vector <Point> pts;
    for(int i = 0; i<sz(dq); i++){
        int j = (i+1)%sz(dq);
        pts.pb(inter(dq[i],dq[j]));
    }
    return pts;
}

ld get_poly_area(vector <Point> poly){
    if (sz(poly) <= 2) return 0.0;
    ld ans = 0;
    poly.pb(poly.front());
    fore(i,1,sz(poly)) ans += (poly[i-1]*poly[i]);
    return abs(ans)/2.0;
}

ll n;
vector <Point> poly;

int main(){
    fast;
    cin >> n;
    vector <Halfplane> hps;
    fore(i,0,n){
        ll x,y;
        cin >> x >> y;
        poly.pb(Point(x,y));
    }

    for(int i = n-1; i>=0; i--){
        Halfplane hp(poly[i],poly[(i-1+n)%n]);
        hps.pb(hp);
    }

    vector <Point> final_poly = hp_intersect(hps);
    
    ld ans = get_poly_area(final_poly);

    cout << fixed << setprecision(9) << ans << nl;
    return 0;
}