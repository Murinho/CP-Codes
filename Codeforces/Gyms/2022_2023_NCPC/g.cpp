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

const ll maxn = 5100;
ll n,offs,k;
ld dp[2][2*maxn],ans=0.0;

vector <ld> a;

void init(){
    a.clear(), a.resize(n+1);
    a[0]=1.0000;
    offs = n;
}

int main(){
    fast;
    cin>>n>>k;
    init();
    fore(i,1,n+1) cin>>a[i];

    sort(ALL(a));
    reverse(ALL(a));

    //compute dp:
    dp[0][offs] = 1.0;
    fore(i,1,n+1){
        ld sum=0.0;
        for(ll j = -i; j<=i; j++){
            dp[i%2][j+offs] = (dp[(i+1)%2][j+offs-1]*a[i]) + (dp[(i+1)%2][j+offs+1]*(1.0-a[i]));
            if (j >= k) sum += dp[i%2][j+offs];
        }
        ans = max(ans,sum);
    }       
    cout<<fixed<<setprecision(12)<<ans<<nl;
    return 0;
}