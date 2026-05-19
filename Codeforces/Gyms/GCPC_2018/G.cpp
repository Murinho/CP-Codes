#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())
#define ld long double
#define pi acos(-1.0)

using namespace std;

int n;
long double x,y;


vector<long double> cruz(vector<long double>&a, vector<long double>&b){
    vector<long double>cruz(3);
    cruz[0]=a[1]*b[2]-a[2]*b[1];
    cruz[1]=a[2]*b[0]-a[0]*b[2];
    cruz[2]=a[0]*b[1]-a[1]*b[0];
    return cruz;
}

vector<long double> rotar(vector<long double>&a, vector<long double>&b, long double th){
    vector<long double>ro(3);
    vector<long double>p;
    p=cruz(a,b);
    //cout << fixed << setprecision(9) << cos(th) << " " << sin(th) << nl;
    ro[0]=a[0]*cos(th)+p[0]*sin(th);
    ro[1]=a[1]*cos(th)+p[1]*sin(th);
    ro[2]=a[2]*cos(th)+p[2]*sin(th);
    return ro;
}

ld dot(vector <ld> a, vector <ld> b){
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

int main(){
    fast;
    cin>>n;
    cin>>x>>y;
    x/=180.0;
    x*= pi;
    y/=180.0;
    y*= pi;
    vector<ld>p1={cos(x),sin(x),0};
    vector<ld>v1= {sin(x),-cos(x),0};
    p1=rotar(p1,v1,y);

    for(int i=0;i<n;i++){
        ld a,b,c,d;
        cin>>a>>b>>c>>d;
        a/=180.0;
        a*=M_PI;
        b/=180.0;
        b*=M_PI;
    
        c/=6371.0;

        vector<ld>p={cos(a),sin(a),0};
        vector<ld>v={sin(a),-cos(a),0};
        v=rotar(v,p,b);
        p=rotar(p,v,2*M_PI*d);

        p[0]*=c;
        p[1]*=c;
        p[1]*=c;

        p[0] -= p1[0];
        p[1] -= p1[1];
        p[2] -= p1[2];

        ld ppunto = dot(p,{-p1[0],-p1[1],-p1[2]});

        if (ppunto < 0.0){
            ld dis= dot(p,p);
            dis/=299792458.0;
            cout<<fixed<<setprecision(10)<<dis;
        } else cout<<"no signal\n";



    }
   
    return 0;
} 