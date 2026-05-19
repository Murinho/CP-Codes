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

int main() {

    int n;
    cin >> n;
    vi A(n),B(n-1);
    rep(c1,0,n){
        cin >> A[c1];
    }
    rep(c1,0,n-1){
        cin >> B[c1];
    }
    sort(all(A));
    sort(all(B));
    int ans = A.back();
    rep(c1,0,n-1){
        if(A[c1] != B[c1]){
            ans = A[c1];
            break;
        }
    }
    cout << ans << "\n";

    return 0;
}

