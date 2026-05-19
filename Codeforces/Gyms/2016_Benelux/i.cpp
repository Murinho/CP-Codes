#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

const ll maxn = 32622;
const ll maxq = 1e9;

ll n;
vi p;
bool c[maxn];

void sieve(){
    fore(i,2,maxn){
        if (!c[i]){
            p.pb(i);
            for(int j = 2; i*j < maxn; j++) c[i*j]=true;
        }
    }
}

bool isprime(ll x){
    if (x == 1) return false;

    ll cnt = 0;

    for(auto &prime : p){
        while(x%prime == 0){
            x /= prime;
            cnt++;
        }
    }
    if (x>1) cnt++;

    return (cnt == 1);
}

int main(){
    fast;
    sieve();

    cin >> n;
    if (isprime(n)){
        cout << "yes" << nl;
        return 0;
    }
    else{
        for(auto &prime : p){
            ll x = prime;
            while(x < n){
                x *= prime;
            }
            if (x == n){
                cout << "yes" << nl;
                return 0;
            }
        }
    }
    cout << "no" << nl;
    return 0;
}