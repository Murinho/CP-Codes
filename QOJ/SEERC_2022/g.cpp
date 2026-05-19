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

const ll maxn = 5e5+100;
const ll inf = 1e18;

ll n,a[maxn],r[maxn];
vector <pii> b,c;
ll res[maxn];
ll mn = inf;
bool flag = false;

void check(ll pos){
  flag = true;
  fore(i,1,n+1) res[i] = 0;
  map <ll,ll> mp;

  fore(i,1,n+1) mp[r[i]]++;

  res[pos] = mn;
  mp[mn]--;

  rofe(i,pos,1){
    ll dif = (a[i+1] - a[i]) - res[i+1];
    if (mp[dif] == 0){
      flag = false;
      return;
    }
    mp[dif]--;
    res[i] = dif;
  }

  fore(i,pos+1,n+1){
    ll dif = (a[i] - a[i-1]) - res[i-1];
    if (mp[dif] == 0){
      flag = false;
      return;
    }
    mp[dif]--;
    res[i] = dif;
  }

  return;
}

int main(){
  fast;
  cin >> n;
  fore(i,1,n+1){
    cin >> a[i];
  }

  fore(i,1,n+1){
    cin >> r[i];
    mn = min(mn,r[i]);
  }

  if (n <= 2){
    cout << r[1] << " " << r[2] << nl;
    return 0;
  }

  // alternar:
  ll sum = 0;
  fore(i,2,n+1){
    ll dif = a[i]-a[i-1];
    if (i%2 == 0){
      sum += dif;
      b.pb({sum,i});
    }
    else{
      sum -= dif;
      c.pb({sum,i});
    }
  }

  sort(ALL(b));
  sort(ALL(c));

  if (!flag) check(b.front().s - 1);
  if (!flag) check(b.front().s);

  if (!flag) check(c.back().s - 1);
  if (!flag) check(c.back().s);


  fore(i,1,n+1) cout << res[i] << " ";
  cout << nl;
  return 0;
}