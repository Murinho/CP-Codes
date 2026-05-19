// Problem: K. Kettle Kitten
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/K
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

const ld pi = acos(-1.0);

int main(){
    fast;
    ll n, v;
	cin >> n >> v;
	vector<ll> in(n);
	for (ll i = 0; i < n; i++) {
		ll h, r;
		cin >> h >> r;
		in[i] = h*r*r;
	}
	ll res = -1;
	for (ll i = 0; i < n; i++) {
		if (in[i]*pi >= v) {
			if (res < 0 || in[i] < in[res]) {
				res = i;
			}
		}
	}
	if (res < 0) {
		cout << "impossible" << endl;
	} else {
		cout << res+1 << endl;
	}
}