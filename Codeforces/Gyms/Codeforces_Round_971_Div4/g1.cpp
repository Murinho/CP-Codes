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

struct qu{int l,r,id;};

ll n,nq,sq,res,ans[maxn],a[maxn],k;

bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
qu qs[maxn];
unordered_map <ll,ll> mp; // frequencies.
multiset <ll> mst; // keep max freq.

void add(int i){
    i = a[i]-i;
    if (mp[i]) mst.erase(mst.find(mp[i]));
    mp[i]++;
    mst.insert(mp[i]);
}

void remove(int i){
    i = a[i]-i;
    mst.erase(mst.find(mp[i]));
    mp[i]--;
    if (mp[i]) mst.insert(mp[i]);
}

ll get_ans(){ return *mst.rbegin();}

void mos(){
    //fore(i,0,nq) qs[i].id=i;
    sq = sqrt(n)+0.5;
    sort(qs,qs+nq,qcomp); //sort the queries.
    int l=0,r=0;
    res=0;
    fore(i,0,nq){ // Must have queries like: [l,r)
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]= (q.r - q.l) - get_ans();
    }
}

void init(){
    mp.clear(), mst.clear();
}

void solve(){
    cin>>n>>k>>nq;
    init();
    fore(i,0,n) cin>>a[i];

    fore(i,0,nq){
        cin>>qs[i].l>>qs[i].r;
        qs[i].l--;
        qs[i].id=i;
    }

    mos();

    fore(i,0,nq) cout<<ans[i]<<nl;

    return;
}   

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}