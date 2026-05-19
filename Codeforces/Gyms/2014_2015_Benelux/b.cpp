#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

using namespace std;

const ll maxn = 20;
const ll inf = 1e9+7;
const ll maxk = 3605;
ll n,k,a[maxn],dp[maxk];

void init(){
    fore(i,0,maxk) dp[i] = inf;
}

void bfs(){
    queue <ll> q;
    q.push(0);
    dp[0] = 0;
    while(sz(q)){
        ll node = q.front();
        q.pop();
        fore(i,0,n){
            ll signode = node + a[i];
            signode = max(signode,0ll);
            signode = min(signode,3600ll);
            if (dp[signode] == inf){
                dp[signode] = dp[node] + 1;
                q.push(signode);
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    init();
    fore(i,0,n) cin >> a[i];

    bfs();

    fore(i,k,maxk){
        if (dp[i] != inf){
            cout << dp[i] << " " << i-k << nl;
            break;
        }
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