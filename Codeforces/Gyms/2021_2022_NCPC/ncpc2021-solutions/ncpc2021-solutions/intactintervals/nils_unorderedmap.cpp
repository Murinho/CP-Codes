#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAXN = 1000001;
const ll mod = 1000000007;
const ll mod2 = 1000000009;
int n;

vi X,Y;
unordered_map<int,int> compress;
int nums_seen = 0;
ll two_pow[MAXN] = {0};
ll n_pow1[MAXN] = {0};
ll n_pow2[MAXN] = {0};

unordered_map<ll,int> hash_freq;
vector<ll> hashes_seen;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(c1,0,n){
        int a;
        cin >> a;
        if(compress.find(a) == compress.end()){
            compress[a] = nums_seen;
            nums_seen++;
        }
        X.push_back(compress[a]);
    }
    rep(c1,0,n){
        int a;
        cin >> a;
        Y.push_back(compress[a]);
    }
    ll t = 1;
    ll t1 = 1;
    ll t2 = 1;
    rep(c1,0,MAXN){
        two_pow[c1] = t;
        t *= 2;
        t %= mod;
        n_pow1[c1] = t1;
        t1 *= ll(MAXN);
        t1 %= mod;
        n_pow2[c1] = t2;
        t2 *= ll(MAXN);
        t2 %= mod2;
    }

    ll h1 = 0;
    ll h2 = 0;

    rep(c1,0,n){
        ll h = h1*mod2 + h2;
        if(hash_freq.find(h) == hash_freq.end()){
            hash_freq[h] = 0;
            hashes_seen.push_back(h);
        }
        hash_freq[h]++;
        ll h1_diff = (n_pow1[X[c1]] + mod - n_pow1[Y[c1]]) % mod;
        h1 += h1_diff;
        h1 %= mod;
        ll h2_diff = (n_pow2[X[c1]] + mod2 - n_pow2[Y[c1]]) % mod2;
        h2 += h2_diff;
        h2 %= mod2;
    }

    ll ans = 0;
    trav(h, hashes_seen){
        ans += two_pow[hash_freq[h]] - hash_freq[h] - 1 + mod;
        ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}

