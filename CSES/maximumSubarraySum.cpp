#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace __gnu_pbds;
using namespace std;
 
const ll maxn = 2e5+100;
const ll INF = 1e18+7;
 
ll n,kl,kr,p[maxn],a[maxn];
 
struct STree{
    vi st; int n;
    STree(int n): st(4*n + 5), n(n) {}
 
    void build(int node, int ini, int fin){
        if (ini == fin){
            st[node] = p[ini];
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node] = max(st[2*node],st[2*node + 1]);
    }

 
    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return -INF;
        if (l <= ini && fin <= r) return st[node];
        int mid = (ini+fin)/2;
        return max(query(2*node,ini,mid,l,r),query(2*node + 1,mid+1,fin,l,r));
    }
 
    void build(){ build(1,1,n);}
    ll query(int l, int r){ return query(1,1,n,l,r);}
};
 

int main(){
    fast;
    cin>>n>>kl>>kr;
    fore(i,1,n+1) cin>>a[i], p[i] = p[i-1] + a[i];

    STree st(n);
    st.build();

    ll ans = -INF;

    fore(i,0,n-kl+1){
        ll mx = st.query(i+kl,min(i+kr,n+1));
        ans = max(ans,mx-p[i]);
    }
    cout<<ans<<nl;
    return 0;
}
