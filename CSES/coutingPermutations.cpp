#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned ll

static const ll MOD = 1e9+7;

ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    fast;

    int n;
    cin >> n;

    int N = n;              // factorial up to n
    int m = n - 1;          // number of forbidden edges

    // factorials + inverse factorials for binomials up to n (and m as well)
    vector<ll> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) invfact[i - 1] = invfact[i] * i % MOD;

    auto C = [&](int a, int b) -> ll {
        if (b < 0 || b > a) return 0LL;
        return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
    };

    // powers of 2 up to n
    vector<ll> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = (pow2[i - 1] * 2) % MOD;

    ll ans = fact[n]; // k=0 term

    for (int k = 1; k <= m; k++) {
        ll inner = 0;
        int maxc = min(k, m - k + 1);
        for (int c = 1; c <= maxc; c++) {
            // count subsets with k edges and c components:
            // C(k-1, c-1) * C(m-k+1, c)
            ll ways = C(k - 1, c - 1) * C(m - k + 1, c) % MOD;
            inner = (inner + pow2[c] * ways) % MOD;
        }

        ll term = fact[n - k] * inner % MOD;
        if (k & 1) ans = (ans - term) % MOD;
        else       ans = (ans + term) % MOD;
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << nl;
    return 0;
}
