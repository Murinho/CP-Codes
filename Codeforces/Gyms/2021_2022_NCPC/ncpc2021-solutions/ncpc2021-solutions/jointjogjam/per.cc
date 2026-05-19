#include <bits/stdc++.h>
using namespace std;

int sqr(int x) { return x*x; }
int main(void) {
    double ans = 0;
    for (int i = 0; i < 2; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = max(ans, sqrt(sqr(x1-x2) + sqr(y1-y2)));
    }
    cout << setprecision(9) << ans << endl;
}
