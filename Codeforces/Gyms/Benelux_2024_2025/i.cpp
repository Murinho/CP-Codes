#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define fst first
#define snd second
#define sz(a) ((ll) a.size())
#define ALL(a) a.begin(),a.end()
#define ppb pop_back

using namespace std;

const ll maxn = 1e4+10;
const ll inf = 1e18;
ll n,k,dp[maxn],d[maxn],p[maxn],c[maxn];
vi t,f;


void init(){
    t.clear(), t.resize(n+1,0);
    f.clear(), f.resize(n+1,0);
    fore(i,1,n+2) dp[i]=inf;
}


int main(){
    fast;
    cin>>n>>k;
    init();
    fore(i,1,n+1){
        cin>>t[i]>>f[i];
    }

    fore(i,1,k+1){
        cin>>p[i]>>d[i]>>c[i];
    }

    dp[0]=0;
    fore(i,1,n+1){
        dp[i] = min(dp[i], dp[i-1] + f[i]); //fare of the day.
        fore(j,1,k+1){
            ll maxday = t[i] + p[j] - 1; //ultimo dia que aplica el pase.
            ll pos;
            if (maxday >= t[n]) pos = n; //si el ultimo dia es mayor o igual al dia del ultimo viaje.
            else{
                pos = upper_bound(ALL(t),maxday) - t.begin(); //primer posicion donde maxday < t[pos].
                pos--; //ultimo viaje que podria tomar 
            }
            ll maxpos = min(i + d[j] - 1,n); // posicion maxima donde agoto todos mis boletos del pase.
            pos = min(maxpos,pos); //minimo de cuando agoto todos mis boletos y cuando el tiempo me lo permite.
            if (i <= pos) dp[pos] = min(dp[pos],dp[i-1] + c[j]);
        }
    }
    cout<<dp[n]<<nl;
    return 0;
}