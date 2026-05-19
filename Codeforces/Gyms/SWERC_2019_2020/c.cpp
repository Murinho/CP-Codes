#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define vi vector<ll>
#define vvi vector<vi>

using namespace std;

set <ll> st;

ll f(string &s){
    ll x = stoi(s);
    return x;
}

int main(){
    fast;
    ll n;
    cin >> n;
    fore(i,0,n){
        string s;
        cin >> s;
        if (sz(s) <= 8 && s[0] != '-'){
            st.insert(f(s));
        }
    }
    fore(i,0,n+2){
        if (!st.count(i)){
            cout << i << nl;
            break;
        }
    }
    return 0;
}