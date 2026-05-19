#include<bits/stdc++.h>
#define nl '\n'
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define ALL(a) a.begin(), a.end()
#define vi vector<ll>
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define sz(a) ((ll)a.size())
using namespace std;
const int M=1e9+7;

const ll maxn = 1e5+100;
const ll alpha = 26;

ll n,res[maxn];

string ask(string &s){
    string res;
    cout << "? " << s << nl;
    cout.flush();
    cin >> res;
    return res;
}

void respond(){
    cout << "! ";
    fore(i,0,n) cout << res[i] << " ";
    cout << nl;
    cout.flush();
    return;
}

ll getpow(ll x, ll y){
    ll ret = 1;
    fore(i,0,y) ret *= x;
    return ret;
}

string build_string(ll bs){
    string s = "";

    char c = 'a';
    ll cnt = 0;
    while(sz(s) < n){
        s += c;
        cnt++;
        if (cnt == bs){
            cnt = 0;
            if (c == 'z') c = 'a';
            else c++;
        }
    }
    return s;
}

string a[4];

int main(){
    fast;
    cin >> n;
    for(ll i = 3; i>=0; i--){
        ll pw = getpow(alpha,i);
        string aux = build_string(pw);
        a[i] = ask(aux);
    }

    fore(i,0,n){
        ll ans = 0;
        for(ll j=3; j >= 0; j--){
            ll cval = (a[j][i] - 'a');

            ll aux = cval * getpow(alpha,j);

            ans += aux;
        }
        res[ans] = i+1;
    }
    respond();
    return 0;
}