#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a)((ll)a.size())
#define lsb(x)((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxdigs = 20;
const ll tope = 1e18;

ll dp[maxdigs],pten[maxdigs],ans=0;
string sa,sb;

void precalc(){
    dp[0]=1;
    dp[1]=9;
    pten[0]=1;
    pten[1]=10;
    fore(i,2,19){
        dp[i]=(dp[i-1]*9ll);
        pten[i]=(pten[i-1]*10ll);
    }
}

void dfs(ll cur, ll &l, ll &r, ll &k, string &sl, string &sr, bool bol, bool bor, ll pv, ll step=0){
    if (step == k){
        ans++;
        return;
    }
    //cout<<"call: "<<cur<<", prev: "<<pv<<nl;
    fore(i,0,10){
        if (i == pv) continue;
        char c = (int)(i+'0');
        if (bol && c < sl[step]) continue;
        else if (bor && sr[step] < c) continue;
        else if (bol && bor && c == sl[step] && sr[step] == c){
            dfs(cur + (i*pten[k-step-1]),l,r,k,sl,sr,true,true,i,step+1);
        }
        else if (bol && c == sl[step]){
            dfs(cur + (i*pten[k-step-1]),l,r,k,sl,sr,true,false,i,step+1);
        }
        else if (bor && c == sr[step]){
            dfs(cur + (i*pten[k-step-1]),l,r,k,sl,sr,false,true,i,step+1);
        }
        else{
            ans += dp[k-step-1];
        }
    }
}

int main(){
    fast;
    precalc();
    ll a,b;
    string sl,sr;
    cin>>a>>b;
    if (a == tope) a--;
    if (b == tope) b--;
    if (a==0) ans++;
    sa=to_string(a);
    sb=to_string(b);
    if (sz(sa) == sz(sb)){
        ll l = a;
        ll r = b;
        ll k = sz(sa);
        sl=sa;
        sr=sb;
        dfs(0,l,r,k,sl,sr,true,true,0);
    }
    else{
        //[a,10^k - 1]:
        ll l = a;
        ll r = pten[sz(sa)+1]-1;
        ll k = sz(sa);
        sl = to_string(l), sr = to_string(r);
        dfs(0,l,r,k,sl,sr,true,true,0);

        //Whole block of numbers with i digits.
        fore(i,sz(sa)+1,sz(sb)) ans += dp[i]; 

        //[10^k, b]:
        l = pten[sz(sb)];
        r = b;
        k = sz(sb);
        sl = to_string(l), sr = to_string(r);
        dfs(0,l,r,k,sl,sr,true,true,0);
    }
    cout<<ans<<nl;
    return 0;
}
