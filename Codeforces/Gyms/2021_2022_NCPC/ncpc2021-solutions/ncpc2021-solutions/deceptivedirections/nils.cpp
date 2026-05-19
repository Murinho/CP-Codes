#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int n,m,k;

bool blocked[1001][1001] = {0};
string seq;
int startx, starty;

int dist[1001][1001] = {0};
bool seen[1001][1001] = {0};

int DX[4] = {0, -1, 0, 1};
int DY[4] = {1, 0, -1, 0};

int char_to_index(char ch){
    if(ch == 'E')return 0;
    if(ch == 'N')return 1;
    if(ch == 'W')return 2;
    return 3;
}

int main() {
    cin >> m >> n;

    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            blocked[c1][c2] = (s[c2] == '#');
            if(s[c2] == 'S'){
                startx = c1;
                starty = c2;
            }
        }
    }
    cin >> seq;
    k = sz(seq);

    // BFS to find distances
    queue<pii> Q;
    Q.push({startx,starty});
    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        if(!seen[p.first][p.second]){
            seen[p.first][p.second] = 1;
            rep(c1,0,4){
                int x = p.first + DX[c1];
                int y = p.second + DY[c1];
                if(!blocked[x][y] && !seen[x][y]){
                    dist[x][y] = dist[p.first][p.second] + 1;
                    Q.push({x, y});
                }
            }
        }
    }

    // BFS to find answer
    rep(c1,0,n){
        rep(c2,0,m){
            seen[c1][c2] = 0;
        }
    }
    Q.push({startx, starty});
    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        if(!seen[p.first][p.second]){
            seen[p.first][p.second] = 1;
            int d = dist[p.first][p.second];
            if(d < k){
                rep(c1,0,4){
                    if(c1 == char_to_index(seq[d]))continue;
                    int x = p.first + DX[c1];
                    int y = p.second + DY[c1];
                    if(!blocked[x][y] && !seen[x][y] && dist[x][y] == d+1){
                        Q.push({x, y});
                    }
                }
            }
        }
    }

    rep(c1,0,n){
        rep(c2,0,m){
            if(blocked[c1][c2]){
                cout << "#";
            }
            else{
                if(seen[c1][c2] && dist[c1][c2] == k){
                    cout << "!";
                }
                else{
                    if(c1 == startx && c2 == starty){
                        cout << "S";
                    }
                    else{
                        cout << ".";
                    }
                }
            }
        }
        cout << "\n";
    }

    return 0;
}

