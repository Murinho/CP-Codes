// O(n*x) time
#include <bits/stdc++.h>
using namespace std;

int SubsetSum(vector<int> &X, int t) {
    // O(|X|*B), based on "Linear Time Algorithms for Knapsack Problems
    // with Bounded Weights" by David Pisinger
    int B = *max_element(X.begin(), X.end());
    int n = X.size();
    vector<int> MaxPref(2*B+1, -1);
    int s = 0, brk;
    for (brk = 0; brk < n && s + X[brk] <= t; ++brk)
        s += X[brk];
    MaxPref[s-(t-B)] = brk;
    vector<int> Prev(B+1, -1);
    for (int i = brk; i < n; ++i) {
        s += X[i];
        for (int d = 0; d <= B; ++d)
            Prev[d] = max(0, MaxPref[d+B]);
        for (int d = B; d >= 0; --d)
            MaxPref[d+X[i]] = max(MaxPref[d+X[i]], MaxPref[d]);
        for (int d = 2*B; d > B; --d)
            for (int j = Prev[d-B]; j < MaxPref[d]; ++j)
                MaxPref[d-X[j]] = max(MaxPref[d-X[j]], j);
    }
    for (int i = 0; i <= B; ++i)
        if (MaxPref[B-i] >= 0)
            return max(t-i, s-(t-i));
}

int main(void) {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> T(n);
    for (int &t: T) scanf("%d", &t);
    sort(T.begin(), T.end());
    int max_T = T.back();
    while (!T.empty() && T.back() > x) T.pop_back();
    int ans;
    if (T.size() > 4) {
        vector<int> Jobs;
        int tot = 0;
        for (int i = 4; i < T.size(); ++i) {
            Jobs.push_back(x+1-T[i]);
            tot += Jobs.back();
        }
        ans = x+1 + SubsetSum(Jobs, tot/2);
    } else if (T.size() > 2) {
        ans = x+1;
    } else
        ans = max_T;
    printf("%d\n", max(max_T, ans));
}
 
