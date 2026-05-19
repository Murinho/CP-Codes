#include<bits/stdc++.h>
#define nl '\n'
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define ALL(a) a.begin(), a.end()
#define vi vector<ll>
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
using namespace std;

const ll maxn = 1e5+100;

bool c[maxn],mk[maxn],mk2[maxn];
ll n,amou[maxn];

vi primes,res,dv;
vector <pii> values;

void init(){
    res.resize(n+1);
    dv.resize(n+1);
}

void sieve(){
    fore(i,2,n+1){
        if (!c[i]){
            primes.pb(i);
            for(int j = 2; i*j<=n; j++) c[i*j] = true;
        }
    }
}

void sieve2(){
    fore(i,2,n+1){
        if (!mk[i]){
            if (amou[i] == 0){
                for(int j = 1; i*j <= n; j++){
                    amou[i*j]++;
                    if (j%i == 0) mk[i*j] = true;
                }
            }
            values.pb({i,amou[i]});
        }
    }
}

void sieve3(){
    fore(i,2,n+1){
        if (!mk2[i]){
            for(int j = 2; i*j <= n; j++){
                if (dv[i*j] == 0 && dv[j] != 0){
                    dv[i*j] = (dv[j]*dv[i]);
                }
                mk2[i*j] = true;
            }
        }
    }
}

void ask(ll &x){
    cout << "? " << x << nl;
    cout.flush();
    cin >> dv[x];
    return;
}

void respond(){
    cout << "! ";
    fore(i,1,n+1){
        cout << i - res[i] << " ";
    }
    cout << nl;
    cout.flush();
    return;
}

int main(){
    fast;
    cin >> n;
    init();
    sieve();

    for(auto &primo : primes) ask(primo);

    sieve2();

    sieve3();

    /*
    cout << "Values: " << nl;
    for(auto &[num, tam] : values){
        cout << num << " " << tam << nl;
    }
    cout << nl; */

    for(auto &[num, tam] : values){
        for(ll j = 1; num*j <= n; j++){
            if (tam%2 == 1){
                res[j*num] += j*dv[num];
            }
            else{
                res[j*num] -= j*dv[num];
            }
        }
    }

    /*
    cout << "Res: " << nl;
    fore(i,1,n+1){
        cout << i << ": " << res[i] << nl;
    } */

    /*
    cout << "Dv: " << nl;
    fore(i,1,n+1){
        cout << i << ": " << dv[i] << nl;
    } */

    respond();

    return 0;
}