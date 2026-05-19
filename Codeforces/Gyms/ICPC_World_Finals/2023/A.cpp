// Problem: A. Riddle of the Sphinx
// Contest: Codeforces - 2023 ICPC World Finals
// URL: https://codeforces.com/gym/105255/problem/A
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
 
using namespace std;

int main(){
	int a, b, c, d, e;
	cout << "1 0 0" << nl; cin >> a;
  	cout << "0 1 0" << nl; cin >> b;
  	cout << "0 0 1" << nl; cin >> c;
  	cout << "1 1 1" << nl; cin >> d;
  	cout << "1 2 3" << nl; cin >> e;
  	if (a+b+c == d) cout << a << ' ' << b << ' ' << c << nl;
  	else if (a+2*b+3*c == e) cout << a << ' ' << b << ' ' << c << nl;
  	else if ((d-b-c)+2*b+3*c == e) cout << d-b-c << ' ' << b << ' ' << c << nl;
  	else if (a+2*(d-c-a)+3*c == e) cout << a << ' ' << d-c-a << ' ' << c << nl;
  	else cout << a << ' ' << b << ' ' << d-a-b << nl;
  	
  	return 0;
}