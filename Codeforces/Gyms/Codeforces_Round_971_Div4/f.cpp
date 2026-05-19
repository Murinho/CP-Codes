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
#define RB(x) (x<n?r[x]:0)
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 2e5+10;

ll n,tot,q;
vi a,b;

void init(){
    tot=0;
    a.clear(), a.resize(n);
    b.clear(), b.resize(n);
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        cin>>n>>q;
        init();
        fore(i,0,n){
            cin>>a[i];
            b[i] = a[i] + (i>0 ? b[i-1] : 0);
        }
        tot = b[n-1];
        while(q--){
            ll l,r,ans=0;
            cin>>l>>r;
            l--;
            r--;
            
            ll shl = l/n;
            ll shr = r/n;

            ll nel = shl+1;
            ll ner = shr-1;
            if (nel <= ner) ans += ((ner-nel+1)*tot);

            if (shl == shr && r-l+1 < n){ //if the segment is little.
                l %= n;
                r %= n;
                l = (l+shl)%n;
                r = (r+shr)%n;
                if (l <= r){
                    ans += (b[r] - (l>0 ? b[l-1] : 0));
                }
                else ans += b[r], ans += b[n-1]-b[l-1];
            }
            else if ((r-l+1) == n && (l%n) == 0 && (r%n) == n-1) ans += tot; 
            else{
                ll pref = n - (l%n);
                if (pref == n) pref = 0, ans += tot;
                else{
                    ll ml = n-pref;
                    ll mr = n-1;
                    ml = (ml+shl)%n;
                    mr = (mr+shl)%n;
                    if (ml <= mr){
                        ans += (b[mr] - (ml>0 ? b[ml-1] : 0));
                    }
                    else ans += b[mr], ans += b[n-1]-b[ml-1];
                }
                

                ll suf = (r%n) + 1;
                if (suf == n) suf = 0, ans += tot;
                else{
                    ll ml = 0;
                    ll mr = suf-1;
                    ml = (ml+shr)%n;
                    mr = (mr+shr)%n;
                    if (ml <= mr){
                        ans += (b[mr] - (ml>0 ? b[ml-1] : 0));
                    }
                    else ans += b[mr], ans += b[n-1]-b[ml-1];
                }
            }
            cout<<ans<<nl;
        }
    }
    return 0;
}