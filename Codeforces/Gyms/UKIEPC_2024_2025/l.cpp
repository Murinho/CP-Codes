#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n' 
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define ld long double
#define eb emplace_back

using namespace std;

constexpr int MONTH=31;
constexpr int WEEK=7;

constexpr const char *REST=u8"\U0001f916";
constexpr const char *LEG=u8"\U0001f9Bf";
constexpr const char *ARM=u8"\U0001f9Be";

int main(){
  int n; cin>>n;
  vector<bool> rest(n),leg(n);

  for (int i=0; i<n; i++){
    string s; cin>>s;
    if (s.find("rest")!=string::npos){
      rest[i]=true;
    }
    if (s.find("leg")!=string::npos){
      leg[i]=true;
    }
  }

  for (int i=0; i<31; i++){
    if (i%WEEK==0){
      cout<<i/WEEK+1<<' ';
    }
    cout<<(rest[i%n]?REST:leg[i%n]?LEG:ARM);
    if (i%WEEK==WEEK-1){
      cout<<endl;
    }
  }
  if (MONTH%WEEK!=WEEK){
    cout<<endl;
  }
}
