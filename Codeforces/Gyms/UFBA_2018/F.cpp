#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const int maxn = 1e5;

// if (N-i < L) break;
ll sum[maxn];
ll vl[maxn];
ll in[maxn];
ll N;
ll L, R;
bool check(ll k) {
    queue<ll> q;
    for (int i = 0; i < N; i++) {
        if (in[i] >= k) vl[i] = 1;
        else vl[i] = 0;

        if (vl[i]) q.push(i);
        sum[i] = 0;
    }
    ll s = 1;
    if (N > 1) sum[1] = -1;
    for (int i = 0; N-i >= L; i++) {
        s += sum[i];
        if (s == 0) continue;
        while((!q.empty()) && q.front() < i) q.pop();
        if (q.empty()) continue;
        if (q.front() - i + 1> R) continue;
        //cout << i << ' ' << s << endl;
        ll l = (max(q.front() + 1, i+L));
        ll r = i + R + 1;

        if (N >= l && N < r) return true;
        if (l < N) sum[l]++;
        if (r < N) sum[r]--;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) cin >> in[i];
    ll ans = 0;
    ll dis = 1e9;
    while (dis > 0) {
        if (ans + dis <= 1e9 && check(ans+dis)) ans+=dis;
        else dis/=2;
    }
    //cout << check(22) << endl;
    cout << ans << '\n';
}