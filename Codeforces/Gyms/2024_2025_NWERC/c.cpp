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

const ll INF = 1e9+7;

ll ans=0;
set < pii > st;

int main(){
    fast;
    fore(i,0,5){
        ll x,y;
        cin>>x>>y;
        st.insert({x,y});
    }

    ll no_change=0;
    while(sz(st) > 1){
        vi xs;
        for(auto &[x,y] : st) xs.pb(x);

        sort(ALL(xs));

        set <pii> st2;
        no_change++;
        for(auto [x,y] : st){
            if (x == xs[0] && x != xs[1]){
                ans += abs(x - xs[1]);
                x = xs[1];
                no_change=0;
            }
            st2.insert({-y,x}); // 90 deg rotation.
        }
        if (no_change >= 4) break;
        st = st2;
    }
    ll minx = INF, miny = INF;
    ll maxx = -INF, maxy = -INF;
    for(auto &[x,y] : st){
        minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
    }

    ans += 2*(maxx-minx);
    ans += 2*(maxy-miny);

    for(auto au : st){
        ll x = au.fst;
        ll y = au.snd;
        if (minx < x && x < maxx && miny < y && y < maxy){
            ans += min(maxy-miny,maxx-minx);
        }
    }

    cout<<ans<<nl;
    return 0;
}