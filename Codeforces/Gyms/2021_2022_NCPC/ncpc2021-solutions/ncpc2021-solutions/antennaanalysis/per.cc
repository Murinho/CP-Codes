#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll add(map<ll, ll> &hist, ll i, ll xi) {
    auto it = hist.lower_bound(xi);
    if (it != hist.end() && it->second >= i+xi)
        return it->second;
    hist[xi] = i+xi;
    it = hist.find(xi);
    while (it != hist.begin()) {
        --it;
        if (it->second <= i+xi)
            hist.erase(it++);
        else
            break;
    }
    return i+xi;
}

int main(void) {
    ll n, c;
    scanf("%lld%lld", &n, &c);
    map<ll, ll> plus, minus;
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        printf("%lld\n", max(add(plus, i*c, x) - x - i*c, add(minus, i*c, -x) + x - i*c));
    }
}
