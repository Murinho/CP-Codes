#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i <b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; --i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define fst first
#define snd second

using namespace std;

const ll maxn = 320;
const ll offs = 105;

struct Circle{
    ll x,y,r;
};

struct Point{
    ll x,y;
};

ll n;
Circle c[12];

ll dist(Point p1, Point p2){ //without sqrt.
    Point p3;
    p3.x = p1.x - p2.x;
    p3.y = p1.y - p2.y;
    return ((p3.x*p3.x) + (p3.y*p3.y));
}

bool check(int fil, int col){
    fil -= offs;
    col -= offs;
    Point p1;
    p1.x = fil;
    p1.y = col;
    fore(i,0,n){
        Point p2;
        p2.x = c[i].x;
        p2.y = c[i].y;
        ll d = dist(p1,p2);
        //cout<<d<<": "<<p1.x<<" "<<p1.y<<" ... "<<p2.x<<" "<<p2.y<<nl;
        if (d <= c[i].r*c[i].r) return true;
    }
    return false;
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n){
        ll x,y,r;
        cin>>c[i].x>>c[i].y>>c[i].r;
        c[i].x *= 10;
        c[i].y *= 10;
        c[i].r *= 10;
    }

    //Check all cells.
    ll ans=0;
    fore(i,0,maxn){
        fore(j,0,maxn){
            if (check(i,j)) ans++;
        }
    }
    //cout<<"ans: "<<ans<<nl;
    ld res = (ld)(ans)/100.0;
    cout<<fixed<<setprecision(9)<<res<<nl;
    return 0;
}