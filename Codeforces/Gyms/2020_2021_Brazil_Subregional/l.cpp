#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 50;

char g[maxn][maxn];
ll mk[maxn][maxn][25];
ll n,m,q,cntq=0;
map <ll,ll> mp,cur;

bool outside(int &x, int &y){
    if (x <= 0 || x > n || y <= 0 || y > m) return true;
    return false;
}

ll gv(char c){
    return (ll)(c-'A');
}

bool check(){
    fore(i,0,26) if (cur[i]!=mp[i]) return false;
    return true;
}

void remove(int &x, int &y){
    cur[gv(g[x][y])]--;
}

void add(int &x, int &y){
    cur[gv(g[x][y])]++;
}

void checkV(string &s){
    if (sz(s) > n) return;
    int lx,ly,rx,ry,cnt=0;
    fore(i,1,m+1){
        cur.clear();
        cnt=0;
        lx=1,ly=i;
        rx=lx;
        ry=ly;
        while(cnt<sz(s)){
            cur[gv(g[rx][ry])]++;
            rx++;
            cnt++;
        }
        while(true){    
            if (check()){
                fore(j,lx,rx) mk[j][ry][cntq]=1;
            }
            remove(lx,ly);
            if (outside(rx,ry)) break;
            add(rx,ry);
            lx++, rx++; //move pointers.
        }
    }
}

void checkH(string &s){
    if (sz(s) > m) return;
    int lx,ly,rx,ry,cnt=0;
    fore(i,1,n+1){
        cur.clear();
        cnt=0;
        lx=i,ly=1;
        rx=lx;
        ry=ly;
        while(cnt<sz(s)){
            cur[gv(g[rx][ry])]++;
            ry++;
            cnt++;
        }
        while(true){    
            if (check()){
                fore(j,ly,ry) mk[rx][j][cntq]=1;
            }
            remove(lx,ly);
            if (outside(rx,ry)) break;
            add(rx,ry);
            ly++, ry++; //move pointers.
        }
    }
}

void checkDi(string &s){
    if (sz(s) > min(n,m)) return;
    int lx,ly,rx,ry,cnt,cx,cy;
    fore(i,1,n+1){
        cur.clear();
        cnt=0;
        lx=i,ly=1;
        rx=lx, ry=ly;
        while(cnt<sz(s) && !outside(rx,ry)){
            cur[gv(g[rx][ry])]++;
            rx++, ry++;
            cnt++;
        }
        while(true){    
            if (check()){
                cx=lx, cy=ly;
                while(cx != rx){
                    mk[cx][cy][cntq]=1;
                    cx++, cy++;
                }
            }
            remove(lx,ly);
            if (outside(rx,ry)) break;
            add(rx,ry);
            lx++, ly++;
            rx++, ry++;
        }
    }
    fore(i,1,m+1){
        cur.clear();
        cnt=0;
        lx=1,ly=i;
        rx=lx, ry=ly;
        while(cnt<sz(s) && !outside(rx,ry)){
            cur[gv(g[rx][ry])]++;
            rx++, ry++;
            cnt++;
        }
        while(true){    
            if (check()){
                cx=lx, cy=ly;
                while(cx != rx){
                    mk[cx][cy][cntq]=1;
                    cx++, cy++;
                }
            }
            remove(lx,ly);
            if (outside(rx,ry)) break;
            add(rx,ry);
            lx++, ly++;
            rx++, ry++;
        }
    }
}

void checkDd(string &s){
    if (sz(s) > min(n,m)) return;
    int lx,ly,rx,ry,cnt,cx,cy;
    fore(i,1,n+1){
        cur.clear();
        cnt=0;
        lx=i,ly=m;
        rx=lx, ry=ly;
        while(cnt<sz(s) && !outside(rx,ry)){
            cur[gv(g[rx][ry])]++;
            rx++, ry--;
            cnt++;
        }
        while(true){    
            if (check()){
                cx=lx, cy=ly;
                while(cx != rx){
                    mk[cx][cy][cntq]=1;
                    cx++, cy--;
                }
            }
            remove(lx,ly);
            if (outside(rx,ry)) break;
            add(rx,ry);
            lx++, ly--;
            rx++, ry--;
        }
    }
    fore(i,1,m+1){
        cur.clear();
        cnt=0;
        lx=1,ly=i;
        rx=lx, ry=ly;
        while(cnt<sz(s) && !outside(rx,ry)){
            cur[gv(g[rx][ry])]++;
            rx++, ry--;
            cnt++;
        }
        while(true){    
            if (check()){
                cx=lx, cy=ly;
                while(cx != rx){
                    mk[cx][cy][cntq]=1;
                    cx++, cy--;
                }
            }
            remove(lx,ly);
            if (outside(rx,ry)) break;
            add(rx,ry);
            lx++, ly--;
            rx++, ry--;
        }
    }
}

int main(){
    fast;
    cin>>n>>m;
    fore(i,1,n+1) fore(j,1,m+1){
        cin>>g[i][j];
    }
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        mp.clear();
        for(auto elm : s) mp[gv(elm)]++;
        checkV(s);
        checkH(s);
        checkDi(s);
        checkDd(s);
        cntq++;
    }

    ll ans=0;
    fore(i,1,n+1){
        fore(j,1,m+1){
            ll aux=0;
            fore(k,0,20) aux += mk[i][j][k];
            if (aux>=2) ans++;
        }
    }
    cout<<ans<<nl;
    return 0;
}