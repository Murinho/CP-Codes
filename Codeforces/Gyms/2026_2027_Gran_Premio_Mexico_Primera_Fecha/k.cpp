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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long

using namespace std;

const ll maxn = 505;
const ld eps = 1e-6;
const ld maxans = 1e18;

struct Point{
	ld x,y;	
	
	Point operator +(const Point& b) const { return Point{x+b.x, y+b.y};} 
	Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; } 
	ll operator *(const Point& b) const { return (ll) x * b.y - (ll) y * b.x; }
	Point operator *(const ld k)const{return Point{x*k,y*k};}
	bool operator <(const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
	void operator +=(const Point& b) { x += b.x; y += b.y; }
	void operator -=(const Point &b) { x -= b.x; y -= b.y; }
	void operator *=(const int k) { x *= k; y *= k; }
	bool operator ==(const Point &b){
		if (b.x == (*this).x && b.y == (*this).y) return true;
		return false;
	}
	ld magnitude() const { return sqrt((x*x) + (y*y)); }
	ld dot (const Point &b){ return (x * b.x) + (y * b.y); }
	
	ld angleBetweenVectors(const Point &b){ //this: (b-a), Point b: (c-a).
		ld ang = acos((*this).dot(b)/((*this).magnitude() * b.magnitude()));
		ang = (ang * 180.0) / PI;
		return ang; //return angle in degrees.
	}
};

struct Circle{
	ld x,y,rad;
};

ld dist(Point p1, Point p2){
	return sqrt((ld)((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));
}

bool has_circle_inside(Circle c1, Circle c2){ // c1 is the bigger one
	Point p1 = {c1.x,c1.y};
	Point p2 = {c2.x,c2.y};
	ld dis = dist(p1,p2);
	if (dis + (ld)(c2.rad) > c1.rad) return false;
	
	return true;
}

vector <Point> circleLineIntersection(ld a, ld b, ld c, ld r){ 
	//Dados los coeficientes de la ecuacion de la recta y el radio del circulo con centro en el origen
	vector <Point> pts;
	ld x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
	if (c*c > r*r*(a*a+b*b)+eps){} // 0 points.
	else if (abs (c*c - r*r*(a*a+b*b)) < eps) pts.pb({x0,y0}); // 1 point.
	else{ // 2 points.
		ld d = r*r - c*c/(a*a+b*b);
		ld mult = sqrt (d / (a*a+b*b));
		ld ax, ay, bx, by;
		ax = x0 + b * mult;
		bx = x0 - b * mult;
		ay = y0 - a * mult;
		by = y0 + a * mult;
		pts.pb({ax,ay});
		pts.pb({bx,by});
	}
	return pts;
}

vector <Point> circleCircleIntersection(Circle oc1, Circle oc2){
	Circle c1,c2;
	c1.x = 0, c1.y = 0, c1.rad = oc1.rad;
	
	c2.x = oc2.x - oc1.x, c2.y = oc2.y - oc1.y, c2.rad = oc2.rad;
	ld ca = -2.0*c2.x;
	ld cb = -2.0*c2.y;
	ld cc = (c2.x*c2.x) + (c2.y*c2.y) + (c1.rad*c1.rad) - (c2.rad*c2.rad);
	vector <Point> ret = circleLineIntersection(ca,cb,cc,c1.rad);
	
	for(auto &[x,y] : ret){
		x += oc1.x;
		y += oc1.y;
	}
	
	return ret;
}

// Dados 2 puntos de una recta, devuelve los coeficientes de Ax + By + C = 0
vector <ld> equation_of_line(Point p1, Point p2){ 
	ld a = p1.y-p2.y;
	ld b = p2.x-p1.x;
	ld c = -(a*p1.x) - (b*p1.y);
	return {a,b,c};
}

vector <Circle> a;
bool mk[maxn];
ll n;
ld ans = maxans;
Point ip;

bool all_inside(Point &p){
	for(auto &[x,y,rad] : a){
		Point cur = {x,y};
		ld dis = dist(cur,p);
		if (dis > rad + eps) return false;
	}
	return true;
}


int main(){
    fast;
    
    cin >> n;
    cin >> ip.x >> ip.y;
    fore(i,0,n){
    		ll x,y,r;
    		cin >> x >> y >> r;
    		a.pb({(ld)x,(ld)y,(ld)r});
    }
    
    if (all_inside(ip)){
    		cout << "0.0000000" << nl;
    		return 0;
    }
    
    fore(i,0,n){
    		fore(j,0,n){
    			if (mk[j] || i == j) continue;
    			
    			if (has_circle_inside(a[i],a[j])){
    				mk[i] = true;
    				break;
    			}
    		}
    }
    
    vector <Circle> aa;
    fore(i,0,n) if (!mk[i]) aa.eb(a[i]);
    
    a = aa;
    n = sz(a);
    
    // x-axis: -----
    // y-axis: |
    
    if (n == 1){
    		Point p1;
    		p1.x = a[0].x;
    		p1.y = a[0].y;
    		ans = dist(p1,ip) - a[0].rad;
    }
    else{
    		// find the intersections:
	    vector < vector <Point> > belong(n);
	    
	    fore(i,0,n){
	    		fore(j,i+1,n){
	    			vector <Point> ret = circleCircleIntersection(a[i],a[j]);
	    			for(auto &pt : ret){
	    				if (all_inside(pt)){ // answer is either an intersection point
	    					ans = min(ans,dist(pt,ip));
	    				}
	    			}
	    		}
	    }
	    
	    fore(i,0,n){ 
	    		Point center,ip2;
	    		center.x = 0;
	    		center.y = 0;
	    		ip2.x = ip.x - a[i].x;
	    		ip2.y = ip.y - a[i].y;
	    		vector <ld> coefs = equation_of_line(center,ip2);
	    		
	    		vector <Point> ret = circleLineIntersection(coefs[0],coefs[1],coefs[2],a[i].rad);
	    		
	    		for(auto &elm : ret){
	    			elm.x += a[i].x;
	    			elm.y += a[i].y;
	    			if (all_inside(elm)){
	    				ans = min(ans,dist(ip,elm));
	    			}
	    		}
	    }
    }
    
    cout << fixed << setprecision(10) << ans << nl;
    return 0;
}