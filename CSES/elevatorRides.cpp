#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a)((int)a.size())
#define lsb(x)((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 21;
const ll maxmask = 1048580;
const ll INF = 1e9+7;

ll n,k,a[maxn],dp[maxmask][maxn],tope,ans=INF,cur[maxmask],pw[maxmask];
vi bins[maxn];
bool ok=false;

void init(){
    tope = (1ll<<n);
    ans = n;
    fore(i,0,tope) fore(j,0,maxn) dp[i][j]=INF;
    fore(i,0,maxn){
        pw[(1ll<<i)]=i;
    }
}

void precalc(){
    fore(mk,0,tope){
        ll cnt = __builtin_popcountll(mk);
        bins[cnt].pb(mk);
    }
}

int main(){
    fast;
    cin>>n>>k;
    init();
    precalc();
    fore(i,0,n){
        cin>>a[i];
        dp[(1ll<<i)][1]=a[i];
        cur[(1ll<<i)]=1;
    }
   
    fore(i,1,n+1){
        //cout<<"ROUND: "<<i<<nl;
        fore(j,0,n){
            for(auto mk : bins[j]){
                if (cur[mk]){
                    ll cnt=0;
                    ll imk = tope-mk-1; //inverse mask.
                    //cout<<"Visiting mk: "<<mk<<" with: "<<dp[mk][i]<<nl;
                    while(imk){
                        ll msb = lsb(imk); //bit menos significativo.
                        ll pos = lsbpos(imk)-1;
                        //cout<<"imk: "<<imk<<nl;
                        if (dp[mk][i] + a[pos] <= min(k,dp[mk+msb][i])){
                            dp[mk+msb][i] = dp[mk][i] + a[pos];
                            cur[mk+msb]=1;
                            dp[mk+msb][i+1]=0;
                            cnt++;
                            if (mk+msb == tope-1) ok=true;
                        }
                        imk -= msb;
                    }
                    if(cnt>0) cur[mk]=0;
                }
            }
        }
        //cout<<"--------------"<<nl;
        if (ok){
            ans=i;
            break;
        }
    }
    cout<<ans<<nl;
    return 0;
}