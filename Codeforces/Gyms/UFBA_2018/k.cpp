#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const int maxn = 1e5;
ll sum[maxn];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N; cin >> N;
    for (int i = 0; i < N; i++) cin >> sum[i];
    for (int i = 1; i < maxn; i++) sum[i] += sum[i-1];

    for (int i = 0; i < N; i++) {
        ll ans = 0;
        for (ll j = i, k = 1; j < N; j += 3*k, k++) {
            ll nex = min(N, j + 3*k -1);
            ll x = sum[nex]; 
            if (j > 0) x-= sum[j-1]; 
            if (x > 0) ans += x;
        }
        cout << ans << '\n';
    }
}