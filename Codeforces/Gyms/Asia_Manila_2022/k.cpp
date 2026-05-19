#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ll long long
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define nl '\n'

using namespace std;

string s[3];
string a[3];

void init(){
    s[0] = "QWERTYUIOP";
    s[1] = "ASDFGHJKL";
    s[2] = "ZXCVBNM";
}

int main(){
    fast;
    init();
    fore(i,0,3) cin >> a[i];

    set <char> st;
    fore(i,0,3){
        fore(j,0,sz(a[i])){
            if (a[i][j] == '*'){
                st.insert(s[i][j]);
            }
        }
    }

    ll q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        bool ok = true;
        set <char> st2;
        for(auto &c : t){
            if (!st.count(c)){
                ok = false;
                break;
            }
            st2.insert(c);
        }
        if (ok && sz(st) == sz(st2)) cout << "POSSIBLE" << nl;
        else cout << "IMPOSSIBLE" << nl;
    }
    return 0;
}