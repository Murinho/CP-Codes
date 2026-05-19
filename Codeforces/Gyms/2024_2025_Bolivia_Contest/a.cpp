#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

struct Poly{
    ll a,b,c;
};

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a,b);
}

void simplify(pii &f1){ //simplifies a fraction.
    if (f1.snd == 0 || f1.fst == 0){
        f1.fst = f1.snd = 0;
        return;
    }
    ll mcd = __gcd(abs(f1.fst),abs(f1.snd));
    f1.fst /= mcd;
    f1.snd /= mcd;
}

void equalize(pii &f1, pii &f2){
    ll mcm = lcm(f1.snd,f2.snd); //comun denominador.
    f1.fst *= (mcm/f1.snd);
    f2.fst *= (mcm/f2.snd);
    f1.snd = f2.snd = mcm;
}

pii sumFrac(pii f1, pii f2){
    simplify(f1), simplify(f2);
    if (f1.snd == 0) return f2;
    if (f2.snd == 0) return f1;
    equalize(f1,f2);
    return {f1.fst + f2.fst,f1.snd};
}

pii evalPoly(Poly p, ll x){ // polynomial: a* x^3/3 + b * x^2/2 + c * x
    pii f1={0,0};
    pii f2;
    f2 = {(p.a*x*x*x),3ll};
    f1 = sumFrac(f1,f2);
    f2 = {(p.b*x*x),2ll};
    f1 = sumFrac(f1,f2);
    f2 = {p.c*x,1ll};
    f1 = sumFrac(f1,f2);
    simplify(f1);
    return f1;
}

vi getRoots(Poly p){ //regresa las raices de un polinomio Ax^2 + Bx + c
    ll discrim = (p.b*p.b) - (4ll*p.a*p.c);
    if (discrim < 0ll) return {}; //0 roots.
    else if (discrim == 0){ //1 root.
        return {-p.b/(2ll*p.a)};
    }
    // 2 roots:
    discrim = sqrt(discrim);
    return {(-p.b+discrim)/(2ll*p.a),(-p.b-discrim)/(2ll*p.a)}; 
}

pii evalIntegral(Poly p, ll l, ll r){
    pii f1={0,0},f2,f3;
    f2 = evalPoly(p,r);
    f1 = sumFrac(f1,f2);
    f3 = evalPoly(p,l);
    f3.fst *= (-1); //resta.
    f1 = sumFrac(f1,f3);
    f1.fst = abs(f1.fst);
    return f1;
}

int main(){
    fast;
    ll n;
    cin>>n;
    while(n--){
        Poly p;
        ll l,r; 
        cin>>p.a>>p.b>>p.c>>l>>r;
        vi roots = getRoots(p);
        /*
        for(auto au : roots) cout<<au<<" ";
        cout<<nl;
        continue; */
        pii f1={0,0},f2;
        bool ok=false;
        if (sz(roots)) sort(ALL(roots));
        vector < pii > alps;
        for(auto au : roots) alps.pb({au,0}); // roots: 0.
        alps.pb({l,1}), alps.pb({r,2}); //start: 1, end: 2
        sort(ALL(alps));
        fore(i,0,sz(alps)-1){
            if (alps[i].snd == 1) ok=true;
            if (alps[i].snd == 2) ok=false;
            if (ok && alps[i].fst != alps[i+1].fst){
                f2 = evalIntegral(p,alps[i].fst,alps[i+1].fst);
                f1 = sumFrac(f1,f2);
            }
        }
        simplify(f1);
        cout<<f1.fst<<"/"<<(f1.snd == 0 ? 1 : f1.snd)<<nl;
    }
    return 0;
}