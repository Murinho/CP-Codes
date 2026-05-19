#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define vi vector<ll>
#define vvi vector<ll>
#define pii pair <ll,ll>
#define sz(a) (ll)a.size()
#define ALL(a) a.begin(),a.end()


using namespace std;

struct Point
{
  ll x,y;
  Point(ll x,ll y): x(x),y(y){};
  Point operator-(const Point &b){return Point(x-b.x,y-b.y);}
  ll dot(const Point &b) const {return x*b.x + y*b.y;}
  ll cross(const Point &b) const {return x*b.y - y*b.x;}
};

ll mag(Point p1, Point p2){
  p1 = p1 - p2;
  return p1.dot(p1);
}

ll area(Point p1,Point p2, Point p3){
  ll res=0;
  res+=p1.cross(p2);
  res+=p2.cross(p3);
  res+=p3.cross(p1);

  return abs(res*res);
}

int main(){
  fast;

  int a,b,c;
  cin>>a>>b>>c;

  if(b<c)swap(b,c);
  if(a<c)swap(a,c);
  if(b<a)swap(b,a);

  Point p1(0,-b);
  Point p2(-c,b+c);
  Point p3(a+b,-a);

  ll d = 4 * area(p1,p2,p3);
 
  ll res = b*b + c*c + a*a + 2*a*c;

  ll n = mag(p1,p2)*mag(p3,p2)*mag(p1,p3);

  if(n < res*d){
    n = res;
    d=1;
  }

  
  cout << fixed << setprecision(13)<<sqrtl(n)/sqrtl(d)<<"\n";

}