// Problem: I. Inconspicuous Identity
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/I
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

using namespace std;

const ld eps = 1e-6;

struct point3{
	ld x,y,z;
	void read(){
		cin>>x>>y>>z;
	} 
	point3(): x(0), y(0), z(0) {}
	point3(ld x, ld y, ld z): x(x), y(y), z(z) {}
	point3 operator - (const point3 &b) const { return point3(x - b.x, y - b.y, z - b.z);}
	bool operator == (const point3 &b) const {return x == b.x && y == b.y && z == b.z;}
	ld dot(const point3 &b) const { return x*b.x + y*b.y + z*b.z;}
	point3 cross(const point3 &b) const { return {(y*b.z) - (z*b.y), (z*b.x) - (x*b.z), (x*b.y) - (y*b.x)};}
	ld norm(){ return sqrt(x*x + y*y + z*z);}
	void print(){ cout<<x<<" "<<y<<" "<<z<<nl; }
};

struct point2{
	ld x,y;
	point2(): x(0), y(0) {}
	point2(ld x, ld y): x(x), y(y) {}
	ld operator *(const point2& b) const { return (x * b.y) - (y * b.x); }
	void print(){ cout<<x<<" "<<y<<nl; }
};

ld degreesToRadians(ld degrees) {
    return degrees * PI / 180.0;
}

ld get_area3(vector<point3> a) {
	if (sz(a) < 3) return 0;
	point3 ref = a[0];
	ld ret = 0;
	for (int i = 1; i + 1 < sz(a); i++) {
		point3 v1 = a[i] - ref;
		point3 v2 = a[i+1] - ref;
		point3 cp = v1.cross(v2);
		ret += cp.norm();
	}
	ret /= 2.0;
	return ret;
}

ld get_area2(vector <point2> a){
	a.pb(a.front());
	ld ret = 0;
	fore(i,1,sz(a)){
		ret += a[i-1]*a[i];
	}
	ret = abs(ret)/2.0;
	return ret;
}

ld get_ca(ld hip, ld co){
	return sqrt((hip*hip) - (co*co));
}

ld n,k,rads;

ld check3(ld zpos){
	point3 p1(0,0,0); //origin point.
	
	point3 p2(0,get_ca(k,zpos),zpos); // point in the y-axis.
	
	ld xyhip = get_ca(k,zpos);
	
	ld x = xyhip * sin(rads);
	ld y = xyhip * cos(rads);
	
	
	point3 p3(x,y,zpos); // point in diagonal.
	
	ld ar = get_area3({p1,p2,p3});
	ar *= 8.0;
	return ar;
}

ld check2(ld zpos){
	point2 p1(0,0);
	
	point2 p2(0,get_ca(k,zpos));
	
	ld xyhip = get_ca(k,zpos);
	
	ld x = xyhip * sin(rads);
	ld y = xyhip * cos(rads);
	
	point2 p3(x,y);
	//cout<<"2D points: "<<nl;
	//p1.print();
	//p2.print();
	//p3.print();
	ld ar = get_area2({p1,p2,p3});
	//cout<<"One triangle: "<<ar<<nl;
	ar *= 8.0;
	return ar;
}

void solve(){
	cin>>n>>k;
	rads = degreesToRadians(45.0);
	
	//cout<<"sin rads: "<<sin(rads)<<nl;
	//cout<<"cos rads: "<<cos(rads)<<nl;
	//cout<<"Rads: "<<rads<<nl;
	// binary search on the z position of the sticks:
	ld l = 0.0;
	ld r = k;
	while(r - l > eps){
		ld mid = (l+r)/2.0;
		if (check3(mid) <= n) r = mid;
		else l = mid;
	}
	
	//cout<<"End zpos: "<<l<<nl;
	
	ld ans = check2(l);
	cout<< fixed << setprecision(9) << ans << nl;
	return;	
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}