#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define nl '\n'


using namespace std;

const int C=1e5 +5;

ll xs,ys, xe, ye;
vector<pair<pl,pi>>pos[4];

void ps(ll x, ll y){
    ll det = x*ye - y*xe;

    if(det>0)pos[0].pb({{x,y},{0,0}});
    if(det<0)pos[1].pb({{x,y},{0,0}});

    if(det == 0){
        if(xe==0){
            if(y>ye)pos[2].pb({{x,y},{0,0}});
            else pos[3].pb({{x,y},{0,0}});
        } else {
            if(x>xe)pos[2].pb({{x,y},{0,0}});
            else pos[3].pb({{x,y},{0,0}});
        }
    }
}

ll res=0;

bool comp(pair<pl,pi> al, pair<pl,pi> bl){
    auto a= al.f;
    auto b=bl.f;
    
    //No morir gcd 0
    ll d=gcd(a.f, a.s);
   
    pl v={a.f/d, a.s/d};

    if(b.f*v.s == b.s*v.f){
        return a.f*a.f + a.s*a.s < b.f*b.f + b.s*b.s;
        
    }

    return (ld)(a.f*xe + a.s*ye)/(sqrt((ld)a.f*a.f + a.s*a.s)) > (ld)(b.f*xe + b.s*ye)/(sqrt((ld)b.f*b.f + b.s*b.s));
}


bool comp2(pair<pl,pi> al, pair<pl,pi> bl){
    auto a= al.f;
    auto b=bl.f;

    a.f-=xe;
    a.s-=ye;

    b.f-=xe;
    b.s-=ye;

    //No morir gcd 0
    ll d=gcd(a.f, a.s);
    
    pl v={a.f/d, a.s/d};

    if(b.f*v.s == b.s*v.f){
        return a.f*a.f + a.s*a.s < b.f*b.f + b.s*b.s;
        
    }

    return (ld)(a.f*xe + a.s*ye)/(sqrt((ld)a.f*a.f + a.s*a.s)) < (ld)(b.f*xe + b.s*ye)/(sqrt((ld)b.f*b.f + b.s*b.s));
}


int s[4*C];

void bd(int a, int b, int c){
    if(a==b){
        s[c]=0;
        return;
    }
    int m=(a+b)/2;
    bd(a,m,2*c);
    bd(m+1,b,2*c+1);
    s[c]=0;
}

int que(int a, int b, int c, int q){
    if(b<=q) return s[c];
    if(a>q) return 0;
    int m=(a+b)/2;
    return que(a,m,2*c,q) + que(m+1,b,2*c+1,q);
}

void up(int a, int b, int c, int q){
    if(b==q && a==q){
        s[c]++;
        return;
    }
    if(b<q || a >q) return;
    int m=(a+b)/2;
    up(a,m,2*c,q), up(m+1,b,2*c+1,q);
    s[c]=s[2*c]+s[2*c+1];
}


ll cont(vector<pair<pl,pair<int,int>>> p){

    if((int) p.size() <2)return 0;

    ll res=0;
    sort(p.begin(), p.end(), comp);


    for(int i=0;i <(int) p.size(); i++){
        //cout << p[i].f.f <<" " << p[i].f.s <<", ";
    
        p[i].s.f=i;
    }
    //cout <<"\n";

    sort(p.begin(), p.end(), comp2);


    for(int i=0;i <(int) p.size(); i++){
        //cout << p[i].f.f <<" " << p[i].f.s <<", ";
        p[i].s.s=i;
    }
    //cout <<"\n";


    vector<pi>ayuda;

    for(auto r:p)ayuda.pb(r.s);
    sort(ayuda.begin(), ayuda.end());


    int t=ayuda.size();

    bd(0,t,1);
    

    for(auto r:ayuda){
        //cout << r.first << " " << r.second << ", ";
        res+=que(0,t,1,r.s);
        up(0,t,1,r.s);
    }
    //cout << nl;


    return res;

}

int main(){

    cin>>xs>>ys>>xe>>ye;

    xe-=xs;
    ye-=ys;

    ll n;
    cin>>n;

    for(ll  i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        x-=xs;
        y-=ys;

        ps(x,y);
    }

    ll res=0;

    ll logan, adrian;
    logan=cont(pos[0]);

    //muere aqui
    adrian = cont(pos[1]);
  


    //cout << logan <<" " << adrian<<"\n";
    //cout << pos[0].size() <<" " << pos[1].size()<<"\n";



    res+=logan;
    res+=adrian;
    
    ll t=pos[2].size();
    res+=t*(t-1)/2;

    t=pos[3].size();
    res+=t*(t-1)/2;

    //cout << pos[2].size() <<"\n";
   // cout << pos[3].size() <<"\n";


    cout << res <<"\n";

    
}

/*
1 1 -1 5
8
-2 7
-3 9
2 -1
3 -3
1 7
1 8
2 11
-1 1
*/