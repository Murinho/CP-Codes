#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define f first
#define s second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'

using namespace std;

const ll maxn = 2e5+100;
const ll inf = 1e18;

vi perm = {1,2,3,4,5,6};
ll n,dp[maxn];
vector <pii> b;

vvi combs;

void init(){
  fore(i,1,(2*n) + 5) dp[i] = inf;
}

void precalc(){
  do{
    bool f = true;
    for(int i = 0; i<6; i += 2){
      if (perm[i] > perm[i+1]){
        f = false;
      }
    }
    if (f) combs.pb(perm);
  }while(next_permutation(ALL(perm)));

  // cout << sz(combs) << nl;
}

int main(){
  fast;
  cin >> n;

  init();
  precalc();

  fore(i,1,(2*n)+1){
    ll x;
    cin >> x;
    b.pb({x,i});
  }

  b.pb({-1,-1});

  sort(ALL(b));

  dp[1] = 0;
  for(int i = 1; i<=2*n; i += 2){
    ll pro = (b[i].s%2 == 1 ? b[i].s + 1 : b[i].s - 1);

    if (pro != b[i+1].s){ // expandir a dp[i+2]
      dp[i+2] = min(dp[i+2], dp[i] + (b[i+1].f - b[i].f));
    }
    
    
    if (i+3 <= 2*n) { // expandir a dp[i+4]:
      dp[i+4] = min(dp[i+4], dp[i] + b[i+2].f + b[i+3].f - b[i+1].f - b[i].f);
    }

    if (i+5 <= 2*n){ // expandir a dp[i+6]
      for(auto &v : combs){
        bool f = true;
        for(int j = 0; j<6; j += 2){
          ll pro = (b[i+v[j]-1].s%2 == 1 ? b[i+v[j]-1].s + 1 : b[i+v[j]-1].s - 1); // calc el prohibido
          if (pro == b[i + v[j+1] - 1].s){
            f = false;
            break;
          }
        }
        if (f){
          ll add = 0;
          for(int j = 0; j<6; j += 2){
            add += (b[i + v[j+1] - 1].f - b[i + v[j] - 1].f);
          }
          dp[i+6] = min(dp[i+6], dp[i] + add);
        }
      }
    }
  }
  cout << dp[2*n + 1] << nl;
  return 0;
}