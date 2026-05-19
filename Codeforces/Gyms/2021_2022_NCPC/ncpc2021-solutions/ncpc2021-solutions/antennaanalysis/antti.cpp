#include <iostream>

using namespace std;
using ll = long long;

#define N (1<<20)
#define INF (1LL<<60)

ll p1[2*N], p2[2*N];

void set1(int k, ll x) {
    k += N;
    p1[k] = max(p1[k],x);
    for (k /= 2; k >= 1; k /= 2) {
        p1[k] = max(p1[2*k],p1[2*k+1]);
    }
}

void set2(int k, ll x) {
    k += N;
    p2[k] = min(p2[k],x);
    for (k /= 2; k >= 1; k /= 2) {
        p2[k] = min(p2[2*k],p2[2*k+1]);
    }
}

ll get1(int a, int b) {
    a += N; b += N;
    ll r = p1[a];
    while (a <= b) {
        if (a%2 == 1) r = max(r,p1[a++]);
        if (b%2 == 0) r = max(r,p1[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

ll get2(int a, int b) {
    a += N; b += N;
    ll r = p2[a];
    while (a <= b) {
        if (a%2 == 1) r = min(r,p2[a++]);
        if (b%2 == 0) r = min(r,p2[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

int main() {
    int n;
    ll c;
    cin >> n >> c;
    for (int i = 0; i < 2*N; i++) p1[i] = -INF;
    for (int i = 0; i < 2*N; i++) p2[i] = INF;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set1(x,x+i*c);
        set2(x,x-i*c);
        ll m1 = get1(x,1e6)-x-i*c;
        ll m2 = x-get2(0,x)-i*c;
        cout << max(m1,m2);
        if (i != n-1) cout << " ";
    }
    cout << "\n";
}
