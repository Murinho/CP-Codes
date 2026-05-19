#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())
#define ld long double

using namespace std;

const ll maxn = 1e7 + 1000;
const ld mult = 1e5;

bool c[maxn];
ll n;
vi p;

void sieve(){
    c[1]=true;
    for(int i = 2; i<maxn; i++){
        if (!c[i]){
            //p.pb(i);
            for(int j = 2; i*j < maxn; j++) c[i*j] = true;
        }
    }
    //int pos 
    //cout << p.back() << nl;
}

ll pow10(ll pw){
    ll x = 1;
    fore(i,0,pw) x *= 10ll;
    return x;
}

ll get_num(string s){
    int pos = sz(s);
    ll x = 0;
    fore(i,0,sz(s)){
        if (s[i] == '.'){
            pos = i;
        }
    }
    // check to the left of the decimal point:
    int ex = 5;
    for(int i = pos-1; i>=0; i--){
        ll val = (ll)(s[i]-'0');
        x += pow10(ex)*val;
        ex++;
    }
    ex = 4;
    for(int i = pos+1; i<sz(s); i++){
        ll val = (ll)(s[i]-'0');
        x += pow10(ex)*val;
        ex--;
    }
    return x;
}

int main(){ // Biggest prime: 9999991
    fast;
    sieve();

    cin >> n;
    while(n--){

        string s;
        ll x,y;

        cin >> s;
        x = get_num(s);

        cin >> s;
        y = get_num(s);

        //cout << "Nums: " << x << " " << y <<nl;
        ll g = __gcd(x,y);
        x /= g, y /= g;

        if (x == y){
            cout << 2 << " " << 2 << nl;
        }
        else if (!c[x] && !c[y]){
            cout << x << " " << y << nl;
        }
        else cout << "impossible" << nl;
    }
    return 0;
}