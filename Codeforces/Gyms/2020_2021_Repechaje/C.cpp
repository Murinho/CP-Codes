// Problem: C. CLETS Patrols
// Contest: Codeforces - 2020-2021 ICPC - Gran Premio de Mexico - Repechaje
// URL: https://codeforces.com/gym/102966/problem/C
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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


void solve(){
	int n, m;
    cin >> n >> m;
 
    vector<vector<double>> p(n, vector<double>(n));
    vector<vector<double>> ex(2, vector<double>(n, 0));
 
    ex[1][0] = 1;
    int mx = min(m, 1200000000/(m*m));
    int x = 0;
 
 
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> p[i][j];
 
 
    for(int s=0; s<mx; s++){
        x = s&1;
        for(int i=0; i<n; i++) ex[x][i] = 0.0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ex[x][j] += p[i][j]*ex[(x+1)&1][i];
            }
        }
 
    }
 
    cout << fixed << setprecision(5);
 
    for(int i=0; i<n; i++){
        cout << ex[x][i] << '\n';
    }
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}