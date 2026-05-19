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

const int maxn = 3e4+5;

struct STree{
    vector <int> st; int n;
    STree(int n): st(4*n + 5), n(n) {}

    void build(int node, int ini, int fin){
        if (ini == fin){
            st[node]=-ini;
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

    void upd(int node, int ini, int fin, int pos, int val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node] += val;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

    ll query(int node, int ini, int fin){
        if (ini == fin) return ini;
        int mid = (ini+fin)/2;
        if (st[2*node + 1] >= 0) return query(2*node+1,mid+1,fin);
        return query(2*node,ini,mid);
    }

    void build(){ build(1,1,n);}
    void upd(int pos, int val){ upd(1,1,n,pos,val);}
    ll query(){ return query(1,1,n);}
};

struct qu{int l,r,id;};
qu qs[maxn];
ll ans[maxn],sq,nq,n,a[maxn];
unordered_map <int,int> f;

bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

void add(STree &st, int i){
    f[a[i]]++;
    st.upd(f[a[i]],+1);
}

void remove(STree &st, int i){
    st.upd(f[a[i]],-1);
    f[a[i]]--;
}

ll get_ans(STree &st){
    return st.query();
}

void mos(){
    fore(i,0,nq) qs[i].id=i;
    sq = sqrt(n)+1;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    STree st(n);
    st.build();
    fore(i,0,nq){ // queries[l,r)
        qu q=qs[i];
        while(l>q.l)add(st,--l);
        while(r<q.r)add(st,r++);
        while(l<q.l)remove(st,l++);
        while(r>q.r)remove(st,--r);
        ans[q.id]=get_ans(st);
    }
}

int main(){
    fast;     
    cin>>n>>nq;
    fore(i,0,n) cin>>a[i];
    fore(i,0,nq) cin>>qs[i].l>>qs[i].r, qs[i].l--;
    mos();
    fore(i,0,nq) cout<<ans[i]<<nl;
    return 0;
}