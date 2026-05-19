// Problem: A. El Camino del Robot Humanoide
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/A
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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;


int main(){
    fast;
    ll n;
    string s;
    cin >> n;
    cin >> s;
    
    int cnt = 0;
    for(auto &elm : s){
    	if (elm == 'L') cnt--;
    	else if (elm == 'R') cnt++;
    	
    }
    
    if (cnt == 0) cout << "Linea Recta" << nl;
    else if (cnt > 0) cout << "Derecha" << nl;
    else cout << "Izquierda" << nl;
    
    return 0;

} 