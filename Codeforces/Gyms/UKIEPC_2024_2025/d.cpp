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

    using namespace std;

    const ld eps = 1e-6;

    ld p,r,y;

    int main(){
        fast;
        ll q;
        cin>>q;
        cout.precision(10);
        while(q--){
            cin>>p>>r>>y;
            ld n,e,s,w;
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
            /*
            e=(y-r-p)/4.0;
            n=e;
            w=e-p;
            s=n-r;
            if(r == 0 && p == 0)n=e=s=w=y/4.0;
            if(mini > max({abs(n),abs(e),abs(s),abs(w)})){
                mini = max({abs(n),abs(e),abs(s),abs(w)});
                na=n; ea=e; sa=s; wa=w;
            }*/

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

            cout<<na<<" "<<ea<<" "<<sa<<" "<<wa<<"\n";
        }
    }