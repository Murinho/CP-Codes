#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i <b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; --i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1005;
const ll maxi = 1e5+5;
const ll INF = 1e9+7;
ll n,m,b[maxi],mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //NSWE.
ll d[maxn][maxn][5],inifil,inicol;
char a[maxn][maxn];
string s;

void init(){
    fore(i,0,n) fore(j,0,m) fore(x,0,5) d[i][j][x]=INF;
}

bool valid(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void bfs(){
    queue < tuple<ll,ll,ll> > q; //row,column,current direction.
    init();
    d[inifil][inicol][b[0]]=0;
    q.push({inifil,inicol,b[0]});
    while(!q.empty()){
        tuple <ll,ll,ll> tu = q.front();
        int fil = get<0>(tu);
        int col = get<1>(tu);
        int curdir = get<2>(tu);
        q.pop();
        if (d[fil][col][curdir] >= sz(s)) continue;
        int nexdir = b[d[fil][col][curdir]+1];
        fore(i,0,4){
            if (i == curdir) continue;
            int sfil = fil + mov[i][0];
            int scol = col + mov[i][1];
            if (valid(sfil,scol) && d[sfil][scol][nexdir]== INF && a[sfil][scol] != '#'){
                d[sfil][scol][nexdir] = d[fil][col][curdir] + 1;
                q.push({sfil,scol,nexdir});
            }
        }   
    }
}

int main(){
    fast;
    cin>>m>>n;
    fore(i,0,n) fore(j,0,m){
        cin>>a[i][j];
        if (a[i][j] == 'S'){
            inifil = i;
            inicol = j;
        }
    }
    cin>>s;
    fore(i,0,sz(s)){
        if (s[i] == 'N') b[i] = 0;
        else if (s[i] == 'S') b[i] = 1;
        else if (s[i] == 'W') b[i] = 2;
        else b[i] = 3;
    }
    b[sz(s)]=4; //end of path value.
    
    bfs();

    bool ok;
    fore(i,0,n){
        fore(j,0,m){
            ok=true;
            fore(x,0,4){
                if (d[i][j][x] < INF){
                    ok=false;
                    break;
                }
            }
            if (ok && d[i][j][4] == sz(s)) cout<<"!";
            else cout<<a[i][j];
        }
        cout<<nl;
    }
    return 0;
}