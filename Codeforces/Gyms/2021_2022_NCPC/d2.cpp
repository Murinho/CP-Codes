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
ll d[maxn][maxn][2],inifil,inicol;
char a[maxn][maxn];
string s;

void init(int idx){
    fore(i,0,n) fore(j,0,m) d[i][j][idx]=INF;
}

void bfs(int idx){ //0: normal, 1: blocking.
    int block;
    queue < pii > q;
    init(idx);
    d[inifil][inicol][idx]=0;
    q.push({inifil,inicol});
    while(!q.empty()){
        pii p = q.front();
        int fil = p.fst;
        int col = p.snd;
        q.pop();
        if (idx == 1){
            block = b[d[fil][col][idx]];
            if (d[fil][col][idx] >= sz(s)) continue;
        }
        fore(i,0,4){
            int sfil = fil + mov[i][0];
            int scol = col + mov[i][1];
            if (idx == 0){ //normal.
                if (d[sfil][scol][idx] == INF && a[sfil][scol] == '.'){
                    d[sfil][scol][idx] = d[fil][col][idx] + 1;
                    q.push({sfil,scol});
                }
            }
            else{ //blockings.
                if (i == block) continue;
                if (d[sfil][scol][idx] == INF && a[sfil][scol] == '.'){
                    d[sfil][scol][idx] = d[fil][col][idx] + 1;
                    q.push({sfil,scol});
                }
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
    
    bfs(0);
    bfs(1);

    fore(i,0,n){
        fore(j,0,m){
            if (d[i][j][0] == d[i][j][1] && d[i][j][1] == sz(s)) cout<<"!";
            else cout<<a[i][j];
        }
        cout<<nl;
    }
    return 0;
}