#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 52;
ll n,k,p[maxn][maxn],l,r;
vi a,b;

void init(){
    a.clear(), a.resize(n);
    b.clear(), b.resize(n);
}

void pascal(){
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    fore(i,2,maxn){
        p[i][0] = 1;
        fore(j,1,i) p[i][j] = p[i-1][j-1] + p[i-1][j];
        p[i][i] = 1;
    }
}

ll dfs(int pos, ll have, ll fa, ll last){
    if (n-pos < fa || r < have) return 0;
    if (last != -1 && have + (last*2) < l) return 0;
    ll res = 0;
    ll sm = b[n-1] - b[n-fa-1];
    ll bg = b[pos+fa-1] - (pos>0 ? b[pos-1] : 0ll);
    if (l <= have + sm && have + bg <= r){
        ll tot = n-pos;
        if (fa <= tot) res += p[tot][fa];
    }
    else if (fa>0){
        fore(i,pos,n){
            res += dfs(i+1,have+a[i],fa-1,a[i]);
        }
    }
    return res;
}

int main(){
    fast;
    cin>>n>>k;
    init();
    fore(i,0,n) cin>>a[i];
    sort(ALL(a));
    reverse(ALL(a));
    fore(i,0,n) b[i] = a[i] + (i>0 ? b[i-1] : 0ll);
    cin>>l>>r;
    pascal();
    ll ans = dfs(0,0,k,-1);
    cout<<ans<<nl;
    return 0;
}