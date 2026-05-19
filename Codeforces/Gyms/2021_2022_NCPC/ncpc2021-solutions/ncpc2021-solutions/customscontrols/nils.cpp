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

const int MAXN = 100001;
const ll mod = 1000000007;
const ll mod2 = 1000000009;

vector<vi> graph(MAXN, vi());
vi W;

int main() {

    int n,m,k;
    cin >> n >> m >> k;
    rep(c1,0,n){
        int a;
        cin >> a;
        W.push_back(a);
    }
    bool special = 0;
    rep(c1,0,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if(min(a, b) == 0 && max(a, b) == n-1)special = 1;
    }

    bool swapped = 0;
    if(k < n-k){
        swapped = 1;
        k = n-k;
    }

    bool answer[MAXN] = {0};

    if(special){
        if(k == 1){
            cout << "ImPOSSIBLE\n";
            return 0;
        }
        else{
            answer[0] = 1;
            answer[n-1] = 1;
            rep(c1, 1, k-1){
                answer[c1] = 1;
            }
        }
    }
    else{
        vector<pii> neighbours;
        trav(y, graph[0]){
            neighbours.push_back({W[y], y});
        }
        sort(all(neighbours));
        answer[0] = 1;
        k--;
        trav(y, neighbours){
            if(k > 0){
                answer[y.second] = 1;
                k--;
            }
        }
        rep(c1,0,n){
            if(answer[c1] == 0 && k > 0){
                answer[c1] = 1;
                k--;
            }
        }
    }

    string sn = "SN";
    for(int c1 = 0; c1 < n; c1++){
        cout << sn[answer[c1]^swapped];
    }cout << "\n";

    return 0;
}

