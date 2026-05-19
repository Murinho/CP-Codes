#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) a.size()
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+100;
const ll maxk = 103;
const ll INF = 1e10;
ll n,k,sum=0,dp[maxn][maxk][2],ans=0;
vi a,b;

void init(){
    fore(i,0,maxn) fore(j,0,maxk){
        dp[i][j][0]=0; // can start wherever I want.
        dp[i][j][1]=-INF; 
    }
}

int main(){
    fast;
    cin>>n>>k;
    fore(i,0,n){
        ll x;
        cin>>x;
        if (x != 0) a.pb(x);
    }

    if (!sz(a)){
        cout<<0<<nl;
        return 0;
    }

    sum = a[0];
    b.pb(0); //push this as a little offset.
    fore(i,1,sz(a)){
        if ((a[i-1]<0 && a[i]>0) || (a[i-1]>0 && a[i]<0)){
            b.pb(sum);
            sum=0;
        }
        sum += a[i];
    }
    b.pb(sum);

    //cout<<"B"<<nl;
    //for(auto au : b) cout<<au<<" ";
    //cout<<nl;

    init(); // init DP.
    fore(i,1,sz(b)){
        fore(j,0,k+1){ //exclusive.
            // With dp(i,j,0):

            // stay same.
            dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][0] + b[i]);
            ans = max(ans,dp[i][j][0]);
            // flip:
            if (j<k){
                dp[i][j+1][1] = max(dp[i][j+1][1],dp[i-1][j][0] + (b[i]*(-1)));
                ans = max(ans,dp[i][j+1][1]);
            }

            // With do(i,j,1):

            // stay same.
            dp[i][j][1] = max(dp[i][j][1],dp[i-1][j][1] + (b[i]*(-1)));
            ans = max(ans,dp[i][j][1]);

            // regresar a normal.
            dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][1] + b[i]);
            ans = max(ans,dp[i][j][0]);

        }
    }
    cout<<ans<<nl;
    return 0;
}