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
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 2e5+5;
const int INF = 1e9+7;
 
struct ivl{
    int l,r,id;
};
 
vector <ivl> a;
 
int n,res[maxn][2];
void init(){
    a.resize(n);
}
 
bool cmp(ivl p1, ivl p2){
    if (p1.l == p2.l) return p1.r > p2.r;
    return p1.l < p2.l;
}
 
int main(){
    fast;
    cin>>n;
    init();
    fore(i,0,n) cin>>a[i].l>>a[i].r, a[i].id=i;
 
    sort(ALL(a),cmp);
    
    ordered_multiset omst;
 
    fore(i,0,n){
        //Contains me:
        omst.insert({a[i].r,-i}); //insert the endings.
        ll ok = omst.order_of_key({a[i].r,-i});
        //cout<<i<<" ok: "<<ok<<nl;
        res[a[i].id][1] = i-ok;
    }   
    omst.clear();
    for(int i = n-1; i>=0; i--){
        //I contain:
        omst.insert({a[i].r,-i}); //insert the endings.
        ll ok = omst.order_of_key({a[i].r,-i});
        //cout<<i<<" ok: "<<ok<<nl;
        res[a[i].id][0] = ok;
    }   
 
    fore(i,0,n) cout<<res[i][0]<<" ";
    cout<<nl;
    fore(i,0,n) cout<<res[i][1]<<" ";
    cout<<nl;
    return 0;
}