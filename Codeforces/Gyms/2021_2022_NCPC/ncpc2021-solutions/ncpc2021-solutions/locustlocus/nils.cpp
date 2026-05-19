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

int gcd(int i, int j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main() {

    int n;
    cin >> n;
    int ans = 999999;
    rep(c1,0,n){
        int y,a,b;
        cin >> y >> a >> b;
        int lcm = (a*b) / gcd(a, b);
        ans = min(ans, y + lcm);
    }
    cout << ans << "\n";

    return 0;
}

