#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)


using namespace std;

const ld Pi=acosl((ld)-1);
const ld r2 = sqrtl((ld)2);

const int C=1e5+5;

struct Point {
    ld x,y;
    Point operator + (const Point &b) const{ return Point {x+b.x , y+b.y};}
    Point operator - (const Point &b) const{ return Point {x-b.x , y-b.y};}
    ld magnitud()const{
        return sqrtl(x*x + y*y);
    }
    ld angle (const Point &b){
        return acosl((x*b.x + y*b.y) / (magnitud()*(b.magnitud())) );
    }

    ld dis (const Point &b){
        return sqrtl((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y));
    }
};

ld angle2( Point p1,  Point p2,  Point p3){
    p1= p1-p2;
    p3= p3 -p2;

    ld ang = p3.angle(p1);
 
    return ang;
}


Point puntos[C];

int n;

int main(){
    fast;
    cin>>n;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        puntos[i].x = x;
        puntos[i].y = y;

    }
    ld res=0;

    for(int i=0;i<n;i++){
        Point prev1 = puntos[(i-1 + n)%n];
        Point prev2 = puntos[(i-2 +n)%n];

        Point pos1 = puntos[(i+1)%n];
        Point pos2 = puntos[(i+2)%n];

        ld dist=puntos[i].dis(prev1);
        dist+=puntos[i].dis(pos1);

        ld l = prev1.dis(pos1);

        ld a1 = angle2(prev2, prev1, pos1);
        ld a2 = angle2(prev1, pos1, pos2);


        a1 = Pi - a1;
        a2 = Pi - a2;

        if (a1 + a2 < Pi/2){
            ld lol = l*(sinl(a1)+sinl(a2))/sinl(a1+a2);
            res=max(res, lol-dist);
        } else {
            
            ld b1=a1 - Pi/2;
            ld b2=a2 - Pi/2;

            ld right = max(b1, Pi/2 - a2);
            right =max(right,(ld)0);

            ld left = max(b2, Pi/2 - a1);
            left = max((ld)0, left);

        
            if(left <= Pi/4 && right<= Pi/4){
                res = max(res, l*r2 - dist);
            } else {
                
               ld mx=max(left, right);

               ld lol = l*(sinl(mx) + cosl(mx));

               res=max(res, lol-dist);

            }
        }
    }

    cout << fixed << setprecision(15) << res <<"\n";


    return 0;

}