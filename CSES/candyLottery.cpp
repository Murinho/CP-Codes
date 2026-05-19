#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    ld ans = (ld)k;

    for (ll i = 0; i <= k - 1; i++) {
        ld x = (long double)i / (long double)k;
        ans -= powl(x, (long double)n); // stable
    }

    // Print whatever you want >= 6 decimals; 9 is fine too.
    cout << fixed << setprecision(6) << ans << "\n";
}
