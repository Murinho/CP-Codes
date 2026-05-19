#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1005;

ll a[maxn][maxn];
vector < pii > p;

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    if (n == 1){
        cout<<"NO"<<nl;
        return 0;
    }
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        a[x][y] = a[y][x] = 1;
    }

    ll mid = (n/2);
    fore(i,1,mid+1){
        fore(j,i+1,mid+1) if (!a[i][j]) p.pb({i,j});
    }
    fore(i,mid+1,n+1){
        fore(j,i+1,n+1) if (!a[i][j]) p.pb({i,j});
    }
    cout<<"YES"<<nl;
    cout<<sz(p)<<nl;
    for(auto au : p){
        cout<<au.fst<<" "<<au.snd<<nl;
    }
    return 0;
}