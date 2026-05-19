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

const ll maxn = 55;

char a[maxn][maxn];
pii to[maxn][maxn];
ll in[maxn][maxn];
bool vis[maxn][maxn];
ll res[maxn][maxn][2];
ll str,stc;
ll n,m;
ll mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void init(){
  fore(i,0,n){
    fore(j,0,m){
      fore(k,0,2){
        res[i][j][k] = -1;
      }
    }
  }
}

bool good(int x, int y){
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  return true;
}

void bfs(){
  queue <pii> q;
  q.push({str,stc});
  to[str][stc] = {str,stc};
  vis[str][stc] = true;
  while(sz(q)){
    auto [r,c] = q.front();
    q.pop();

    fore(i,0,4){
      int sr = r + mov[i][0];
      int sc = c + mov[i][1];
      if (good(sr,sc) && !vis[sr][sc] && a[sr][sc] != '.'){
        vis[sr][sc] = true;
        to[sr][sc] = {r,c};
        in[r][c]++;
        q.push({sr,sc});
      }
    }
  }
}

void topobfs(){
  queue <pii> q;
  fore(i,0,n){
    fore(j,0,m){
      if (in[i][j] == 0 && vis[i][j]){
        res[i][j][0] = (int)a[i][j] - '0';
        // cout << "leaf: " << i << " " << j << ": " << res[i][j][0] << nl;
        q.push({i,j});
      }
    }
  }

  while(sz(q)){
    auto [r,c] = q.front();
    q.pop();

    // cout << r << " " << c << nl;

    if (r == str && c == stc) break;

    ll val = 0;
    if (a[r][c] == '+'){
      val = res[r][c][0] + res[r][c][1];
    }
    else if (a[r][c] == '-'){
      val = max(res[r][c][0], res[r][c][1]) - min(res[r][c][0], res[r][c][1]);
    }
    else if (a[r][c] == '*'){
      val = res[r][c][0] * res[r][c][1];
    }
    else if (a[r][c] == '/'){
      val = max(res[r][c][0], res[r][c][1])/min(res[r][c][0], res[r][c][1]);
    }
    else{
      val = res[r][c][0];
    }

    in[to[r][c].f][to[r][c].s]--;
    if (res[to[r][c].f][to[r][c].s][0] == -1){
      res[to[r][c].f][to[r][c].s][0] = val;
    }
    else{
      res[to[r][c].f][to[r][c].s][1] = val;
    }

    if (in[to[r][c].f][to[r][c].s] == 0){
      q.push({to[r][c].f, to[r][c].s});
    }
  }
}

int main(){
  fast;
  cin >> n >> m;
  init();
  fore(i,0,n){
    fore(j,0,m) {
      cin >> a[i][j];
      if (a[i][j] == 'P'){
        str = i;
        stc = j;
      }
    }
  }

  bfs();

  topobfs();

  // fore(r,0,n){
  //   fore(c,0,m){
  //     ll val = 0;
  //     if (a[r][c] == '+'){
  //       val = res[r][c][0] + res[r][c][1];
  //     }
  //     else if (a[r][c] == '-'){
  //       val = max(res[r][c][0], res[r][c][1]) - min(res[r][c][0], res[r][c][1]);
  //     }
  //     else if (a[r][c] == '*'){
  //       val = res[r][c][0] * res[r][c][1];
  //     }
  //     else if (a[r][c] == '/'){
  //       val = max(res[r][c][0], res[r][c][1])/min(res[r][c][0], res[r][c][1]);
  //     }
  //     else{
  //       val = res[r][c][0];
  //     }
  //     cout << val << " ";
  //   }
  //   cout << nl;
  // }

  cout << res[str][stc][0] << nl;
  return 0;
}