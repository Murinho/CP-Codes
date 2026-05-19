// Problem: J. Joint Jinx
// Contest: Codeforces - CPUlm Winter Contest 2022
// URL: https://codeforces.com/gym/104149/problem/J
// Memory Limit: 512 MB
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

using namespace std;

const ll rad = 100;
const ll sep = 8;

struct Circle{
	ll x,y,r;
};

ll n,k;
bool ok=true;
vector <Circle> a;

ll ints(ll x, ll y, ll r){
	ll cnt = 0;
	for(auto &[cx,cy,cr] : a){
		if (abs(cx-x) < 2*rad) cnt += 2;
		else if (abs(cx-x) == 2*rad) cnt++;
	}
	return cnt;
}

void solve(){
	cin >> n >> k;
	if (k > n*(n-1)){
		cout<<"impossible"<<nl;
		return;
	}
	ll have = 0;
	ll add = 2;
	ll cnt = 1;
	a.pb({0,0,rad});
	while(cnt < n){
		if (have + add > k) break;
		cnt++;
		a.pb({(cnt-1)*sep,0,rad});
		have += add;
		add += 2;
	}
	if (cnt < n){
		cnt++;
		rofe(i,1000,0){
			if (ints(i,0,rad) == k-have){
				a.pb({i,0,rad});
				break;
			}
		}
	}
	int x = 1000;
	int y = 1000;
	while(cnt < n){
		cnt++;
		a.pb({x,y,1});
		x -= 2, y -= 2;
	}
	for(auto &[x,y,r] : a) cout<<x<<" "<<y<<" "<<r<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}