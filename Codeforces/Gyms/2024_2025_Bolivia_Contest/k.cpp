#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e3+5;

ll n,m,v[maxn][maxn],ans=0,mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char a[maxn][maxn];

bool validCell(int fil, int col){
    if (fil < 0 || fil >= n || col < 0 || col >= m) return false;
    return true;
}

bool canMove(int fil, int col){
    fore(i,0,4){
        int sfil = fil + mov[i][0];
        int scol = col + mov[i][1];
        if (validCell(sfil,scol) && a[sfil][scol] == 'T') return false;
    }
    return true;
}

void bfs(){
    queue < pii > q;
    fore(i,0,n) fore(j,0,m) if (a[i][j] == 'S'){
        q.push({i,j});
        v[i][j]=0;
    }
    while(!q.empty()){
        int fil = q.front().fst;
        int col = q.front().snd;
        q.pop();
        if (!canMove(fil,col)) continue;
        fore(i,0,4){
            int sfil = fil + mov[i][0];
            int scol = col + mov[i][1];
            if (validCell(sfil,scol) && !v[sfil][scol] && a[sfil][scol] != '#'){
                q.push({sfil,scol});
                v[sfil][scol]=1;
                int val = (int)(a[sfil][scol]-'0');
                if (0 <= val && val <= 9) ans += val;
            }
        }
    }
}

void init(){
    fore(i,0,n) fore(j,0,m) v[i][j]=0;
    ans=0;
}

int main(){
    fast;
    while(cin>>n>>m){
        init();
        fore(i,0,n) fore(j,0,m) cin>>a[i][j];

        bfs();

        cout<<ans<<nl;
    }
    
    return 0;
}