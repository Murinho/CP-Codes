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
#define pb push_back

using namespace std;

const ll inf = 1e9+7;

string s;
set <pii> st;
ll min_x, min_y;
ll max_x, max_y;
ll cur_x, cur_y;
ll ori;
int mov[4][2] = {{0,1},{-1,0},{0,-1},{1,0}}; // right, up, left, down.

void init(){
    min_x = min_y = inf;
    max_x = max_y = -inf;
    ori = 0;
    st.clear();
    cur_x = 0;
    cur_y = 0;
}

void record(){
    min_x = min(min_x,cur_x);
    min_y = min(min_y,cur_y);
    max_x = max(max_x,cur_x);
    max_y = max(max_y,cur_y);

    st.insert({cur_x,cur_y});
}

void solve(){
    cin >> s;
    init();
    
    for(auto &c : s){
        if (c == 'R'){
            ori = (ori-1+4)%4;
        }
        else if (c == 'L'){
            ori = (ori+1)%4;
        }
        else if (c == 'B'){
            ori = (ori+2)%4;
        }
        if (ori == 0) cur_y++;
        else if (ori == 1) cur_x--;
        else if (ori == 2) cur_y--;
        else if (ori == 3) cur_x++;

        record();
    }

    // Reconstruct
    int n = (max_x - min_x) + 3;
    int m = max_y + 2;
    cout << n << " " << m << nl;

    for(int i = min_x - 1; i <= max_x + 1; i++){
        for(int j = min_y; j <= max_y + 1; j++){
            if (st.count({i,j})) cout << ".";
            else cout << "#";
        }
        cout << nl;
    }
    return;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    cout << tc << nl;
    while(tc--){
        solve();
    }
    return 0;
}