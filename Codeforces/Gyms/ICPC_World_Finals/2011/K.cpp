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
 
using namespace __gnu_pbds;
using namespace std;

const ld inf = 1e9;

struct Point {
    ld x, y; //cambiar tipo de dato de acuerdo al problema
    void read(){ cin>>x>>y; }
    Point operator +(const Point& b) const { return Point{x+b.x, y+b.y}; } //suma de puntos
    Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; } //resta de puntos
    ll operator *(const Point& b) const { return (ll) x * b.y - (ll) y * b.x; }
    Point operator *(const ld k) const { return Point{x*k,y*k}; }
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

struct LineToPoint{ //calcula la distancia entre un punto y una recta.
    Point p1,p2;
    ld dist(Point refPoint){
        return abs((refPoint - p1) * (refPoint - p2)) / p1.dist(p2);
    }
};

vector <Point> calculateHull(vector <Point> &p, int n){ //Calculo del Convex Hull
    if (n <= 2) return p;
    vector<Point> hull;
    int tam = 0;
    sort(ALL(p));
    fore(t,0,2){
        fore(i,0,n){
            while(sz(hull)-tam >= 2){
                Point p1 = hull[sz(hull)-2];
                Point p2 = hull[sz(hull)-1];
                //Producto cruz: P1 ---> P2 ---> P3 
                //agregar (<=) si tambien se quieren incluir los puntos colineales, sino solo (<)
                if(p1.cross(p2, p[i]) <= 0) break; 
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

bool solve(int tc){
	ld ans = inf;
	ll n;
	vector <Point> a;
	cin>>n;
	if (n == 0) return false;
	
	fore(i,0,n){
		int x,y;
		cin>>x>>y;
		a.pb({x,y});
	}
	
	a = calculateHull(a,n);
	
	for(int i = 0; i<=sz(a); i++){
		Point p1 = a[i];
		Point p2 = a[(i+1)%sz(a)];
		LineToPoint ltp;
		ltp.p1 = p1, ltp.p2 = p2;
		ld mx = 0.0;
		for(int j = 0; j<sz(a); j++){
			if (i == j || ((i+1)%sz(a)) == j) continue;
			mx = max(mx,ltp.dist(a[j]));
		}
		ans = min(ans,mx);
	}
	ll cans = (ll)(ans*1000);
	while(cans%10 > 0) cans++;
	cout<<"Case "<<tc<<": ";
	ans = (ld)cans/1000.0;
	//cout<<cans<<nl;
	cout << fixed << setprecision(2) << ans << nl;
	return true;
}

int main(){
    fast;
    for(int i = 1;;i++){
    	if (!solve(i)) break;
    }
}