#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first 
#define snd second

using namespace std;

const ll maxn = 2e5+10;
const ll mod = 1e9+7;
ll pow_f[maxn],pow_i[maxn];

ll exponentiate(ll x, ll e) {
	if (e == 0) return 1;
	ll s = exponentiate(x, e / 2);
	(s *= s) %= mod;
	if (e % 2) (s *= x) %= mod;
	return s;
}

ll inv(ll x){ return exponentiate(x,mod-2);}

struct STree{
    vi st; int n;
    STree(int n): st(4*n + 5), n(n) {}

    void upd(int node, int ini, int fin, int pos, ll val){
        if (fin < pos || pos < ini) return;
        if (ini == fin){
            st[node] = (st[node]+val)%mod;
            return;
        }
        int mid = (ini+fin)/2;
        upd(2*node,ini,mid,pos,val);
        upd(2*node + 1,mid+1,fin,pos,val);
        st[node] = (st[2*node] + st[2*node + 1])%mod;
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return 0;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return (query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r))%mod;
    }

    void upd(int pos, ll val){ upd(1,0,n-1,pos,val);}
    ll query(int l, int r){ return query(1,0,n-1,l,r);}
};

int main(){
    fast;
    ll n,q;
    string s;
    cin>>n>>q>>s;
    
    ll denom = exponentiate(10,sz(s)-2);
    ll nume = denom - stoull(s.substr(2));
    ll mulf = (nume * inv(denom))%mod; //multiplication factor.
    ll mulf_inv = inv(mulf);

    //Segment trees for adding left and right.
    STree l(n), r(n);

    //precalculate the inverse powers:
    pow_f[0] = 1; //normal power (p^k)
    pow_i[0] = 1; //inverse power (p^-k)

    fore(i,1,n){
        pow_f[i] = (pow_f[i-1]*mulf)%mod; //this decreases light
        pow_i[i] = (pow_i[i-1]*mulf_inv)%mod; //this increases light
    }

    while(q--){
        char t;
        cin>>t;
        if (t == '?'){ //query.
            ll x; cin>>x, x--;
            ll y = n-1-x;
            ll res = (l.query(0,x)*pow_f[x])%mod;
            res += (r.query(0,y)*pow_f[y])%mod;
            cout<<res%mod<<nl;
        }
        else{
            ll b,x; cin>>b>>x, x--;
            if (t == '-') b = mod-b;
            l.upd(x,(b*pow_i[x])%mod);
            ll y = n-1-x;
            if (y+1<n) r.upd(y+1,(b*pow_i[y])%mod);
        }
    }
}