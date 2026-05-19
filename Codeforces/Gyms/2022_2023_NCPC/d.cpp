#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector <Vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll INF = 1e18;

ll ed(ll x, ll y){
    return (x*x) + (y*y);
}

int main(){
    fast;
    ll r,x,y,med,bx,by,bed=INF,d;
    cin>>r;
    med = ed(r,0);
    x = r;
    y = 0;
    while(x >= 0){
        d = ed(x,y);
        if (d <= med){
            y++;
        }
        else{
            if (d < bed){
                bed = d;
                bx=x, by=y;
            }
            x--;
        }
    }
    cout<<bx<<" "<<by<<nl;
    return 0;
}