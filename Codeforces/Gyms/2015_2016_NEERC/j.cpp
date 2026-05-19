#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define ppb pop_back
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 1e5+100;
const ll inf = 1e18;

struct STree{
    vi st;
    int n;
    STree(int n): st(4*n + 5,inf), n(n) {}

    void upd(int node, int ini, int fin, int pos, ll val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node] = val;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node+1,mid+1,fin,pos,val);
        st[node] = min(st[2*node],st[2*node + 1]);
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return inf;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return min(query(2*node,ini,mid,l,r),query(2*node+1,mid+1,fin,l,r));
    }

    void upd(int pos, ll val){ upd(1,1,n,pos,val);}
    ll query(int l, int r){ return query(1,1,n,l,r);}
};

ll n,t,d[maxn];
vector <pii> p; // tarjetas disponibles.

bool check(ll &tam){
    STree st(n);
    st.upd(1,0);
    fore(i,2,n+1){
        ll l = max(i-tam,1ll);
        ll dpmin = st.query(l,i-1);
        st.upd(i,dpmin + d[i]);
    }
    ll ft = st.query(n,n);
    return ft <= t;
}

int main(){
    fast;
    freopen("journey.in", "r", stdin);  
    freopen("journey.out", "w", stdout);
    cin >> n >> t;
    t -= n-1;
    fore(i,1,n){
        ll x;
        cin >> x;
        while(sz(p) && p.back().fst >= x) p.ppb();
        p.pb({x,i});
    }

    fore(i,2,n) cin >> d[i];
    d[1] = d[n] = 0;

    // Las tarjetas estan en orden estrictamente ascendente.
    int l = 0;
    int r = sz(p)-1;
    while(l < r){
        ll mid = (l+r)/2;
        if (check(p[mid].snd)) r = mid;
        else l = mid+1;
    }
    cout << p[l].fst << nl;
    return 0;
}