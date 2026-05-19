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

ll n;
vector < pii > a;
set <ll> c0,c1;

void init(){
    a.clear(), a.resize(n);
    c0.clear(), c1.clear();
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        cin>>n;
        init();
        fore(i,0,n){
            cin>>a[i].fst>>a[i].snd;
            if (a[i].snd == 0){
                c0.insert(a[i].fst);
            }
            else c1.insert(a[i].fst);
        }

        sort(ALL(a));

        ll ans=0; // vertical side.
        fore(i,0,n){
            if (i+1<n && a[i].fst == a[i+1].fst){
                ans += i;
                ans += (n-i-2);
            }
            if (a[i].snd == 0){
                if (c1.count(a[i].fst-1) && c1.count(a[i].fst+1)) ans++;
            }
            else{
                if (c0.count(a[i].fst-1) && c0.count(a[i].fst+1)) ans++;
            }
        }
        cout<<ans<<nl;
    }   
    return 0;
}