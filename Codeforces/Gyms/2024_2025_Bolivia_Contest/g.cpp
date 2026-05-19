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
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll mod = 1e18;
const ll maxn = 1e5+50;
const ll maxval = 1e5+50;
const ll neut = 0;
const ll lzneut = -1;

ll spf[maxval],mxpf[maxval],v[maxval],a[maxn];

struct STree{
    vi st,lzset; int n; bool nums;
    STree(int n, bool nums): st(4*n + 5,neut), lzset(4*n + 5,lzneut), n(n), nums(nums) {}

    void build(int node, int ini, int fin){
        if (ini == fin){
            if (nums) st[node] = a[ini]; //number itself.
            else st[node] = spf[a[ini]]; //sum of prime factors.
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node] = (st[2*node] + st[2*node + 1])%mod;
    }

    void assign(int node, int ini, int fin, ll val){
        lzset[node]=val;
        st[node] = ((fin-ini+1)*val)%mod;
    }

    void push(int node, int ini, int fin){
        int mid = (ini+fin)/2;
        if (lzset[node] != -1){
            assign(2*node,ini,mid,lzset[node]);
            assign(2*node + 1,mid+1,fin,lzset[node]);
            lzset[node]=lzneut;
        }
    }

    void setUpdate(int node, int ini, int fin, int l, int r, ll val){
        if (fin < l || r < ini) return;
        if (l <= ini && fin <= r){
            assign(node,ini,fin,val);
            return;
        }
        push(node,ini,fin);
        ll mid = (ini+fin)/2;
        setUpdate(2*node,ini,mid,l,r,val);
        setUpdate(2*node + 1,mid+1,fin,l,r,val);
        st[node] = (st[2*node] + st[2*node + 1])%mod;
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return neut;
        if (l <= ini && fin <= r) return st[node];
        push(node,ini,fin);
        int mid = (ini+fin)/2;
        ll lsum = query(2*node,ini,mid,l,r);
        ll rsum = query(2*node + 1,mid+1,fin,l,r);
        st[node] = (st[2*node] + st[2*node + 1])%mod;
        return (lsum + rsum)%mod;
    }

    void build(){ build(1,1,n);}
    void setUpdate(int l, int r, ll val){ setUpdate(1,1,n,l,r,val);}
    ll query(int l, int r){ return query(1,1,n,l,r);}
};      

void criba(){
    fore(i,2,maxval){
        if (!v[i]){
            for(int j = 1; i*j<maxval; j++){
                v[i*j]=1;
                mxpf[i*j]=i;
                ll x = i*j;
                while(x%i == 0){
                    x /= i;
                    spf[i*j] += i;
                }
            }
        }
    }
    spf[1]=0;
    mxpf[1]=0;
}

ll n,q;

int main(){
    fast;
    criba();
    cin>>n;
    fore(i,1,n+1) cin>>a[i];

    STree stnums(n,true);
    stnums.build();
    STree stsum(n,false);
    stsum.build();
    cin>>q;
    while(q--){
        ll typ;
        cin>>typ;
        if (typ == 1){
            ll pos;
            cin>>pos;
            ll x = stnums.query(pos,pos);
            if (x > 1){
                ll newval = x/mxpf[x];
                stnums.setUpdate(pos,pos,newval);
                stsum.setUpdate(pos,pos,spf[x]-mxpf[x]);
            }   
        }
        else if (typ == 2){
            ll l,r,res;
            cin>>l>>r;
            res = stsum.query(l,r);
            cout<<res<<nl;
        }
        else{
            ll l,r,x;
            cin>>l>>r>>x;
            stnums.setUpdate(l,r,x);
            stsum.setUpdate(l,r,spf[x]);
        }
    }
    return 0;
}