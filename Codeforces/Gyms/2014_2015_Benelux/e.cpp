#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

using namespace std;

const ll maxn = 1e5+100;
const ll inf = 1e9+7;

struct STree{
    vi st;
    ll n;
    STree(int n): st(4*n + 5,inf), n(n) {}

    int query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return inf;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return min(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
    }

    void upd(int node, int ini, int fin, int pos, int val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node] = val;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node] = min(st[2*node],st[2*node+1]);
        return;
    }

    int query(int l, int r){ return query(1,1,n,l,r);}
    void upd(int pos, int val){ upd(1,1,n,pos,val);}
};

vvi a;
ll n;

void init(){
    a.clear(), a.resize(n);
}

void solve(){
    cin >> n;
    init();
    fore(i,0,n){
        fore(j,0,3){
            ll x;
            cin >> x;
            a[i].pb(x);
        }
    }
    
    sort(ALL(a));

    STree st(n);
    ll ans = 0;

    for(auto &v : a){
        ll x = v[0];
        ll y = v[1];
        ll z = v[2];
        //cout << "P: " <<  x << " " << y << " " << z << nl;
        ll ret = st.query(1,y);
        if (z < ret) ans++;

        st.upd(y,z);
    }
    //cout << nl;
    cout << ans << nl;
    return;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}