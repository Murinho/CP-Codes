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

const ll maxn = 200;

ll n,a[maxn][2],ans=0;
char c;
bool won=false;
bool ok=true;

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1){
        cin>>a[i][0];
        cin>>c;
        cin>>a[i][1];
        int x = a[i][0] + a[i][1];
        if (x%4 == 1 || x%4 == 2) swap(a[i][0],a[i][1]);
    }

    //check:
    fore(i,1,n+1){
        if (a[i][0] == a[i-1][0] && a[i][1] == a[i-1][1]) continue; //same score.
        else if (a[i][0] < a[i-1][0] || a[i][1] < a[i-1][1]){ //score is less.
            ok=false;
            ans=i;
            break;
        }
        else if (min(a[i][0],a[i][1]) == 11 || won){ //11-11 or someone already had won.
            ok=false;
            ans=i;
            break;
        }
        else if (max(a[i][0],a[i][1]) == 11) won=true;
    }
    if (ok) cout<<"ok"<<nl;
    else cout<<"error "<<ans<<nl;
    return 0;
}