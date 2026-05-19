#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll oo = 1LL<<60;

ll best_alloc(ll M, ll L1, ll S1, ll L2, ll S2) {
    /* maximize x*S1 + y*S2
     * subject to
     *   x + 2*y = M,    0 <= x <= L1,   0 <= y <= L2,   x, y integers
     */
    if (M < 0 || L1 + 2*L2 < M || (M % 2 and L1 == 0))
        return -oo;
    ll x, y;
    if (S2 > 2*S1) {
        y = min(L2, M/2);
        x = M - 2*y;
    } else {
        x = min(L1, M);
        x -= (x ^ M) & 1;
        y = (M-x) / 2;
    }
    return x*S1 + y*S2;
}

ll ans;

ll solve0(vector<ll> X, vector<ll> L, vector<ll> R, ll M) {    
    int n = X.size() - 1;
    vector<ll> Lsum(n+1), Rsum(n+1);
    for (int i = 0; i < n; ++i) {
        Lsum[i+1] = Lsum[i] + L[i]*(X[i+1]-X[i]);
        Rsum[i+1] = Rsum[i] + R[i]*(X[i+1]-X[i]);
    }
    vector<vector<ll>> Score(n+1, vector<ll>(n+1));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            Score[i][j] = i < j ? Rsum[j]-Rsum[i] : Lsum[i] - Lsum[j];
    
    // no turns
    for (int i = 0; i <= n; ++i) 
        for (int j = 0; j <= n; ++j) {
            if (X[j] - X[i] == M)
                ans = max(ans, Score[i][j]);
            if (X[j] - X[i] >= M)
                break;
            if (j < n && X[j+1] - X[i] > M)
                ans = max(ans, Score[i][j] + (M - (X[j]-X[i]))*R[j]);
        }

    // one turn
    for (int i1 = 0; i1 < n; ++i1)
        for (int i2 = i1; i2 <= n; ++i2) {
            ll rem0 = M - (X[i2]-X[i1]);
            if (rem0 < 0) break;
            ll x2room = i2 < n ? X[i2+1]-X[i2] : 0;
            ll x2score = i2 < n ? R[i2] + L[i2] : 0;
            ll score0 = Score[i1][i2];
            if (i2 < n && rem0 <= 2*x2room) {
                ll x = R[i2] >= L[i2] ? min(rem0, x2room) : (rem0+1)/2;
                ans = max(ans, score0 + x*R[i2] + (rem0-x)*L[i2]);
            }
            for (int i3 = i2; i3 >= 0; --i3) {
                ll rem = rem0 - (X[i2]-X[i3]);
                if (rem < 0) break;
                ll score = score0 + Score[i2][i3];
                ll x3room = i3 ? X[i3]-X[i3-1] : 0;
                ll x3score = i3 ? L[i3-1] : 0;
                ans = max(ans, score + best_alloc(rem, x3room, x3score, x2room, x2score));
            }
        }
    
    // two turns
    for (int i1 = 0; i1 < n; ++i1)
        for (int i2 = i1; i2 <= n && X[i2]-X[i1] <= M; ++i2) {
            ll x2room = i2 < n ? X[i2+1] - X[i2] : 0;
            if (2*(X[i2]+x2room) < M) continue;
            ll x2score = i2 < n ? L[i2] + R[i2] : 0;
            for (int i3 = i1; i3 >= 0; --i3) {
                ll rem0 = M - ((X[i2] - X[i1]) + (X[i2] - X[i3]));
                if (rem0 < 0) break;
                ll x3room = i3 ? X[i3] - X[i3-1] : 0;
                ll x3score = i3 ? L[i3-1] + R[i3-1] : 0;
                if (Score[max(0, i3-1)][min(n, i2 + 1)] + Score[min(n, i2+1)][max(0, i3-1)] < ans) continue;
                if (rem0 > 2*max(x2room, x3room) + X[i1]-X[i3]) continue;
                ll score0 = Score[i1][i2] + Score[i2][i3];
                if (i3 && rem0 <= 2*x3room) {
                    ll x = L[i3-1] >= R[i3-1] ? min(rem0, x3room) : (rem0+1)/2;
                    ans = max(ans, score0 + x*L[i3-1] + (rem0-x)*R[i3-1]);
                }
                for (int i4 = i3; i4 <= i1; ++i4) {
                    ll rem = rem0 - (X[i4] - X[i3]);
                    if (rem < 0) break;
                    ll score = score0 + Score[i3][i4];
                    ll x4room = i4 < i1 ? X[i4+1] - X[i4] : 0;
                    ll x4score = R[i4];
                    ans = max(ans, score + max(best_alloc(rem, x4room, x4score, x3room, x3score),
                                               best_alloc(rem, x4room, x4score, x2room, x2score)));
                }
            }
        }
    return ans;   
}

ll solve(vector<ll> X, vector<ll> L, vector<ll> R, ll M) {
    ans = 0;
    solve0(X, L, R, M);
    solve0(X, R, L, M);
    
    ll mX = X.back();
    reverse(X.begin(), X.end());
    for (auto &x: X) x = mX - x;
    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());
    
    solve0(X, L, R, M);
    solve0(X, R, L, M);
    return ans;
}

struct ival {
    ll l, r, v;
    ival(ll l=0, ll r=0, ll v=0): l(l), r(r), v(v) {}
    bool operator<(const ival &I) const { return l < I.l; }
};

int main(void) {
    ll m, x, n;
    scanf("%lld%lld%lld", &m, &x, &n);
    set<ll> Xset;
    Xset.insert(0);
    Xset.insert(m);
    vector<ival> LI, RI;
    for (int i = 0; i < n; ++i) {
        ll l, r, v;
        scanf("%lld%lld%lld", &l, &r, &v);
        Xset.insert(l);
        Xset.insert(r);
        if (l < r) RI.push_back(ival(l, r, v));
        else LI.push_back(ival(r, l, v));
    }
    sort(LI.begin(), LI.end());
    sort(RI.begin(), RI.end());
    vector<ll> X(Xset.begin(), Xset.end());
    vector<ll> L, R;
    int Li = 0, Ri = 0;
    for (int i = 0; i < X.size()-1; ++i) {
        while (Li < LI.size() && LI[Li].r <= X[i]) ++Li;
        L.push_back(Li < LI.size() && LI[Li].l <= X[i] ? LI[Li].v : 0);
        while (Ri < RI.size() && RI[Ri].r <= X[i]) ++Ri;
        R.push_back(Ri < RI.size() && RI[Ri].l <= X[i] ? RI[Ri].v : 0);
    }
    printf("%lld\n", solve(X, L, R, x));
}
