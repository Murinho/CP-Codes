#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n' 
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define ld long double
#define eb emplace_back

using namespace std;

const ld eps = 1e-8;
ld p,r,y;
ld n,e,s,w;
ld minis = 10.0;

ld f(ld x){
    w = x;
    e = p + w;
    ld c1 = w + e;
    ld c2 = y - c1;
    n = (r+c2)/2.0;
    s = n-r;
    //cout<<n<<" "<<e<<" "<<s<<" "<<w<<nl;
    return max({abs(n),abs(e),abs(s),abs(w)});
}

ld binaria(ld l, ld r){  
    while(r-l > eps){
        ld m1 = (l + r) / 2.0;
        ld f1 = f(m1);
        if (f1 < minis){
            r = m1;
            minis = f1;
        }
        else{
            l = m1;
        }
    }
    return r; // fixed w.
}

int main(){
    fast;
    ll q;
    cin>>q;
    while(q--){
        cin>>p>>r>>y;

        ld na,ea,sa,wa;
        ld mini=10.0;

        n=(y+r+p)/4.0;
        e=n;
        s=n-r;
        w=e-p;
        if(mini > max({abs(n),abs(e),abs(s),abs(w)})){
            mini = max({abs(n),abs(e),abs(s),abs(w)});
            na=n; ea=e; sa=s; wa=w;
        }

        // Problema
        //ld neg_w = binaria(-1.0,0.0); 
        ld pos_w = binaria(0.0,1.0);

        //ll e1 = f(neg_w);
        ll e2 = f(pos_w);   
        /*if (e1 < e2){
            // neg_w esta mejor evaluado que e2, entonces volver a calcular los valores de n,e,s,w.
              f(neg_w);
        }*/
        if(mini > max({abs(n),abs(e),abs(s),abs(w)})){
            mini = max({abs(n),abs(e),abs(s),abs(w)});
            na=n; ea=e; sa=s; wa=w;
        }

        n=(y+r-p)/4.0;
        w=n;
        e=p+w;
        s=n-r;
        if(mini > max({abs(n),abs(e),abs(s),abs(w)})){
            mini = max({abs(n),abs(e),abs(s),abs(w)});
            na=n; ea=e; sa=s; wa=w;
        }

        e=(y-r+p)/4.0;
        s=e;
        n=r+s;
        w=e-p;
        if(mini > max({abs(n),abs(e),abs(s),abs(w)})){
            mini = max({abs(n),abs(e),abs(s),abs(w)});
            na=n; ea=e; sa=s; wa=w;
        }

        s=(y-r-p)/4.0;
        w=s;
        n=r+s;
        e=p+w;
        if(mini > max({abs(n),abs(e),abs(s),abs(w)})){
            mini = max({abs(n),abs(e),abs(s),abs(w)});
            na=n; ea=e; sa=s; wa=w;
        }

        cout<<fixed<<setprecision(9)<<na<<" "<<ea<<" "<<sa<<" "<<wa<<"\n";
    }
    return 0;
}