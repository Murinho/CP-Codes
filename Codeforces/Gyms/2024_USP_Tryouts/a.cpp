#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(), u.end()
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second;

using namespace std;

const ld eps = 1e-6;

struct Point{
    ld x,y,z;
};
ld dx,dy,dz,rad;
Point v[8];
Point center;
int mov[8][3] = {{-1,-1,-1},{-1,-1,1},{-1,1,-1},{-1,1,1},{1,-1,-1},{1,-1,1},{1,1,-1},{1,1,1}}; //eight directions.

ld dist(Point p){
    return sqrt(((p.x-center.x)*(p.x-center.x))+((p.y-center.y)*(p.y-center.y))+((p.z-center.z)*(p.z-center.z)));
}

bool isValid(Point p, ld trad){
    if (dist(p) >= rad+trad) return true;
    return false;
}

bool insideBox(Point p){
    if (0 <= p.x && p.x <= dx && 0 <= p.y && p.y <= dy && 0 <= p.z && p.z <= dz){
        return true;
    }
    return false;
}

bool check(ld trad){
    Point p;
    fore(i,0,8){
        fore(j,0,8){
            p.x = v[i].x + (mov[j][0]*trad);
            p.y = v[i].y + (mov[j][1]*trad);
            p.z = v[i].z + (mov[j][2]*trad);
            if (insideBox(p) && isValid(p,trad)) return true;
        }
    }
    return false;
}

ld bs(ld l, ld r){
    while(l < r){
        double mid = (l+r)/2.0;
        if (check(mid)) l = mid;
        else r = mid-eps;
    }
    return l;
}

int main(){
    fast;
    cin>>dx>>dy>>dz;
    cin>>center.x>>center.y>>center.z;
    cin>>rad;
    v[0] = {0,0,0};
    v[1] = {dx,0,0};
    v[2] = {0,dy,0};
    v[3] = {dx,dy,0};
    v[4] = {0,0,dz};
    v[5] = {dx,0,dz};
    v[6] = {0,dy,dz};
    v[7] = {dx,dy,dz};
    ld ans = bs(eps,min(dx,dy,dz)/2.0);
    cout<<fixed<<setprecision(9)<<ans<<nl;
    return 0;
}