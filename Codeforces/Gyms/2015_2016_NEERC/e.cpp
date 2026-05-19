#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

using namespace std;

string s;

int main(){
    fast;
    freopen("easy.in", "r", stdin);  
    freopen("easy.out", "w", stdout);
    cin >> s;
    bool add=true;
    char las = '+';
    for(auto &c : s){
        if (c == '-'){
            add=false;
            cout << c;
        }
        else if (c == '+'){
            add=true;
            cout << c;
        }
        else{
            if (add) cout << c;
            else{
                if (las == '-') cout << c;
                else if (c == '0') cout << "+" << c;
                else{
                    cout << "+" << c;
                    add = true;
                }
            }
        }
        las = c;
    }
    cout << nl;
    return 0;
}