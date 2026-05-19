#include <bits/stdc++.h>
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
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

struct Point{
    ll x,y,t;
};

ll n,ans=0,totb=0,totw=0,curb=0,curw=0;
map <ll, vector <Point> > mpx,mpy;

int main(){
    fast;   
    cin>>n;
    fore(i,0,n){
        Point p;
        char c;
        cin>>p.x>>p.y;
        cin>>c;
        p.t = (c == 'b' ? 1 : 2);
        if (p.t == 1) totb++;
        else totw++;
        mpx[p.x].pb(p);
        mpy[p.y].pb(p);
    }

    // Do it in x order:
    for(auto au : mpx){
        vector <Point> ps = au.snd;
        for(auto elm : ps){
            if (elm.t == 1) curb++;
            else curw++;
        }
        ans = max({ans,curb + (totw-curw),curw + (totb-curb)});
    }
    // Do it in y order:
    curb=curw=0;
    for(auto au : mpy){
        vector <Point> ps = au.snd;
        for(auto elm : ps){
            if (elm.t == 1) curb++;
            else curw++;
        }
        ans = max({ans,curb + (totw-curw),curw + (totb-curb)});
    }
    cout<<ans<<nl;
    return 0;
}