#include <bits/stdc++.h>
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
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 2e5+10;
const ll INF = 1e10;
ll a[maxn],b[maxn];

struct STree{
    vi st; int n,op;
    STree(int n, int op): st(4*n + 5), n(n), op(op) {}

    void build(int node, int ini, int fin){
        if (ini == fin){
            if (op==1) st[node]=b[ini];
            else st[node]=a[ini];
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid), build(2*node + 1,mid+1,fin);
        if (op == 1) st[node] = min(st[2*node],st[2*node + 1]);
        else st[node] = max(st[2*node],st[2*node + 1]);
    }

    void upd(int node, int ini, int fin, int pos, ll val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node]=val;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val), upd(2*node + 1,mid+1,fin,pos,val);
        if (op == 1) st[node] = min(st[2*node],st[2*node + 1]);
        else st[node] = max(st[2*node],st[2*node + 1]);
    }
    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini){
            if (op == 1) return INF; //for minimums.
            return -INF;
        }
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        if (op == 1) return min(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
        return max(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
    }

    void build(){ build(1,1,n);}
    void upd(int pos, ll val){ upd(1,1,n,pos,val);}
    ll query(int l, int r){ return query(1,1,n,l,r);}
};
ll n,q;

int main(){
    fast;   
    cin>>n>>q;
    fore(i,1,n+1) cin>>a[i]>>b[i];

    STree stmax(n,2);
    stmax.build();
    STree stmin(n,1);
    stmin.build();
    //cout<<"stmin: "<<stmin.query(1,3)<<nl;
    //cout<<"stmax: "<<stmax.query(1,3)<<nl;
    char c;
    while(q--){
        cin>>c;
        if (c == 'C'){
            ll l,r,pos;
            cin>>pos>>l>>r;
            //cout<<"update: "<<pos<<" --> "<<l<<" "<<r<<nl;
            stmax.upd(pos,l);
            stmin.upd(pos,r);
        }
        else{
            ll l,r;
            cin>>l>>r;
            ll mn = stmin.query(l,r);
            ll mx = stmax.query(l,r);
            //cout<<"query: "<<l<<" "<<r<<" --> "<<mx<<", "<<mn<<nl;
            cout<<max(mn-mx+1,0ll)<<nl; 
        }
    }
    return 0;
}