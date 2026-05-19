#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define ppb pop_back

using namespace std;

const ll inf = 1e18;
const ll maxn = 705;
ll n,dp[maxn][maxn];
string a;

vi get_divs(ll k){
    ll sq = sqrt(k);
    vi ret;
    fore(i,1,sq+1){ 
        if (k%i == 0){
            ret.pb(i);
            if (i != k/i) ret.pb(k/i);
        }
    }
    sort(ALL(ret));
    //cout<<"Divs "<<k<<": ";
    //for(auto &au : )
    return ret;
}

int main(){
    fast;
    cin>>n;
    cin>>a;
    fore(i,0,n){
        fore(j,0,n) dp[i][j] = inf;
    }
    fore(i,0,n) dp[i][i] = 1;

    fore(i,1,n){ // longitudes de substring.
        //cout<<"LEN: "<<i+1<<nl;
        vi d = get_divs(i+1); // get the divisors of this length.
        int l = 0;
        int r = i;
        while(r < n){
            // check all possible splits:
            for(int j = l; j<r; j++){
                dp[l][r] = min(dp[l][r], dp[l][j] + dp[j+1][r]);
            }
            // make some length consecutive sequences:
            for(auto &len : d){
                bool ok=true;

                for(int j = l; j<l+len && ok; j++){
                    for(int k = j; k<=r && ok; k += len){
                        if (a[j] != a[k]) ok=false;
                        //if (l == 0 && r == 7 && len == 4) cout<<"Compare: "<<j<<" "<<k<<nl;
                    }
                }
                if (ok){
                    dp[l][r] = min(dp[l][r], dp[l][l+len-1]);
                }
            }
            //cout<<"dp: "<<l<<" "<<r<<" "<<dp[l][r]<<nl;
            l++, r++;
        }
    }
    cout<<dp[0][n-1]<<nl;
    return 0;
}