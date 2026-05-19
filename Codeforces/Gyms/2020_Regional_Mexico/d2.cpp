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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

struct Point {
	ll x, y, cost;
	Point operator +(const Point& b) const { return Point{x+b.x, y+b.y};} 
	Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; } 
	ll operator *(const Point& b) const { return (ll) x * b.y - (ll) y * b.x; }
	Point operator *(const ll k)const{return Point{x*k,y*k};}
	bool operator <(const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
	void operator +=(const Point& b) { x += b.x; y += b.y; }
	void operator -=(const Point &b) { x -= b.x; y -= b.y; }
	void operator *=(const int k) { x *= k; y *= k; }
	bool operator ==(const Point &b){
		if (b.x == (*this).x && b.y == (*this).y) return true;
		return false;
	}
	ll magnitude() const { return sqrt((x*x) + (y*y)); }
	ll dot (const Point &b){ return (x * b.x) + (y * b.y); }
	// If dot product > 0, angle between vectors is acute, = 0 vectors are perpendicular, and if < 0, angle is obtuse
	ll dist (const Point & b){return (*this - b).magnitude();} 
	ll cross(const Point& b, const Point& c) const {
		ll cruz = (b - *this) * (c - *this);
		if (cruz < 0) return -1; //cw (right)
		if (cruz > 0) return +1; //ccw (left)
		return 0; //Collinear.
	}
	ll rawCross(const Point &a, const Point &b) const { 
		return (a - *this) * (b - *this);
	}
	bool onSegment(Point p, Point r){ //point in a rectangular box
		if ((*this).x <= max(p.x, r.x) && (*this).x >= min(p.x, r.x) && (*this).y <= max(p.y, r.y) && (*this).y >= min(p.y, r.y)) return true;
		return false;
	}
	ll angleBetweenVectors(const Point &b){ //this: (b-a), Point b: (c-a).
		ll ang = acos((*this).dot(b)/((*this).magnitude() * b.magnitude()));
		ang = (ang * 180.0) / PI;
		return ang; //return angle in degrees.
	}
	int half() const { // for angular sweep
		if ((*this).y > 0) return 0;
		if ((*this).y < 0) return 1;
		return (*this).x >= 0 ? 0 : 1;
	}
};


int main(){
	ll n;
	cin >> n;
    Point p1;
   	// p1.x = -1, p1.y = -1, p1.cost = 1;
   	p1.x = 1, p1.y = 1, p1.cost = 1;
   	
   	Point p2;
   	p2.x = 1, p2.y = -1, p2.cost = 1;
   	
   	Point p3;
   	p3.x = 0, p3.y = 0, p3.cost = 1;
   	
   	cout << p3.rawCross(p1,p2) << nl;
}