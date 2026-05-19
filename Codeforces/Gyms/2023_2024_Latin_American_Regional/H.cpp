// Problem: H. Health in Hazard
// Contest: Codeforces - 2023-2024 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/104736/problem/H
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 2e5+100;
const ld eps = 1e-9, inf = 1e9; 

struct Point {
    ld x, y; //cambiar tipo de dato de acuerdo al problema
    Point (): x(0), y(0){}
	Point (ld x, ld y): x(x), y(y) {};
    void read(){ cin>>x>>y; }
    Point operator +(const Point& b) const { return Point{x+b.x, y+b.y}; } //suma de puntos
    Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; } //resta de puntos
    ld operator *(const Point& b) const { return (ld) x * b.y - (ld) y * b.x; }
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

struct Halfplane { 
    Point p, pq; 
    ld angle;

	// Consider the left part of a vector as the inside part of the halfplane.
    Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);    
    }

    bool out(const Point& r) { 
		Point ot = r-p;
		return (pq*ot) < -eps;
    }

    bool operator < (const Halfplane& e) const { 
        return angle < e.angle;
    } 

    friend Point inter(const Halfplane& s, const Halfplane& t) {
		Point ot = t.p - s.p;
        ld alpha = (ot*t.pq) / (s.pq*t.pq);
        return s.p + (s.pq * alpha);
    }
};

vector<Point> hp_intersect(vector<Halfplane>& H) { 
    Point box[4] = {  // Bounding box in CCW order
        Point(inf, inf), 
        Point(-inf, inf), 
        Point(-inf, -inf), 
        Point(inf, -inf) 
    };

    for(int i = 0; i<4; i++) { // Add bounding box half-planes.
        Halfplane aux(box[i], box[(i+1) % 4]);
        H.pb(aux);
    }

    // Sort by angle and start algorithm
    sort(ALL(H));
    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < sz(H); i++) {

        // Remove from the back of the deque while last half-plane is redundant
        while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }

        // Remove from the front of the deque while first half-plane is redundant
        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }

        // Special case check: Parallel half-planes
        if (len > 0 && fabsl((H[i].pq*dq[len-1].pq)) < eps) {
            // Opposite parallel half-planes that ended up checked against each other.
            if (H[i].pq.dot(dq[len-1].pq) < 0.0) return vector<Point>();
            
            if (H[i].out(dq[len-1].p)){ // Same direction half-plane: keep only the leftmost half-plane.
                dq.pop_back();
                --len;
            }
            else continue;
        }

        // Add new half-plane
        dq.push_back(H[i]);
        ++len;
    }

    // Final cleanup: Check half-planes at the front against the back and vice-versa
    while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    // Report empty intersection if necessary
    if (len < 3) return vector<Point>();

    // Reconstruct the convex polygon from the remaining half-planes.
    vector<Point> pts;
    for(int i = 0; i < sz(dq); i++){
        int j = (i + 1) % sz(dq);
        pts.pb(inter(dq[i], dq[j]));
    }
    return pts;
}

struct Line{
	Point p1,p2;
	Line(Point p1, Point p2): p1(p1), p2(p2) {}
};

vector <Line> a;
ll n;
ld rad;
Point ox = {0.0,0.0};

bool check(ll tar){
	vector <Halfplane> hps;
	fore(i,0,tar){
		hps.eb(a[i].p1,a[i].p2);
	}
	
	vector <Point> poly = hp_intersect(hps);
	
	for(auto &pt : poly){
		if (pt.magnitude() >= rad) return false;
	}
	return true; // ningun punto a Distancia rad es alcanzable.
}

ll bs(){
	if (!check(n)) return n+1;
	ll l = 1;
	ll r = n;
	while(l < r){
		ll mid = (l+r)/2;
		if (!check(mid)) l = mid+1; //fui capaz de llegar a un punto a distancia D.
		else r = mid;
	}
	return l;
}

int main(){
	fast;
	cin>>n>>rad;
	fore(i,0,n){
		Point p1,p2;
		cin>>p1.x>>p1.y>>p2.x>>p2.y;
		// check if the origin is to the left of the line, else swap points.
		
		ll ret = p2.cross(p1,ox);
		if (ret == 1){
			//cout<<"CW"<<nl;
			swap(p1,p2);
		} 
		Line line(p1,p2);
		a.pb(line);
	}
	
	if (n <= 2){
		cout<<"*"<<nl;
		return 0;
	}
	
	ll ans = bs();
	
	if (ans == n+1) cout<<"*"<<nl;
	else cout<<ans<<nl;
	
	/*
	vector <Halfplane> hps;
	for(auto &line : a){
		hps.eb(line.p1,line.p2);
	}
	
	vector <Point> poly = hp_intersect(hps);
	
	cout<<sz(poly)<<nl;
	for(auto &elm : poly) cout<<elm.x<<" "<<elm.y<<" dist: "<<elm.magnitude()<<nl; */
	return 0;
}
