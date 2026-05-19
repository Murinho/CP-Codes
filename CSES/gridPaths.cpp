#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace __gnu_pbds;
using namespace std;

const ll n = 48;
const ll m = 7;
ll vis[m][m];
string s;

void init(){
    fore(i,0,m){
        fore(j,0,m){
            vis[i][j]=0;
        }
    }
}

bool valid(int x, int y){
    if (min(x,y) < 0 || max(x,y) >= m) return false;
    if (vis[x][y]) return false;
    return true;
}

bool jokerValid(int x, int y){
    if (!valid(x-1,y) && !valid(x+1,y) && valid(x,y-1) && valid(x,y+1)) return false;
    if (valid(x-1,y) && valid(x+1,y) && !valid(x,y-1) && !valid(x,y+1)) return false;
    return true;
}

pii move(int x, int y, char c){
    if (c == 'L') y--;
    else if (c == 'R') y++;
    else if (c == 'U') x--;
    else if (c == 'D') x++;
    return {x,y};
}

ll dfs(int x, int y, int pos){
    if (x == m-1 && y == 0){
        if (pos == n) return 1;
        else return 0;
    }
    ll ans=0;
    vis[x][y]=1;
    if (s[pos]=='?'){
        if (jokerValid(x,y)){
            pii p;
            p = move(x,y,'L');
            if (valid(p.fst,p.snd)) ans += dfs(p.fst,p.snd,pos+1);
            p = move(x,y,'R');
            if (valid(p.fst,p.snd)) ans += dfs(p.fst,p.snd,pos+1);
            p = move(x,y,'U');
            if (valid(p.fst,p.snd)) ans += dfs(p.fst,p.snd,pos+1);
            p = move(x,y,'D');
            if (valid(p.fst,p.snd)) ans += dfs(p.fst,p.snd,pos+1);
        }
    }
    else{
        pii p = move(x,y,s[pos]);
        if (valid(p.fst,p.snd)) ans += dfs(p.fst,p.snd,pos+1);
    }
    vis[x][y]=0;
    return ans;
}

int main(){
    fast;
    cin>>s;
    init();
    cout<<dfs(0,0,0)<<nl;
    return 0;
}