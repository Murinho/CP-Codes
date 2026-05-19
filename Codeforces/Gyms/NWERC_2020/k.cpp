#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pb push_back
#define vi vector <ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()

using namespace std;

const ll maxn = 10005;

ll a[maxn],b[maxn];

string s,t;

int main(){
    fast;
    getline(cin,s);
    getline(cin,t);

    ll cnt = 1;
    ll gc = 0;
    fore(i,1,sz(s)){
        if (s[i-1] != s[i]){
            a[gc] = cnt;
            cnt = 0;
            gc++;
        }
        cnt++;
    }
    a[gc] = cnt;

    //cout << "A" << gc << nl;

    cnt = 1;
    gc = 0;
    fore(i,1,sz(t)){
        if (t[i-1] != t[i]){
            b[gc] = cnt;
            cnt = 0;
            gc++;
        }
        cnt++;
    }
    b[gc] = cnt;

    //cout << "B" << gc << nl;
 
    set <char> st;
    for(auto &c : s) st.insert(c);

    cnt = 1;
    gc = 0;
    fore(i,1,sz(s)){
        if (s[i-1] != s[i]){
            if (a[gc] == b[gc]) st.erase(s[i-1]);
            cnt = 0;
            gc++;
        }
        cnt++;
    }
    a[gc] = cnt;
    if (a[gc] == b[gc]) st.erase(s.back());

    //cout << sz(st) << nl;
    for(auto &elm : st) cout << elm;
    cout << nl;
    return 0;
}