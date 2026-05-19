#include <bits/stdc++.h>
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

const ll maxn = 2e3+10;
ll n,a[maxn];
vi d;

bool check(ll x){
    vi b(x);
    fore(i,0,n) b[a[i]%x]++;
    sort(ALL(b));
    return b.front() == b.back();
}

int main(){
    fast;     
    cin>>n;
    fore(i,0,n) cin>>a[i];

    fore(i,2,n+1) if (n%i == 0) d.pb(i);

    for(auto dv : d){
        if (check(dv)){
            cout<<dv<<nl;
            return 0;
        }
    }
    cout<<-1<<nl;
    return 0;
}