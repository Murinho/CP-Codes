#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+5;
const ll maxval = 1e6+2;
const ll mod = 1e9+7;
const ll loga = 31;

ll n,a[maxn],mpt[maxval],v[maxval],pots[loga],memo[maxval],fi[maxval],fd[maxval];
vi ps[maxval];

void precalc(){
    pots[0]=1;
    fore(i,1,loga) pots[i] = (pots[i-1]*2ll)%mod;
    fore(i,0,maxval) memo[i]=-1;
}

void criba(){
    fore(i,2,maxval){
        if (!v[i]){
            for(int j = 1; i*j<maxval; j++){
                ll x = i*j;
                v[x]=1;
                ps[x].pb(i);
                fd[i] += fi[i*j];
                ll cnt=0;
                while(x%i == 0){
                    x /= i;
                    cnt++;
                }
                if (cnt>1) mpt[i*j]=1;
            }
        }
        else for(int j = 1; i*j<maxval; j++) fd[i] += fi[i*j];
    }
}

ll exponentiate(ll x, ll pw){
    ll expo = x;
    ll res = 1;
    fore(i,0,loga){
        if ((pots[i]&pw) == pots[i]){
            res = (res*expo)%mod;
        }
        expo = (expo*expo)%mod;
    }
    return res;
}

ll inclusionExclusion(ll num, ll val){ //number and value of the mask.
    ll fnum=1;
    fore(i,0,sz(ps[num])){
        if ((pots[i]&val) == pots[i]) fnum *= ps[num][i];
    }
    if (mpt[fnum]) return 0;
    ll bcnt = __builtin_popcount(val);
    if (bcnt%2) return fd[fnum]; //found multiples of fnum.
    return fd[fnum]*(-1);
}

int main(){
    fast;
    precalc();
    cin>>n;
    fore(i,0,n){
        cin>>a[i];
        fi[a[i]]++;
    }
    criba();

    ll tot = exponentiate(2ll,n);

    ll q;
    cin>>q;
    while(q--){
        ll x,k=0;
        cin>>x;
        if (memo[x] != -1){
            cout<<memo[x]<<nl;
            continue;
        }
        fore(i,1,(1ll<<sz(ps[x]))){
            k += inclusionExclusion(x,i);
        }
        memo[x] = (tot*exponentiate(exponentiate(2ll,k),mod-2))%mod;
        cout<<memo[x]<<nl;
    }
    return 0;
}