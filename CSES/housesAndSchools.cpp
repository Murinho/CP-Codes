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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;
 
const ll INF = 1e18+7;
 
struct Line{
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>>{ // For Max values
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	// For Min values use: cht.add(-k,-m) and -cht.query(x);
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p > y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
 
int main(){
    fast;
    int N, M;
	cin >> N >> M;
	vector<long long> A(N + 1, 0);
	for (int i = 1; i <= N; i++) cin >> A[i];
	vector<long long> sum(N + 1), pre(N + 1), suf(N + 1);
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + A[i];
		pre[i] = pre[i - 1] + A[i] * i;
		suf[i] = suf[i - 1] + A[i] * (N - i + 1);
	}
 
	vector<vector<long long>> dp0(M + 1, vector<long long>(N + 1, INF));
	vector<vector<long long>> dp1(M + 1, vector<long long>(N + 1, INF));
	
	dp1[0][0] = 0;
	fore(m,1,M+1){
		LineContainer md0, md1;
		md1.add(0,0);
		fore(i,1,N+1){
			dp0[m][i] =
			    -md1.query((i - 1) - N) + suf[i - 1] - (N - (i - 1)) * sum[i - 1];
			md0.add(i, -dp0[m][i] + pre[i] - i * sum[i]);
			dp1[m][i] = -md0.query(sum[i]) + pre[i];
			md1.add(sum[i], -dp1[m - 1][i] + suf[i]);
		}
	}
	
	cout << dp1[M][N] << nl;
	return 0;
}