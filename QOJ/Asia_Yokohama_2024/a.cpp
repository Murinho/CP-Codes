#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define vi vector<ll>
#define vvi vector<ll>
#define pii pair <ll,ll>
#define sz(a) (ll)a.size()
#define ALL(a) a.begin(),a.end()


using namespace std;

const ll maxn = 110;

struct UF{
  ll pad,ran,l,r;
};

UF uf[maxn];
ll n,a[maxn];
vector <pii> b;
ll ans=0;

int bus(int u){
  if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad);
  return uf[u].pad;
}

void join(int u, int v){
  u = bus(u);
  v = bus(v);

  if (u == v) return;

  if (uf[u].ran < uf[v].ran) swap(u,v);

  uf[v].pad = u;
  uf[u].l = min(uf[u].l,uf[v].l);
  uf[u].r = max(uf[u].r,uf[v].r);

  if (uf[u].ran == uf[v].ran) uf[u].ran++;

  return;
}

void init(){
  a[0] = 0;
  a[n+1] = 0;
  fore(i,0,n+1){
    uf[i].ran = 0;
    uf[i].pad = uf[i].l = uf[i].r = i;
  }
}

int main(){
  fast;
  cin >> n;
  init();
  fore(i,1,n+1){
    cin >> a[i];
    b.pb({a[i],i});
  }

  sort(ALL(b));
  reverse(ALL(b));

  for(int i = 0; i<n; i++){
    int pos = i;
    while(pos < n && b[i].f == b[pos].f) pos++;

    fore(j,i,pos){
      if (b[j].s - 1 >= 1 && a[b[j].s - 1] >= a[b[j].s]) join(b[j].s - 1, b[j].s);
      if (b[j].s + 1 <= n && a[b[j].s + 1] >= a[b[j].s]) join(b[j].s + 1, b[j].s);
    }

    set <ll> st;
    fore(j,i,pos){
      ll pad = bus(b[j].s);
      st.insert(pad);
    }

    ans += sz(st);

    i = pos-1;
  }

  cout << ans << nl;
  return 0;
}