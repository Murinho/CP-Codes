#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int n;
vector<double> X,Y,R;
vector<bool> kind;
vector<double> y_interval;
vector<int> ind;

bool comp(int i, int j){
    return y_interval[i] < y_interval[j];
}

double intersect(double x){
    kind.clear();
    y_interval.clear();
    ind.clear();
    for(int c1 = 0; c1 < n; c1++){
        double D = R[c1]*R[c1] - (X[c1] - x) * (X[c1] - x);
        if(D > 0){
            double y = Y[c1] - sqrt(D);
            kind.push_back(1);
            y_interval.push_back(y);
            ind.push_back(sz(ind));
            y = Y[c1] + sqrt(D);
            kind.push_back(0);
            y_interval.push_back(y);
            ind.push_back(sz(ind));
        }
    }
    sort(all(ind), comp);
    double res = 0.0;
    int open_intervals = 0;
    double prev = -123;
    trav(i, ind){
        double y = y_interval[i];
        if(open_intervals > 0)res += y - prev;
        if(kind[i] == 1)open_intervals++;
        if(kind[i] == 0)open_intervals--;
        prev = y;
    }
    return res;
}

int main() {

    cin >> n;
    rep(c1,0,n){
        int x,y,r;
        cin >> x >> y >> r;
        X.push_back(x);
        Y.push_back(y);
        R.push_back(r);
    }

    double L = -20.0;
    double R = 20.0;
    int stops = 1000000;
    double dx = (R-L) / double(stops);

    double ans = 0.0;
    double prev = 0.0;
    for(int i = 1; i <= stops; i++){
        double x = L + dx*double(i);
        double f = intersect(x);
        ans += (f + prev) * dx / 2.0;
        prev = f;
    }

    cout << setprecision(9) << ans << "\n";

    return 0;
}

