// Problem: D. Determine the Winner Marshaland
// Contest: Codeforces - 2020-2021 ICPC - Gran Premio de Mexico - Repechaje
// URL: https://codeforces.com/gym/102966/problem/D
// Memory Limit: 256 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
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
 
using namespace std;

const int maxn = 1e6+5;
vector<int> p;
vector <int> res[maxn];
int lp[maxn];
bool c[maxn];

void sieve_linear(){
    fore(i,2,maxn){
        if (!lp[i]){
            lp[i]=i;
            p.pb(i);
        }
        for (int j=0; j < sz(p) && p[j]<=lp[i] && i*p[j]<maxn; j++) {
            lp[i * p[j]] = p[j];
        }
    }
}

void solve(){
	int k;
    bool ok=false;
    cin>>k;
    for(auto &prime : p){
    	if (prime == 2) continue;
    	if (prime-2 > k) break;
    	
    	if ((k%prime) == prime-2){
    		if (ok) cout<<" ";
    		ok=true;
    		cout<<prime;
    	}
    }
   	if (!ok) cout<<-1;
   	cout<<nl;
    return;
}

int main(){ // primes: 78499
    sieve_linear();
    ll tc;
    cin>>tc;
    while(tc--){
    	solve();
    }
   	
}