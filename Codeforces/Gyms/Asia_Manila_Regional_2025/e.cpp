#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fst first
#define snd second
#define nl '\n'

using namespace std;

const int maxn = 101;
const int inf = 1e9;

int n,m,sax,say,sbx,sby,ebx,eby;
char a[maxn][maxn],b[maxn][maxn];
int d[maxn][maxn][maxn][maxn];
int mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void init(){
    fore(i,0,n){
        fore(j,0,m){
            fore(ii,0,n){
                fore(jj,0,m){
                    d[i][j][ii][jj] = inf;
                }
            }
        }
    }
}

array <ll,4> move(int ax, int ay, int bx, int by, int dx, int dy){
    if (ax + dx < 0 || ax + dx >= n) return {-1,-1,-1,-1};
    if (ay + dy < 0 || ay + dy >= m) return {-1,-1,-1,-1};

    int sigax = ax + dx;
    int sigay = ay + dy;
    
    if (a[sigax][sigay] == 'X') return {-1,-1,-1,-1};

    int sigbx = bx + dx;
    int sigby = by + dy;
    if (sigbx < 0 || sigbx >= n || sigby < 0 || sigby >= m){
        sigbx = bx;
        sigby = by;
    }
    else if (b[sigbx][sigby] == 'X'){
        sigbx = bx;
        sigby = by;
    }
    return {sigax,sigay,sigbx,sigby};
}

void bfs(){
    queue < array <ll,4> > q;
    q.push({sax,say,sbx,sby});
    d[sax][say][sbx][sby] = 0;
    while(sz(q)){
        auto [ax,ay,bx,by] = q.front();
        q.pop();

        fore(i,0,4){
            auto [sigax,sigay,sigbx,sigby] = move(ax,ay,bx,by,mov[i][0],mov[i][1]);
            if (sigax == -1) continue;

            if (d[sigax][sigay][sigbx][sigby] == inf){
                d[sigax][sigay][sigbx][sigby] = d[ax][ay][bx][by] + 1;
                q.push({sigax,sigay,sigbx,sigby});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    init();
    fore(i,0,n){
        fore(j,0,m){
            cin >> a[i][j];
            if (a[i][j] == 'S'){
                sax = i;
                say = j;
            }
        }
    }

    fore(i,0,n){
        fore(j,0,m){
            cin >> b[i][j];
            if (b[i][j] == 'S'){
                sbx = i;
                sby = j;
            }
            else if (b[i][j] == 'D'){
                ebx = i;
                eby = j;
            }
        }
    }

    bfs();

    int ans = inf;

    fore(i,0,n){
        fore(j,0,m){
            ans = min(ans,d[i][j][ebx][eby]);
        }
    }

    if (ans == inf) cout << -1 << nl;
    else cout << ans << nl;

    return;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){ solve(); }
}