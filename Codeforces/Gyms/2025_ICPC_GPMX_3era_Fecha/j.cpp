#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e6+100;
const ll inf = 1e9+7;

ll a[maxn];

struct STree{
    vector <pii> st; ll n;
    STree(int n): st(4*n + 5), n(n) {}

    void build(int node, int ini, int fin){
        if (ini == fin){
            st[node].fst = a[ini];

            if (st[node].fst == 0) st[node].snd = 0;
            else if (st[node].fst == 1) st[node].snd = 1;
            else st[node].snd = inf;

            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node].fst = (st[2*node].fst ^ st[2*node + 1].fst);
        st[node].snd = (st[2*node].snd + st[2*node + 1].snd);
    }

    void upd(int node, int ini, int fin, int &pos, ll &val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node].fst += val;

            if (st[node].fst == 0) st[node].snd = 0;
            else if (st[node].fst == 1) st[node].snd = 1;
            else st[node].snd = inf;

            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node].fst = (st[2*node].fst ^ st[2*node + 1].fst);
        st[node].snd = (st[2*node].snd + st[2*node + 1].snd);
    }

    pii query(int node, int ini, int fin, int &l, int &r){
        if (fin < l || r < ini) return {0,0};
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        pii lft = query(2*node,ini,mid,l,r);
        pii rgt = query(2*node + 1,mid+1,fin,l,r);
        lft.fst ^= rgt.fst;
        lft.snd += rgt.snd;
        return lft;
    }

    void build(){ build(1,1,n);}
    void upd(int pos, ll val){ upd(1,1,n,pos,val); }
    pii query(int l, int r){ return query(1,1,n,l,r); }
};

void solve(){
    ll n,q;
    cin >> n >> q;
    fore(i,1,n+1) cin >> a[i];

    STree st(n);
    st.build();

    while(q--){
        char c;
        ll x,y;
        cin >> c >> x >> y;
        if (c == 'P'){
            pii ret = st.query(x,y);
            //cout << ret.fst << " " << ret.snd << nl;
            if (ret.snd <= (y-x+1)){
                if (ret.snd%2 == 1) cout << "FRANK" << nl;
                else cout << "JUAN" << nl;
            }
            else{
                if (ret.fst > 0) cout << "FRANK" << nl;
                else cout << "JUAN" << nl;
            }
        }
        else st.upd(x,y);
    }
}

int main(){
    fast;
    ll tc=1;
    while(tc--){ solve(); }
    return 0;
}