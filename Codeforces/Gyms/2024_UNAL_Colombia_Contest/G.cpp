// Problem: G. Chocolate Volcano
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 2e5+100;
const ld EPS = 1e-6;
const ld pi = 3.1415926535;
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
    ld determinant(const Point &b){ return (((*this).x) * b.y) - ((*this).y * b.x); } //determinante 2x2
};

ll n,k;
ld sum[maxn];

void calcArea(vector <Point> &poly){ //Calculo de area de poligono
    fore(i,0,n+2){
    	if (i == n+1) sum[i] = poly[i].determinant(poly[0]);
    	else sum[i] = poly[i].determinant(poly[i+1]);
    	if (i>0) sum[i] += sum[i-1]; 
    }
}

void ecuacionDeRecta(ld &fa, ld &fb, ld &fc, Point &p1, Point &p2){ //dados 2 puntos de una recta, devuelve los coeficientes de Ax + By + C = 0
    fa = p1.y-p2.y;
    fb = p2.x-p1.x;
    fc = -(fa*p1.x) - (fb*p1.y);
    return;
}

ld getYpt(ld &fa, ld &fb, ld &fc, ld &x){
	return ((fa*x) + fc)/(-fb);
}

vector <Point> a;

void init(){
	a.resize(n+2);
}

ld getFormedArea(ld ar, Point &p1, Point &p2, Point &p3){
	ar += p1.determinant(p2);
	ar += p2.determinant(p3);
	ar += p3.determinant(a[0]);
	ar = abs(ar)/2.0;
	return ar;
}

int main(){
    fast;
    cin>>n>>k;
    init();
	fore(i,1,n+1) cin>>a[i].x;
	fore(i,1,n+1) cin>>a[i].y;
	a[0].x = a[1].x;
	a[0].y = 0.0;
	a[n+1].x = a[n].x;
	a[n+1].y = 0.0;
	
	calcArea(a);
	ld totarea = abs(sum[n+1])/2.0;
	ld tar = totarea/(ld)k; //target slice size.
	ll cnt = 1;
	
	Point paux,p2,p3;
	ld ar,lasans;
	fore(i,1,n+1){ //i-1 --- i; (connection).
		ar = sum[i-1];
		paux.x = a[i].x;
		paux.y = 0.0;
		ar += a[i].determinant(paux); //last point -- ground.
		ar += paux.determinant(a[0]); //ground -- beginning.
		ar = abs(ar)/2.0;
		ld fa,fb,fc;
		ecuacionDeRecta(fa,fb,fc,a[i-1],a[i]); //gives the equation of the line.
		lasans = a[i-1].x;
		while(cnt < k && tar*(ld)cnt <= ar){
			//make binary search between points (i-1) and i.
			ld l = lasans;
			ld r = a[i].x;
			p3.y = 0.0;
			while (r-l > EPS){
				ld mid = (l+r)/2.0;
				ld ypt = getYpt(fa,fb,fc,mid);
				p2.x = mid, p2.y = ypt;
				p3.x = mid;
				if (getFormedArea(sum[i-1],a[i],p2,p3) <= tar*(ld)cnt) l = mid;
				else r = mid;
			}
			cout<<fixed<<setprecision(6)<<l<<" ";
			lasans = l;
			cnt++;
		}
		if (cnt >= k) break;
	}
	cout<<nl;
	return 0;
}