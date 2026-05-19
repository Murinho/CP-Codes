#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fst first
#define snd second
#define nl '\n'

using namespace std;

const ll maxn = 2e5+100;

ll n,deg[maxn],m,ans=0;
vi g[maxn];

bool simulate2(int stnode){ // win in both scenarios
    fore(i,0,2){
        int otnode = g[stnode][i]; // blocked node.
        int node = g[stnode][(i+1)%2]; // other chosen node.
        int free = 0;
        bool win = false;
        for(auto &signode : g[node]){
            if (signode == stnode || signode == otnode) continue;
            free++;
            if (free >= 2){
                win = true;
                break;
            }
        }

        if (!win) return false;
    }
    return true;
}

bool simulate3(int stnode){
    fore(i,0,3){
        int otnode = g[stnode][i];
        int node1 = g[stnode][(i+1)%3];
        int node2 = g[stnode][(i+2)%3];
        bool win = false;
        
        for(auto &signode : g[node1]){
            if (signode == stnode || signode == node2 || signode == otnode) continue;
            win = true;
            break;
        }
        for(auto &signode : g[node2]){
            if (signode == stnode || signode == node1 || signode == otnode) continue;
            win = true;
            break;
        }

        if (!win) return false;
    }
    return true;
}

int main(){
    fast;
    cin >> n >> m;
    fore(i,0,m){
        ll x,y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        g[x].pb(y);
        g[y].pb(x);
    }

    fore(i,1,n+1){
        if (deg[i] >= 4) ans++;
        else if (deg[i] == 3){
            if (simulate3(i)) ans++;
        }
        else if (deg[i] == 2){
            if (simulate2(i)) ans++;
        }
    }

    cout << ans << nl;
    return 0;
}