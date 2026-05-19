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

const ll maxn = 1e5+10;

ll n,pos;
vi h,d,ad,od;
bool ok;

void init(){
    h.clear(), h.resize(n);
    od.clear(), od.resize(n-1);
    d.clear(), d.resize(n);
    ad.clear(), ad.resize(n);
    ok=false;
}

void solve(){
    pos=0;
    fore(i,0,n-1){
        if (pos < i) break;
        ll l = i;
        ll r = n-1;
        while(l < r){
            ll mid = (l+r+1)/2;
            ll totd = ad[mid] - ad[i];
            if (totd < h[i]) l = mid;
            else r = mid-1;
        }
        //cout<<i<<"-> "<<r<<" ... "<<ad[r]<<nl;
        pos = max(pos,r);
    }
    if (pos+1 == n) ok=true; //pos indica la ultima ficha tirada.
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        cin>>n;
        init();
        fore(i,0,n) cin>>h[i];
        ad[0]=0;
        fore(i,1,n){
            cin>>d[i];
            od[i-1] = d[i];
            ad[i] = d[i] + ad[i-1];
        }
        solve();
        if (!ok){
            reverse(ALL(h));
            reverse(ALL(od));
            fore(i,1,n) d[i] = od[i-1];
            ad[0]=0;
            fore(i,1,n){
                ad[i] = d[i] + ad[i-1];
            }
            solve();
        }
        if (ok) cout<<"habibi"<<nl;
        else cout<<"which"<<nl;
    }
    return 0;
}