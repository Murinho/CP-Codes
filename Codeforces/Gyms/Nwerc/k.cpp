#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

const ll maxn = 550;
ll n,a,b,c,d;
bool dp[maxn][maxn][2];

int mov[4][2] = {{1,1},{-1,-1},{-1,1},{1,-1}};

bool good(int x, int y){
    if (0 <= x && x < n && 0 <= y && y < n) return true;
    return false;
}

void dfs(int row, int col, int turn){
    if (dp[row][col][turn]) return;

    dp[row][col][turn] = true;

    if (turn == 0){
        fore(v,0,2){
            fore(i,0,4){
                int nrow = row + (a * mov[i][0]);
                int ncol = col + (b * mov[i][1]);

                if (good(nrow,ncol)){
                    dfs(nrow,ncol,1-turn);
                }
            }
            swap(a,b);
        }
    }
    else{
        fore(v,0,2){
            fore(i,0,4){
                int nrow = row + (c * mov[i][0]);
                int ncol = col + (d * mov[i][1]);

                if (good(nrow,ncol)){
                    dfs(nrow,ncol,1-turn);
                }
            }
            swap(c,d);
        }
    }
}

int main(){
    fast;
    cin >> n;
    cin >> a >> b;
    cin >> c >> d;

    dfs(0,0,0);
    dfs(0,0,1);

    ll ans = 0;

    fore(i,0,n){
        fore(j,0,n){
            //cout << (dp[i][j][0] | dp[i][j][1]) << " ";
            ans += (dp[i][j][0] | dp[i][j][1]);
        }
        //cout << nl;
    }
    cout << ans << nl;
    return 0;
}