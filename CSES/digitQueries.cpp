#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
 
const ll tope = 17;
const ll INF = 1e18+2;
ll refs[tope],digs[tope],pten[tope+1];
 
void precalc(){
    refs[0]=9;
    fore(i,1,tope){
        refs[i] = (refs[i-1]*10) + 9;
        //cout<<i<<": "<<refs[i]<<nl;
    }
    digs[0]=9;
    fore(i,1,tope){
        digs[i] = (digs[i-1]*10);
    }
    fore(i,1,tope){
        digs[i] *= (i+1);
        digs[i] += digs[i-1];
        //cout<<i<<": "<<digs[i]<<nl;
    }
    //powers of ten
    pten[0]=1;
    fore(i,1,tope+1) pten[i] = (pten[i-1]*10ll);
}
 
ll getAmou(ll r, ll cut){
    ll digamou = cut+1;
    ll l = pten[cut];
    ll amou;
    if (INF/digamou < (r-l+1)) amou = INF;
    else amou = (r-l+1)*digamou;
    return amou;
}
 
void solve(ll k){
    if (k <= 9){
        cout<<k<<nl;
        return;
    }
    //check where is the cutting point:
    ll cut=0;
    fore(i,0,tope){
        if (digs[i] >= k){
            cut=i;
            break;
        }
    }
    ll l = pten[cut];
    ll r = pten[cut+1]-1;
    //cout<<l<<" "<<r<<nl;
    k -= digs[cut-1];
    //cout<<"now k: "<<k<<nl;
    while(l < r){
        ll mid = (l+r)/2;
        if (getAmou(mid,cut) >= k) r = mid;
        else l = mid+1;
    }
    if (l != pten[cut]) k -= getAmou(l-1,cut);
    //cout<<"here: "<<k<<nl;
    string s = to_string(l);
    int pos = k-1;
    cout<<s[pos]<<nl;
    return;
}
 
int main(){
    fast;
    precalc();
    ll q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        solve(k);
    }
    return 0;
}