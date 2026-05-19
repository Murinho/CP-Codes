#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll bin_exp(ll a, ll x) {
    ll ans = 1;
    while (x) {
        if (x%2) ans = (ans * a)%mod;
        x/=2;
        a = (a*a)%mod;
    }
    return ans;
}

void solve() {
    ll N; cin >> N;
    cout << (((bin_exp(2,N)*(N%mod))%mod + 3 + N - bin_exp(2,N) - bin_exp(2,N+1))%mod + mod)%mod << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) solve();
}
