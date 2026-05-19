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

const ll maxn = 4001;

struct Point{
  ll x,y;
};

char a[maxn][maxn];
bool vis[maxn][maxn];
ll n;
Point c[4];

char move_up(){
  cout << "^" << nl;
  cout.flush();
  char res;
  cin >> res;
  return res;
}

char move_down(){
  cout << "v" << nl;
  cout.flush();
  char res;
  cin >> res;
  return res;
}

char move_left(){
  cout << "<" << nl;
  cout.flush();
  char res;
  cin >> res;
  return res;
}

char move_right(){
  cout << ">" << nl;
  cout.flush();
  char res;
  cin >> res;
  return res;
}

void move_horizontal(){

}

void move_vertical(){

}

void init_move(){

}

int main(){
  fast;
  cin >> n;
  c[0] = {1,1};
  c[1] = {1,2*n + 1};
  c[2] = {2*n + 1,1};
  c[3] = {2*n + 1,2*n + 1};

  while()
} 