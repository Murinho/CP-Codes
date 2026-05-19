#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second


using namespace std;

const ll maxn = 1e5+10;
const ll INF = 1e18;

ll a[maxn],b[maxn];

struct STMax{
    vi st; int n;
    STMax(int n): st(4*n + 5), n(n) {}

    void build(int node, int ini, int fin){
        if (ini == fin){
            st[node] = b[ini];
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

    void upd(int node, int ini, int fin, int pos, ll val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node] = val;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (r < ini || fin < l) return 0;
        if (l <= ini && fin <= r){
            return st[node];
        }
        int mid = (ini+fin)/2;
        return max(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
    }

    void build(){ build(1,1,n);}
    void upd(int pos, ll val){ upd(1,1,n,pos,val);}
    ll query(int l, int r){ return query(1,1,n,l,r);}
};

ll n,q;

ll leftBS(int pos, ll val, STMax &stmax){
    if (pos == 1 || b[pos] > val) return 0;
    int l = 2;
    int r = pos;
    while(l < r){
        ll mid = (l+r)/2;
        ll minic = stmax.query(mid,pos);
        if (minic <= val) r = mid;
        else l = mid+1;
    }
    return pos-l+1;
}

ll rightBS(int pos, ll val, STMax &stmin){
    if (pos == n) return 1;
    if (b[pos+1] > val) return 1;
    int l = pos+1;
    int r = n;
    while(l < r){
        int mid = (l+r+1)/2;
        ll minic = stmin.query(pos+1,mid);
        if (minic <= val) l = mid;
        else r = mid-1;
    }
    return (r-pos+1);
}

int main(){
    fast;
    cin>>n>>q;
    fore(i,1,n+1) cin>>a[i];
    fore(i,2,n+1) b[i] = abs(a[i]-a[i-1]); //b[i] contains the difference between a[i]-a[i-1].

    STMax stmin(n);

    stmin.build();
    while(q--){
        ll t,pos,val;
        cin>>t>>pos>>val;
        if (t == 1){ //update:
            a[pos] = val;
            if (pos>1) b[pos] = abs(a[pos]-a[pos-1]), stmin.upd(pos,b[pos]);//update to the left.
            if (pos<n) b[pos+1] = abs(a[pos+1]-a[pos]), stmin.upd(pos+1,b[pos+1]); //update to the right
        }   
        else{
            //cout<<lft<<" + "<<rgt<<nl;
            ll res = leftBS(pos,val,stmin) +  rightBS(pos,val,stmin);
            cout<<res<<nl;
        }
    }
    return 0;
}