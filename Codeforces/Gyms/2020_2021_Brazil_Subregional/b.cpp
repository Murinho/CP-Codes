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

const ll maxn = 11;

ll g[maxn][maxn],n;
bool ok=true;

bool valid(int x, int y){
    if (x <= 0 || x > 10 || y <= 0 || y > 10) return false;
    if (g[x][y]) return false;
    g[x][y]=1;
    return true;
}

bool checkh(int x, int y, int l){
    fore(i,0,l){
        if (!valid(x,y)) return false;
        y++;
    }
    return true;
}

bool checkv(int x, int y, int l){
    fore(i,0,l){
        if (!valid(x,y)) return false;
        x++;
    }
    return true;
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n){
        ll d,l,x,y;
        cin>>d>>l>>x>>y;
        if (d==0){
            if (!checkh(x,y,l)) ok=false;
        }
        else{
            if (!checkv(x,y,l)) ok=false;
        }
    }
    cout<<(ok ? "Y" : "N")<<nl;
    return 0;
}