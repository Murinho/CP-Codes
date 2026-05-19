#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long double xc,yc,xd,yd,xb,yb,rb,xr,yr,rr;
    cin>>xc>>yc>>xd>>yd>>xb>>yb>>rb>>xr>>yr>>rr;
    long double x,y;
    xc-=xr;
    yc-=yr;
    xd-=xr;
    yd-=yr;

    x=(xc)*(xc) + (yc)*(yc);
    y = (xd)*(xd) + (yd)*(yd);

    long double d1=x-rr*rr;
    long double d2=y-rr*rr;

    long double f1=sqrt(d1), f2=sqrt(d2);
    long double a1=atan2(f1,rr);
    long double a2=atan2(f2,rr);

    int punt=xc*xd+yc*yd;
    long double cos= (long double)punt/sqrt(x*y);

    cos = acos(cos);
    cos-=a1;
    cos-=a2;
    cos*=rr;

    cout<<fixed<<setprecision(10)<<f1+f2+cos;
}