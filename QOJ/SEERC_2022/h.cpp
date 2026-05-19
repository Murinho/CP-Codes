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

const ll maxn = 550;

stack <ll> stk[4];
ll n;
vector <pii> a;

void insert(ll p1, ll p2){
  ll x = stk[p1].top();
  stk[p1].pop();
  a.pb({p1,p2});
  stk[p2].push(x);
}

int main(){
  fast;
  cin >> n;
  fore(i,1,n+1){
    ll x;
    cin >> x;
    stk[1].push(x);
  }

  if (n == 1){
    cout << 1 << nl;
    cout << 1 << " " << 3 << nl;
    return 0;
  }

  while(sz(stk[1]) > 0){
    while(sz(stk[1])){
      if (sz(stk[3]) == 0){
        insert(1,3);
      }
      else if (stk[3].top() > stk[1].top()){
        insert(1,3);
      }
      else break;
    }

    if (sz(stk[3]) == n) break;

    insert(1,2);

    while(sz(stk[3]) && stk[3].top() < stk[2].top()){
      insert(3,1);
    }
    insert(2,3);
  }

  // assert(sz(stk[3]) == n);

  // cout << "Debug: " << nl;
  // while(sz(stk[3]) > 0){
  //   ll x = stk[3].top();
  //   cout << x << " ";
  //   stk[3].pop();
  // }
  // cout << nl;

  cout << sz(a) << nl;
  for(auto &[i,j] : a) cout << i << " " << j << nl;
  return 0;
}