// Problem: K. Kitchen Waste
// Contest: Codeforces - 2020-2021 ICPC - Gran Premio de Mexico - Repechaje
// URL: https://codeforces.com/gym/102966/problem/K
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

ll n,m,ans,posa,posb;
vector <ll> a,b;
 
void init(){
    a.clear();
    a.resize(n);
    b.clear();
    b.resize(m);
    ans = posa = posb = 0;
}
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    init();
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<m; i++) cin>>b[i];
 
    while(posa < n && posb < n){
        if (a[posa] <= b[posb]){
            b[posb] -= a[posa];
            posa++;
        }
        else{
            ans += b[posb];
            b[posb] = 0;
            posb++;
        }
    }
    for (int i = 0; i<m; i++) ans += b[i];
    cout<<ans<<"\n";
    return 0;
}   