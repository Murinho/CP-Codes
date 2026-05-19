#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define ld long double
#define eb emplace_back
#define vi vector<ll>
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 105;
const ll inf = 1e9+7;
ll n,m,k;
ll dp[maxn][maxn];
char a[maxn][maxn];
ll stfil,stcol;
ll efil,ecol;
vi moves[maxn];

int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void init(){
    fore(i,0,maxn) fore(j,0,maxn) dp[i][j] = inf;
}

bool good(ll &x, ll &y){
    if (0 <= x && x < n && 0 <= y && y < m && a[x][y] == '0') return true;
    return false;
}

array <ll,3> doit(vi &v, ll fil, ll col){
    ll cnt = 0;
    for(auto &id : v){
        fil += mov[id][0];
        col += mov[id][1];
        if (!good(fil,col)){
            fil -= mov[id][0];
            col -= mov[id][1];
        }
        else cnt++; 
    }
    return {cnt,fil,col};
}

void daikra(){
    priority_queue < array <ll,3> , vector <array <ll,3> >, greater <array <ll,3> > > pq;

    pq.push({0,stfil,stcol});
    dp[stfil][stcol] = 0;

    while(sz(pq)){
        auto [curw, fil,col] = pq.top();
        pq.pop();

        if (dp[fil][col] != curw) continue;

        fore(i,0,k){
            auto [w,sigfil,sigcol] = doit(moves[i],fil,col);

            if (dp[sigfil][sigcol] > curw + w){
                dp[sigfil][sigcol] = curw + w;
                pq.push({curw + w, sigfil, sigcol});
            }
        }
    }
}

int main(){
    fast;
    cin >> n >> m;
    init();

    fore(i,0,n){
        fore(j,0,m){
            cin >> a[i][j];
        }
    }

    cin >> stfil >> stcol;
    cin >> efil >> ecol;

    cin >> k;
    fore(i,0,k){
        string s;
        cin >> s;

        for(auto &c : s){
            if (c == 'U') moves[i].eb(0);
            else if (c == 'D') moves[i].eb(1);
            else if (c == 'L') moves[i].eb(2);
            else moves[i].eb(3);
        }
    }

    daikra();

    if (dp[efil][ecol] == inf) cout << -1 << nl;
    else cout << dp[efil][ecol] << nl;

    return 0;
}