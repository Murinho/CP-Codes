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

const ll maxn = 42;
const ll hmaxn = 21;
const ll maxbit = (1<<20);

int n,k;
ll a[maxn],p[hmaxn];

void precalc(){
    p[0]=1;
    fore(i,1,hmaxn) p[i]=(p[i-1]*2ll);
}

int main(){
    fast;
    cin>>n>>k;
    precalc();
    fore(i,0,n) cin>>a[i];
    
    auto get_subset_sums = [&](int l, int r) -> vi {
        ll len = r-l+1;
        vi res;

        fore(i,0,p[len]){
            ll sum = 0;
            fore(j,0,len) if ((i&p[j])) sum += a[l+j];
            res.pb(sum);
        }
        return res;
    };

    vi izq= get_subset_sums(0,n/2 - 1);
    vi der= get_subset_sums(n/2,n-1);

    sort(ALL(izq)), sort(ALL(der));

    ll ans = 0;
    for(ll elm : izq){
        auto lwb = lower_bound(ALL(der),k-elm);
        auto upb = upper_bound(ALL(der),k-elm);
        ans += upb-lwb;
    }
    cout<<ans<<nl;
    return 0;
}