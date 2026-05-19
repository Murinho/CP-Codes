#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 4e5+15;
const ll loga = 19;

ll up[maxn][loga],a[maxn];
ll n,k,sum,pos;

void binaryLift(){
    fore(i,0,loga) up[2*n][i]=2*n;
    fore(i,1,loga){
        fore(j,0,2*n) up[j][i] = up[up[j][i-1]][i-1];
    }
}

int main(){
    fast;
    cin>>n>>k;
    fore(i,0,n) cin>>a[i], a[i+n]=a[i];

    //compute direct parents
    pos = 0;
    sum = 0;
    fore(i,0,2*n){
        if (i>0) sum -= a[i-1];
        while(pos < 2*n && sum + a[pos] <= k){
            sum += a[pos];
            pos++;
        }
        up[i][0] = pos;
        //cout<<i<<": "<<pos<<" sum: "<<sum<<nl;
    }

    binaryLift();

    ll ans=n;

    fore(i,0,n){ //get the smallest amount of jumps.
        ll res=0;
        ll cur=i;
        rofe(j,loga,0){
            if (up[cur][j] < i+n){
                res += (1ll<<j);
                cur = up[cur][j];
            }
        }
        ans = min(ans,res+1);
    }
    cout<<ans<<nl;
    return 0;
}

