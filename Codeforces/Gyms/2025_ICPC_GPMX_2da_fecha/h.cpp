#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e4+5;
const ll inf = 1e9+7;

ll n,h,k,x[maxn],y[maxn],z[maxn],dp[maxn],stx,sty,ans=inf;
vi g[maxn];

void init(){
	fore(i,0,n+1) dp[i] = inf;
}

ll sq(ll x){
	return x*x;
}

void bfs(){
    queue <ll> q;
   	fore(i,1,n+1){
   		if (x[i] == stx && y[i] == sty){
   			q.push(i);
   			dp[i] = 0;
   		}
   	}

    while(sz(q)){
        ll i = q.front();
        q.pop();

        fore(j,1,n+1){
        	if (dp[j] != inf) continue;
        	
        	int flag = 0;
			flag |= z[i] && sq(x[i] - x[j]) + sq(y[i] - y[j]) <= h*h;
			flag |= z[j] && sq(x[i] - x[j]) + sq(y[i] - y[j]) <= k*k;
			if (flag){
				dp[j] = dp[i] + 1;
				q.push(j);
			}
        }
    }
}	


int main(){
    fast;
    cin >> n >> h >> k;
    init();
    fore(i,1,n+1){
        cin >> x[i] >> y[i] >> z[i];
    }
    
    // Find the initial node.
    cin >> stx >> sty;
	
    // bfs:
    bfs();
    
    ans = dp[0];
    fore(i,1,n+1){
    	if (dp[i] != inf && abs(y[i]) <= h){
    		if (z[i] || y[i] == 0){
    			ans = min(ans, dp[i] + (y[i] == 0 ? 0 : 1));
    		}
    	}
    }
    
    if (ans >= inf) cout << -1 << nl;
    else cout << ans << nl;
    
    return 0;
}