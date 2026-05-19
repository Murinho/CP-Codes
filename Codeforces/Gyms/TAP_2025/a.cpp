#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

int main(){
    fast;
    string s;
    cin >> s;
    string t = "TAP";
    int cnt = 0;
    for(auto &au : s){
        if (au == t[cnt]){
            cnt++;
            if (cnt == 3) break;
        }
    }

    if (cnt == 3) cout << "S" << nl;
    else cout << "N" << nl;

    return 0;
}