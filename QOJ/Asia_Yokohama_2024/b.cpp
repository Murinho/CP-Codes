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

int main(){
  fast;
  ll a,b;
  cin>>a>>b;
  ll res=0;
  bool d=0;
  ll v=0;

  ll t=1;
  while(t<a)t*=2;
  if(b>=t){
    cout << t<<"\n";
    return 0;
  }

  for(int j=63;j>=0;j--){
    v/=2;
    if(d && (a&(1ll<<j))){
      res+=v;
      if(res<a)res+=v;
      break;
    } else if(d)continue; 
    if((a&(1ll<<j)) != (b&(1ll<<j))){
      d=1;
      v=(1ll<<j);
    } else {
      res+=(a&(1ll<<j));
    }
  }
  cout << res<<"\n";

}