// Problem: L. Lets Count Factors
// Contest: Codeforces - 2020-2021 ICPC - Gran Premio de Mexico - Repechaje
// URL: https://codeforces.com/gym/102966/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace __gnu_pbds;
using namespace std;

vector<int> primes;
vector<bool> isp(3163, 1);
 
void cb(){
    isp[0] = 0;
    isp[1] = 0;
 
    for(int i=2; i<=3162; i++){
        if(!isp[i]) continue;
        primes.push_back(i);
        for(int j=2; j*i<=3162; j++){
            isp[i*j]=0;
        }
    }
}
 
int main(){
    fast;
 
    int n;
    cin >> n;
 
    cb();
 
    long long x, y;
    set<long long> facts;
 
    while(n--){
        facts.clear();
        cin >> x >> y;
        int i = 0;
        while(x > 1 && i < primes.size()){
            if(x%primes[i] == 0){
                facts.insert(primes[i]);
                while(x%primes[i] == 0)x/=primes[i];
            }
            i++;
        }
        if(x>1) facts.insert(x);
        i = 0;
        while(y > 1 && i < primes.size()){
            if(y%primes[i] == 0&& facts.find(y) == facts.end()){
                facts.insert(primes[i]);
                while(y%primes[i] == 0)y/=primes[i];
                
            }
            i++;
        }
        if(y > 1 && facts.find(y) == facts.end()) facts.insert(y);
        cout << facts.size() << '\n';
        //for(auto it: facts) cout << it << " ";
        //cout << '\n';
    }   
}