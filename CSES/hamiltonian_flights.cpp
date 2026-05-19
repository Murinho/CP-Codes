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
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
    
using namespace std;

const ll maxn = 20;
const ll maxbit = (1<<maxn);
const ll mod = 1e9+7;

ll n,m,dp[maxbit][maxn];
vi adj[maxn];

int main() {
	fast;
	cin>>n>>m;
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        x--, y--;
        adj[x].pb(y);
    }
    dp[1][0]=1;
    //Make DP bits:
    fore(i,1,(1<<n)-1){ //iterate through all bit masks.
        fore(j,0,n){ 
            if (dp[i][j]){ //if visited.
                for(auto sbit : adj[j]){
                    if ((i&(1<<sbit)) == 0){ //bit is off.
                        dp[i+(1<<sbit)][sbit] = (dp[i+(1<<sbit)][sbit] + dp[i][j])%mod;
                        //cout<<"Trans: "<<(i + (1<<sbit))<<", "<<sbit<<": "<<dp[i+(1<<sbit)][sbit]<<nl;
                    }
                }
            }
        }
    }
    
    cout<<dp[(1<<n)-1][n-1]<<nl;
    return 0;
}