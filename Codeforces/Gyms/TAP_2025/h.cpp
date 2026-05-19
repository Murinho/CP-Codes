#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ppb pop_back
#define ALL(a) a.begin(),a.end()
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define vi vector<ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+10;
const ll inf = 1e18;
const ll maxi = 1e9;

ll n;
vi a;

void init(){
    a.clear(), a.resize(n);
}

bool isPrime(ll x){
    if (x == 1) return false;

    ll sq = sqrt(x);
    fore(i,2,sq+1){
        if (x%i == 0) return false;
    }
    return true;
}

bool safe(ll x, ll y){
    if (x <= inf/y) return true;
    return false;
}

int main(){
    fast;
    cin >> n;
    init();
    fore(i,0,n) cin >> a[i];

    sort(ALL(a));

    if (a[0] != 1){ // ARREGLADO
        cout << a[n-1] << " " << 1 << nl;
    }
    else if (n == 1){ // ARREGLADO
        cout << "*" << nl;
    }
    else if (n == 2){ // ARREGLADO
        ll cnt = 0;
        ll x = 0; // hidden number
        ll y = 0; // missing divisor

        // checar si a[n-1] tiene raiz exacta
        ll sq = sqrt(a[n-1]);
        if (sq*sq == a[n-1]){
            cnt++;
            x = a[n-1];
            y = sq;
        }

        // checar is a[n-1] is primo
        if (a[n-1] <= maxi && isPrime(a[n-1])){
            cnt++;
            x = a[n-1]*a[n-1];
            y = a[n-1]*a[n-1];
        }

        if (cnt >= 2) cout << "*" << nl;
        else cout << x << " " << y << nl;
    }
    else if (n == 3){ // ARREGLADO
        ll x = 0, y = 0;
        ll cnt = 0;
        if (a[2]%a[1] == 0 && a[2]/a[1] != a[1]){
            cnt++;
            x = a[2];
            y = a[2]/a[1];
        }
        else{
            cnt++;
            x = a[1]*a[2];
            y = a[1]*a[2];
        }
        if (cnt >= 2) cout << "*" << nl;
        else cout << x << " " << y << nl;
    }
    else if (n == 4){
        set <ll> st;
        for(auto &elm : a) st.insert(elm);

        ll x=0,y=0;
        if (a[1]*a[1] == a[3]){
            x = a[3];
            y = a[3]/a[2];
        }
        else if (a[2]*a[2] == a[3]){
            x = a[3];
            y = a[3]/a[1];
        }
        else if (sqrt(a[3])*sqrt(a[3]) == a[3] && !st.count(sqrt(a[3]))){
            x = a[3];
            y = sqrt(a[3]);
        }
        else{ // falta el numero mas grande.
            x = a[2]*a[2];
            y = a[2]*a[2];
        }
        cout << x << " " << y << nl;
    }
    else{ // n >= 5
        ll x = 0, y = 0, cnt = 0;
        set <ll> st;
        for(auto &elm : a) st.insert(elm);

        if (a[0]*a[n-1] == a[1]*a[n-3] && a[n-1]%a[n-2] == 0 && !st.count(a[n-1]/a[n-2])){ // case 1
            x = a[n-1];
            y = a[n-1]/a[n-2];
            cnt++;
        }
        if (a[0]*a[n-1] == a[2]*a[n-2] && a[n-1]%a[1] == 0 && !st.count(a[n-1]/a[1])){ // case 2
            x = a[n-1];
            y = a[n-1]/a[1];
            cnt++;
        }
        if (a[0]*a[n-1] == a[1]*a[n-2]){ // case 3
            x = a[n-1];
            bool ok = false;
            for(auto &elm : a){
                ll ot = x/elm;
                if (!st.count(ot)){
                    y = ot;
                    cnt++;
                    ok = true;
                    break;
                }
            }
            if (!ok) y = sqrt(a[n-1]);
        }
        
        ll px = a[1]*a[n-1];
        bool ok = true;
        for(auto &elm : st){
            if (elm == 1) continue; // omitir el 1.

            if (px%elm > 0){
                ok = false;
                break;
            }
            if (!st.count(px/elm)){
                ok = false;
                break;
            }
        }

        if (ok){
            cnt++;
            x = px;
            y = px;
        }
        
        if (cnt >= 2) cout << "*" << nl;
        else cout << x << " " << y << nl;
    }
    return 0;
}