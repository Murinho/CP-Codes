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
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)

using namespace std;

const int maxn = 26;
int n;
int a[maxn][maxn],b[maxn][maxn];
int color[maxn],par[maxn],deg[maxn];
int dp[maxn];
vi cycle;
int rev=0; // reverse input

void init(){
    fore(i,0,maxn){
        fore(j,0,maxn) a[i][j] = b[i][j] = (1-rev);
        color[i] = dp[i] = deg[i] = 0;
    }
    cycle.clear(), cycle.resize(0);
}

char getch(int i){
    return (char)(i+'a');
}

void dfs(int u, int p){
    if (color[u] == 2) return;
    if (color[u] == 1){
        if (!sz(cycle)){
            int cur = p;
            cycle.pb(cur);
            while(cur != u){
                cur = par[cur];
                cycle.pb(cur);
            }
            reverse(ALL(cycle));
        }
        return;
    }
    par[u] = p;
    color[u] = 1;
    fore(i,0,maxn){
        if (a[u][i]) dfs(i,u);
    }
    color[u] = 2;
}

void bigprint(string s){
    fore(i,0,20){
        int pos = i%sz(s);
        fore(j,0,20){
            cout << s[pos];
            pos = (pos+1)%sz(s);
        }
        cout << nl;
    }
    return;
}

void bfs(){
    queue <int> q;
    fore(i,0,maxn){
        if (!deg[i]){
            q.push(i);
            dp[i] = 1;
        }
    }

    while(sz(q)){
        ll node = q.front();
        q.pop();

        //cout << "bfs: " << getch(node) << nl;
 
        fore(i,0,maxn){
            if (b[node][i]){
                deg[i]--;
                dp[i] = max(dp[i], dp[node] + 1);
                if (!deg[i]){
                    q.push(i);
                }
            }
        }
    }
}

void solve(){
    cin >> n;
    init();
    fore(i,0,n){
        char x,y;
        cin >> x >> y;
        int vx = (int)(x-'a');
        int vy = (int)(y-'a');
        a[vx][vy] = rev;
        b[vy][vx] = rev;
    }

    //cout << a[0][0] << nl;
    ///cout << a[0][1] << nl;

    // single letter patterns.
    fore(i,0,maxn){
        if (a[i][i]){
            string t = "";
            char c = (char)(i+'a');
            t += c;
            //cout << t << nl;
            bigprint(t);
            return;
        }
    }

    // search for cycles:
    fore(i,0,maxn){
        if (!color[i]) dfs(i,i);
    }

    if (sz(cycle)){
        string t = "";
        for(auto &elm : cycle){
            t += getch(elm);
        }
        bigprint(t);
        return;
    }

    // get the longest chain that can be obtained from each node.
    fore(i,0,maxn){
        fore(j,0,maxn){
            if (b[i][j]) deg[j]++;
        }
    }

    bfs(); // topo-bfs

    // search for the edge 4-node structure.
    ll best = 0;
    ll who = -1;
    fore(i,0,maxn){
        if (best < dp[i]){
            best = dp[i];
            who = i;
        }
    }

    vi path;
    int cur = who;
    path.pb(cur);
    while(dp[cur] > 1){
        fore(i,0,maxn){
            if (a[cur][i] && dp[i]+1 == dp[cur]){
                cur = i;
                path.pb(cur);
                break;
            }
        }
    }

    //cout << best << " " << who << nl;
    ll len = (best+1)/2;
    len = min(len,20ll);
    /*
    cout << len << nl;
    cout << who_i << " " << who_j << " " << who_k << nl;
    cout << "path: ";
    for(auto &elm : path) cout << elm << " ";
    cout << nl; */

    fore(i,0,len){
        int pos = i;
        int cnt = 0;
        while(cnt < len){
            cout << getch(path[pos]);
            pos++;
            cnt++;
        }
        cout << nl;
    }
    return;
}
 
int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}