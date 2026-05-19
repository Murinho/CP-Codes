#include <bits/stdc++.h>
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
#define RB(x) (x<n?r[x]:0)
 
using namespace std;

const ld EPS = 1e-6;
const ll INF = 1e18;

struct Point {
    ld x, y; //cambiar tipo de dato de acuerdo al problema
    void read(){ cin>>x>>y; }
    Point operator +(const Point& b) const { return Point{x+b.x, y+b.y}; } //suma de puntos
    Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; } //resta de puntos
    ll operator *(const Point& b) const { return (ll) x * b.y - (ll) y * b.x; }
    bool operator <(const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
    void operator +=(const Point& b) { x += b.x; y += b.y; }
    void operator -=(const Point &b) { x -= b.x; y -= b.y; }
    void operator *=(const int k) { x *= k; y *= k; }
    bool operator ==(const Point &b){
        if (b.x == (*this).x && b.y == (*this).y) return true;
        return false;
    }
    ld magnitude() const { return sqrt((x*x) + (y*y)); } //longitud hipotenusa
    ld dot (const Point &b){ return (x * b.x) + (y * b.y); } //producto punto. 
    // Si es el producto punto es positivo, el angulo entre los vectores es menor a 90 grados, igual a 0 los vectores son perpendiculares y si es negativo el angulo es obtuso.
    ld dist (const Point & b){ return (*this - b).magnitude(); } //distancia entre 2 puntos.
    ll cross(const Point& b, const Point& c) const { //Producto cruz
        ll cruz = (b - *this) * (c - *this);
        if (cruz < 0) return -1; //Clockwise (right)
        if (cruz > 0) return +1; //Counter-clockwise (left)
        return 0; //Collinear.
    }
    ld rawCross(const Point &a, const Point &b) const { 
		return (a - *this) * (b - *this);
	}
    bool onSegment(Point p, Point r){ //checa si un punto esta en el segmento entre dos puntos (delimitado como si fuera un rectangulo)
        if ((*this).x <= max(p.x, r.x) && (*this).x >= min(p.x, r.x) && (*this).y <= max(p.y, r.y) && (*this).y >= min(p.y, r.y)) return true;

        return false;
    }
    ld angleBetweenVectors(const Point &b){ //this: (b-a), Point b: (c-a).
        ld ang = acos((*this).dot(b)/((*this).magnitude() * b.magnitude()));
        ang = (ang * 180.0) / PI;
        return ang; //return angle in degrees.
    }
};

int main(){
    fast;
    ll n;
    cin>>n;
    vector <Point> poly(n);
    fore(i,0,n) cin>>poly[i].x>>poly[i].y;

    ld poly_area = 0.0;

    // compute prefix sums for the points:
    vector <ld> px(n),py(n), pix(n), piy(n);
    fore(i,0,n){
        if (i>0){
            poly_area += (poly[i-1]*poly[i]);
            px[i] = px[i-1] + poly[i-1].x;
            py[i] = py[i-1] + poly[i-1].y;
            pix[i] = pix[i-1] + poly[i-1].x * (i-1);
            piy[i] = piy[i-1] + poly[i-1].y * (i-1);
        }
    }
    poly_area += (poly[n-1]*poly[0]);

    ld sum=0.0;
    fore(i,0,n){
        sum -= (n - 2 * i) * (poly[i].x * py[i] - poly[i].y * px[i]);
        sum -= 2 * (poly[i].x * piy[i] - poly[i].y * pix[i]);
    }

    //cout<<sum<<" "<<poly_area<<nl;

    ld ans = abs(sum/poly_area);
    cout<<fixed<<setprecision(9)<<ans<<nl;
    return 0;
}