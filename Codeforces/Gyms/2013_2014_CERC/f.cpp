#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define nl '\n'
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

const int maxn = 10;
const int n = 10;
char a[maxn][maxn];
int cnt,b[maxn][maxn];
ll ans = 0;
int tc;
map <ll,ll> dp[maxn][maxn];
int mov[4][2] = {{1,1},{-1,-1},{1,-1},{-1,1}};

void init(){
    cnt = 0;
    ans = 1;
    fore(i,0,n) fore(j,0,n){
        b[i][j] = -1;
    }
}

void label_pieces(){
    fore(i,0,n){
        fore(j,0,n){
            if (a[i][j] == 'B'){
                b[i][j] = cnt++;
            }
        }
    }
}

bool good(int &fil, int &col){
    if (min(fil,col) < 0 || max(fil,col) >= n) return false;
    return true;
}

void clean(){
    fore(i,0,n) fore(j,0,n){
        dp[i][j].clear();
    }
}

void bfs(int sti, int stj){
    clean();
    queue < array <ll,3> > q;
    q.push({sti,stj,0});
    dp[sti][stj][0] = 1;
    a[sti][stj] = '#';

    while(sz(q)){
        auto [fil,col,mk] = q.front();
        q.pop();

        fore(i,0,4){
            int sigfil = fil + mov[i][0];
            int sigcol = col + mov[i][1];
            if (good(sigfil,sigcol) && a[sigfil][sigcol] == 'B' && !(mk&(1ll<<b[sigfil][sigcol]))){
                ll sigmk = mk + (1ll<<b[sigfil][sigcol]);
                sigfil += mov[i][0];
                sigcol += mov[i][1];
                if (good(sigfil,sigcol) && a[sigfil][sigcol] == '#' && dp[sigfil][sigcol][sigmk] == 0){
                    dp[sigfil][sigcol][sigmk] = dp[fil][col][mk] + 1;
                    ans = max(ans,dp[sigfil][sigcol][sigmk]);
                    q.push({sigfil,sigcol,sigmk});
                }
            }
        }
    }

    a[sti][stj] = 'W';
}

void solve(){
    fore(i,0,n) fore(j,0,n) cin >> a[i][j];

    init();
    label_pieces();
    fore(i,0,n){
        fore(j,0,n){
            if (a[i][j] == 'W'){
                bfs(i,j);
            }
        }
    }

    cout << ans - 1 << nl;
    return;
}

int main(){
    fast;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}