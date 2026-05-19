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

using namespace std;

set<int>a[26];

int main(){
  fast;
  string s,t;
  cin>>s>>t;

  int n=s.size();

  for(int i=0; i<n;i++){
    a[s[i]-'a'].insert(i);
    a[s[i]-'a'].insert(n+i);
  }

  int res=1;

  int cur=*a[t[0]-'a'].begin();

  int k=t.size();

  for(int i=1;i<k;i++){
    int aux=*a[t[i]-'a'].upper_bound(cur);

    aux%=n;

    if(aux<= cur)res++;
    cur=aux;
  }

  cout << res <<"\n";


}