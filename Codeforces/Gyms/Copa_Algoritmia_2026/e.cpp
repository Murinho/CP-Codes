#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>
#define nl '\n'
#define fore(i,a,b) for(int i=a; i<b; i++)
#define ld long double
#define ppb pop_back
#define eb emplace_back

using namespace std;

const ll maxn = 2e5+10;
const ll inf = 1e9+7;
ll a[maxn],mn[maxn],mx[maxn];
vi g[maxn];

struct Node{
    vi v;
    void order(){
        sort(ALL(v));
    }
    int get(int &val_l, int &val_r){
        if (v.size() == 0 || v.back() < val_l) return 0;

        int lwb = lower_bound(ALL(v),val_l) - v.begin();
        int upb = upper_bound(ALL(v),val_r) - v.begin();
        return upb-lwb;
    }
};

struct MSTree{
    vector <Node> st; int n;
    MSTree(int n): st(4*n + 5), n(n) {}

    void upd(int node, int ini, int fin, int pos, int val){
        st[node].v.eb(val);
        if (ini >= fin) return;
        int mid = (ini+fin)/2;
        if (pos<=mid) upd(2*node, ini,mid,pos,val);
        else upd(2*node + 1,mid+1,fin,pos,val);
    }
    int query(int node, int ini, int fin, int l, int r, int val_l, int val_r){
        if (fin < l || r < ini) return 0;
        if (l <= ini && fin <= r) return st[node].get(val_l,val_r);
        int mid = (ini+fin)/2;
        return query(2*node,ini,mid,l,r,val_l,val_r) + query(2*node + 1,mid+1,fin,l,r,val_l,val_r);
    }

    void order(){ fore(i,1,4*n + 5) st[i].order();}

    void upd(int pos, int val){ upd(1,0,n,pos,val);}
    int query(int l, int r, int val_l, int val_r){
        return query(1,0,n,l,r,val_l,val_r);
    }
};

void init(){
    fore(i,0,maxn){
        mn[i] = inf;
        mx[i] = -inf;
    }
}

void dfs(int u){
    mn[u] = mx[u] = a[u];
    for(auto &v : g[u]){
        if (v != 0){
            dfs(v);
            mn[u] = min(mn[u],mn[v]);
            mx[u] = max(mx[u],mx[v]);
        }
    }
}

int main(){
    fast;
    ll n;
    cin >> n;
    init();
    vi uni;
    fore(i,1,n+1){
        ll l,r;
        cin >> l >> r >> a[i];
        g[i].pb(l);
        g[i].pb(r);
        uni.pb(a[i]);
    }

    sort(ALL(uni));
    uni.erase(unique(ALL(uni)),uni.end());

    // now map the values
    fore(i,1,n+1){
        a[i] = lower_bound(ALL(uni),a[i]) - uni.begin();
    }

    // now figure out the ranges:
    dfs(1);

    // now build the merge sort tree:
    MSTree mst(sz(uni));

    fore(i,1,n+1){
        mst.upd(mx[i],mn[i]);

        // cout << i << " " << mn[i] << " " << mx[i] << nl;
    }

    mst.order();

    ll q;
    cin >> q;
    fore(v,0,q){
        ll l,r;
        cin >> l >> r;
        l = lower_bound(ALL(uni),l) - uni.begin();
        r = upper_bound(ALL(uni),r) - uni.begin() - 1;

        // cout << v << ": " << l << " " << r << nl;
        
        int ans = 0;
        // get amount of values in [ql,qr] that < ql
        if (l-1 >= 0 && l <= r){
            ans += mst.query(l,r,0,l-1);
        }

        // return 0;

        // // get amount of values in [qr+1,n] that <= qr
        if (r+1 < sz(uni)){
            ans += mst.query(r+1,sz(uni)-1,0,r);
        }
        cout << ans*2 + 1 << nl;
    }
    return 0;
}