#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e6+5;
const ll B = 131;
const ll M = 1e9+7;

ll p[maxn];
string s;

struct STree{
    vi st; int n;
    STree(int n): st(4*n + 5), n(n) {}

    void upd(int node, int ini, int fin, int pos, ll val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node]=val;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node] = (st[2*node] + st[2*node + 1])%M;
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return 0;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return (query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r))%M;
    }

    void upd(int pos, ll val){ upd(1,0,n-1,pos,val);}
    ll query(int l, int r){ return query(1,0,n-1,l,r);}
};

ll conv(char c){
    return (c-'a'+1);
}
 
int main(){ //maybe having hashing an point updates like a STree may work.
    fast;
    int n,q;
    string s;
    cin>>n>>q;
    cin>>s;
    //precalculate powers:
    p[0]=1;
    fore(i,1,n+1) p[i] = (B * p[i-1])%M;
    //Define segment trees for storing the hashes:
    STree forward(n);
    STree backward(n);

    fore(i,0,n){
        forward.upd(i,(conv(s[i])*p[i])%M);
        backward.upd(i,(conv(s[i])*p[n-i-1])%M);
    }

    while(q--){
        ll t;
        cin>>t;
        if (t == 1){
            ll pos;
            char c;
            cin>>pos>>c;
            pos--;
            forward.upd(pos,(conv(c)*p[pos])%M);
            backward.upd(pos,(conv(c)*p[n-pos-1])%M);
        }
        else{
            ll l,r;
            cin>>l>>r;
            l--, r--;
            ll h1 = forward.query(l,r);
            h1 = (h1*p[n-1-r])%M;
            ll h2 = backward.query(l,r);
            h2 = (h2*p[l])%M;
            if (h1 == h2) cout<<"YES"<<nl;
            else cout<<"NO"<<nl;
        }
    }
    return 0;
}
