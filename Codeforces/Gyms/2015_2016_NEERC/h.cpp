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

const ll maxn = 1000;
ll k;

string s;

void init(){
    fore(i,0,maxn) s += "a";
}

ll getpow(ll k){
    ll ret = 1;
    fore(i,0,k) ret *= 31;
    return ret;
}

ll gethash(){
    ll ret = 0;
    fore(i,0,sz(s)){
        ll aux = getpow(sz(s)-i-1) * (int)(s[i]);
        ret += aux;
    }
    return ret;
}

int main(){
    fast;
    freopen("hash.in", "r", stdin);  
    freopen("hash.out", "w", stdout);
    init();
    cin >> k;
    for(int i = 0; i<maxn && k > 0; i += 2, k--){
        //cout << s << " h: " << gethash() << nl;
        cout << s << nl;
        s[i]++, s[i+1]++;
        s[i+1] = toupper(s[i+1]);
    }
    for(int i = 0; i<maxn && k > 0; i += 2, k--){
        cout << s << nl;
        s[i]--, s[i+1]--;
        s[i+1] = tolower(s[i+1]);
    }
    return 0;
}