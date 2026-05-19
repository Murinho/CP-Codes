#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define ppb pop_back

using namespace std;

const ll inf = 1e18;

struct frac{
    ll num,den,ap;
    bool up;
    frac() {}

    frac(ll num, ll den, ll ap): num(num), den(den), ap(ap), up(up){
        if (!num) den = 1;
        if (num > 0 && den < 0) num = -num, den = -den;
        simplify();
    }
    void simplify(){
        ll g = __gcd(abs(num),abs(den));
        if (g) num /= g, den /= g;
    }
    bool operator < (const frac& b) const {
        return num*b.den < den * b.num;
    }
};

struct Point{
    ll x,y,ap;
};

ll n,ans=inf;
vector <Point> p;

int main(){
    fast;
    cin>>n;
    p.resize(n);
    fore(i,0,n){
        cin>>p[i].x>>p[i].y>>p[i].ap;
    }

    fore(i,0,n){
        vector <frac> pf;
        ll sa = 0;
        ll sb = 0;
        fore(j,0,n){
            if (i == j) continue;
            if (p[i].y <= p[j].y){
                sa += p[j].ap;
                frac fr;
                fr.num = p[j].x - p[i].x;
                fr.den = p[j].y - p[i].y;
                fr.ap = p[j].ap;
                fr.up = true;
                pf.pb(fr);
            }
            else{
                sb += p[j].ap;
                frac fr;
                fr.num = p[i].x - p[j].x;
                fr.den = p[i].y - p[j].y;
                fr.ap = p[j].ap;
                fr.up = false;
                pf.pb(fr);
            }
        }
        sort(ALL(pf));
        for(auto &fr : pf){
            if (fr.up){
                sa -= fr.ap;
                ans = min(ans,abs(sa-sb));
                sb += fr.ap;
            }
            else{
                sb -= fr.ap;
                ans = min(ans,abs(sa-sb));
                sa += fr.ap;
            }
        }
    }
    cout<<ans<<nl;
    return 0;
}