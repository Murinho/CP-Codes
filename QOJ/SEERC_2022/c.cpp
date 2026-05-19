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

const int N=1000;
set<int>v[N];
pair<vector<unsigned>,int>bit[N];
int a[N+1];

int main(){
  fast;

  int n,m;

  cin>>n>>m;

  for(int i=0;i<m;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int a;
      cin>>a;
      v[i].insert(a-1);
    }
  }

  vector<int>sub(1<<m,n);
  for(int i=0;i<n;i++){
    vector<int>pos;
    for(int j=0;j<m;j++)
      if(v[j].find(i)==v[j].end())
        pos.push_back(j);
    for(int j=1;j<(1<<pos.size());j++){
      int f=0;
      for(int k=0;k<pos.size();k++){
        if((j>>k)&1)f|=(1<<pos[k]);
      }
      sub[f]--;
    }
  }

  for(int i=0;i<n;i++){

    for(int j=0;j<=N;j++)a[j]=0;
    a[0]=1;

    vector<int>pos;
    for(int j=0;j<m;j++)
      if(v[j].find(i)==v[j].end())
        pos.push_back(j);
    for(int j=1;j<(1<<pos.size());j++){
      int f=0,c=0;
      for(int k=0;k<pos.size();k++){
        if((j>>k)&1)f|=(1<<pos[k]),c^=1;
      }
      a[sub[f]]+=(c?-1:1);
    }

    bit[i].first.resize(N/32+1);
    bit[i].second=i;
    for(int j=N;j>0;j--){
      a[j-1]+=a[j]/2;
      a[j]%=2;
      if(a[j]==-1){
        a[j]=1;
        a[j-1]--;
      }
      bit[i].first[j/32]|=(a[j]<<(31-j%32));
    }
    bit[i].first[0]|=(a[0]<<31);
  }
  sort(bit,bit+n);
  for(int i=0;i<n;i++)cout<<bit[i].second+1<<" ";
  cout<<"\n";
}