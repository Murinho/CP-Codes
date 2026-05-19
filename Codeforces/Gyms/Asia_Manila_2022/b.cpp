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

const ll maxn = 1e7+5;

vi p;
bool c[maxn];

void sieve(){
    c[1] = true;
    fore(i,2,maxn){
        if (!c[i]){
            p.pb(i);
            for(int j = 2; i*j<maxn; j++) c[i*j] = true;
        }
    }
}

int main(){
    fast;
    sieve();

    ll sum = 0;
    fore(i,0,2000) sum += p[i];

    cout << sum << nl;
    cout << "last prime: " << p[1999] << nl;
    return 0;
}