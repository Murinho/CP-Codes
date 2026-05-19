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

int main() {

    double xs1, ys1, xs2, ys2;
    double xe1, ye1, xe2, ye2;
    cin >> xs1 >> ys1 >> xs2 >> ys2 >> xe1 >> ye1 >> xe2 >> ye2;
    double ans1 = sqrt((xs1-xs2)*(xs1-xs2) + (ys1-ys2)*(ys1-ys2));
    double ans2 = sqrt((xe1-xe2)*(xe1-xe2) + (ye1-ye2)*(ye1-ye2));

    cout << setprecision(18) << max(ans1, ans2) << "\n";

    return 0;
}

