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
#define ld long double
#define eb emplace_back
#define vi vector<ll>
#define sz(a) ((ll)a.size())
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)

using namespace std;

const ll maxn = 2e5+100;
const ll neut = 0;
const ll lzneut = 1;
const ll loga = 18;
const ll mod = 1e9+7;

ll arr[maxn];

struct STree{ //Lazy Segment Tree with set and add updates with sum get query.
    vi st,lzmul; ll n;
    STree(int n): st(4*n + 5,neut),lzmul(4*n + 5,lzneut), n(n){}

    void build(int node, int ini, int fin){
        if (ini == fin){
            st[node] = arr[ini];
            return;
        }
        int mid = (ini+fin)/2;
        build(2*node,ini,mid);
        build(2*node + 1,mid+1,fin);
        st[node] = (st[2*node] + st[2*node + 1])%mod;
    }

    void multiply(int node, int ini, int fin, ll val){ // watch out with this
        val %= mod;                 // add this
        lzmul[node] = (lzmul[node] * val) % mod;
        st[node]    = (st[node]    * val) % mod;
    }

    void push(int node, int ini, int fin){
        int mid = (ini+fin)/2;
        if (lzmul[node] != lzneut){
            lzmul[node] %= mod;
            multiply(2*node,ini,mid,lzmul[node]);
            multiply(2*node + 1,mid+1,fin,lzmul[node]);
            lzmul[node] = lzneut;
        }
    }

    void mulUpdate(int node, int ini, int fin, int l, int r, ll val){
        if (fin < l || r < ini) return;
        if (l <= ini && fin <= r){
            multiply(node,ini,fin,val);
            return;
        }
        push(node,ini,fin);
        ll mid = (ini+fin)/2;
        mulUpdate(2*node,ini,mid,l,r,val);
        mulUpdate(2*node + 1,mid+1,fin,l,r,val);
        st[node] = (st[2*node] + st[2*node + 1])%mod;
    }

    ll query(int node, int ini, int fin, int l, int r){
        if (fin < l || r < ini) return neut;
        if (l <= ini && fin <= r) return st[node];
        push(node,ini,fin);
        int mid = (ini+fin)/2;
        return (query(2*node,ini,mid,l,r) + query(2*node + 1,mid+1,fin,l,r))%mod;
    }

    void build(){ build(1,1,n);} //[1,n]
    void mulUpdate(int l, int r, ll val){ mulUpdate(1,1,n,l,r,val);} //[l,r]
    ll query(int l, int r){ return query(1,1,n,l,r);} //[l,r]
};

ll n,qrys,label_cont;
ll up[maxn][loga],subt[maxn],dep[maxn],labe[maxn],tp[maxn],revlabe[maxn],p[loga];
vector <pii> g[maxn];

void init(){
    label_cont = 1;
    p[0] = 1;
    fore(i,1,loga) p[i] = (p[i-1] * 2LL);
    up[1][0] = 1;
}

int dfs_sz(int cur, int par){
    subt[cur] = 1;
	for (auto &[chi, ew] : g[cur]) {
		if (chi == par) continue;
		dep[chi] = dep[cur] + 1;
		up[chi][0] = cur;
		subt[cur] += dfs_sz(chi, cur);
	}
	return subt[cur];
}

void dfs_hld(int cur, int par, int top, ll val){
    labe[cur] = label_cont++;
    tp[cur] = top;
    arr[labe[cur]] = val;
    int h_chi = -1, h_sz = -1;
    ll hew = 0;
    for(auto &[chi,ew] : g[cur]){
        if (chi == par) continue;
		if (subt[chi] > h_sz) {
			h_sz = subt[chi];
			h_chi = chi;
            hew = ew;
		}
    }

    if (h_chi == -1) return;
    dfs_hld(h_chi, cur, top, hew);

    for(auto &[chi, ew] : g[cur]){
        if (chi == par || chi == h_chi) continue;
        dfs_hld(chi, cur, chi, ew);
    }
}

void binlift(){
    fore(i,1,loga){
        fore(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
    }
}

ll lca(ll x, ll y){
    if (x == y) return x;
    if (dep[x] > dep[y]) swap(x,y); //'y' is deeper.
    ll dif = dep[y] - dep[x];
    rofe(i,loga,0){
        if (p[i] <= dif){
            dif -= p[i];
            y = up[y][i];
        }
    }
    if (x == y) return x;
    rofe(i,loga,0){
        if (up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}

ll pathQuery(int chi, int par, STree &st, ll &mulval){
    ll ret = 0;
    while(chi != par){
        if (tp[chi] == chi){
            st.mulUpdate(labe[chi], labe[chi], mulval);

            ret += st.query(labe[chi], labe[chi]);
            ret %= mod;

            chi = up[chi][0];
        }
        else if (dep[tp[chi]] > dep[par]){
            st.mulUpdate(labe[tp[chi]], labe[chi], mulval);

            ret += st.query(labe[tp[chi]], labe[chi]);
            ret %= mod;

            chi = up[tp[chi]][0];
        }
        else{
            st.mulUpdate(labe[par] + 1, labe[chi], mulval);

            ret += st.query(labe[par] + 1, labe[chi]);
            ret %= mod;

            break;
        }
    }
    return ret;
}

int main(){
    fast;
    cin >> n >> qrys;
    init();
    fore(i,1,n){
        ll x,y,z;
        cin >> x >> y >> z;
        z %= mod;
        g[x].pb({y,z});
        g[y].pb({x,z});
    }

    dfs_sz(1,1);
    dfs_hld(1,1,1,0);
    binlift();

    STree st(n);
    st.build();

    while(qrys--){
        ll u,v,x;
        cin >> u >> v >> x;
        x %= mod;

        ll lcan = lca(u,v);

        ll qans = pathQuery(u,lcan,st,x) + pathQuery(v,lcan,st,x);
        qans %= mod;
        cout << qans << nl;
    }
}