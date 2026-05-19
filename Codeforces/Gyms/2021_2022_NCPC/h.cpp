#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i <b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; --i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const ll maxn = 2e5+5;

struct Coder{
    ll l,f,id;
};


vector<Coder> a;
Coder b[maxn];

struct STree{ //Will contain the f's
    vi st; int n;
    STree(int n): st(4*n + 5), n(n) {}

    void build(int node, int ini, int fin){
        if (ini == fin){
            st[node]=a[ini].f;
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

    void upd(int node, int ini, int fin, int pos, ll val){ //assign update.
        if (fin < pos || pos < ini) return;
        if (ini == fin){ 
            st[node]=val;
            cout<<"llegue "<<nl;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return 0;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return max(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
    }

    void build(){ build(1,0,n-1);}
    void upd(int pos, ll val){ upd(1,0,n-1,pos,val);}
    ll query(int l, int r){ return query(1,0,n-1,l,r);}
};  

ll n,orid[maxn];

void init(){
    a.clear(), a.resize(n);
}

bool cmp(Coder c1, Coder c2){
    if (c1.l == c2.l) return c1.f < c2.f;
    return c1.l < c2.l;
}

int main(){
    fast;
    ordered_multiset omst; //have the l's
    cin>>n;
    init();
    fore(i,0,n){
        cin>>a[i].l>>a[i].f;
        a[i].id = i+1;
        b[i+1]=a[i];
    }

    sort(ALL(a),cmp);

    //Fill up the original index.
    fore(i,0,n){
        orid[a[i].id]=i;
        cout<<a[i].l<<" , "<<a[i].f<<nl;
    }

    //Fill up the OMST:
    fore(i,0,n){
        omst.insert({a[i].l,i});
    }

    //Build the segment tree.
    STree st(n);
    st.build();

    ll q;
    cin>>q;
    while(q--){
        char t;
        cin>>t;
        if (t == 'c'){
            ll tp,x,y;
            cin>>tp>>x>>y;
            ll l = 0;
            ll r = sz(omst)-1;
            while(l < r){
                ll mid = (l+r)/2;
                pii p = *omst.find_by_order(mid);
                if (x <= p.fst*tp) r = mid;
                else l = mid+1;
            }
            pii p = *omst.find_by_order(l);
            ll val = p.fst;
            cout<<"herex: "<<val*tp<<nl;
            if (val*tp < x) cout<<"yes"<<nl;
            else{
                ll lwb = p.snd; //get the index in the segment tree.
                ll res = st.query(lwb,n-1);
                cout<<"Search ivl: "<<lwb<<" "<<n-1<<nl;
                cout<<"herey: "<<res*tp<<nl;
                if (res*tp < y) cout<<"yes"<<nl;
                else cout<<"no"<<nl;
            }
        }
        else{
            ll idx,stidx;
            cin>>idx;
            Coder coder = b[idx];
            stidx = orid[idx]; //segment tree index.
            //cout<<"erasing: "<<coder.l<<" "<<stidx<<nl;
            omst.erase({coder.l,stidx});
            //cout<<"Size of omst: "<<sz(omst)<<nl;
            st.upd(stidx,0);
        }
    }
    return 0;
}