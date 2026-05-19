// Problem: I. Cristales Mágicos
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/I
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const ll maxn = 1e6+100;

map <string,ll> mp;
ll n,k,tam=0;
bool mk[maxn];

struct Cry{
	ll val,pos,color;
};

vector <Cry> a;

bool cmp(Cry &c1, Cry &c2){
	if (c1.val == c2.val) return c1.pos < c2.pos;
	return c1.val > c2.val;
}

int main(){
    fast;
    cin >> n >> k;
    fore(i,1,n+1){
    	string s;
    	cin >> s;
    	ll x;
    	cin >> x;
    	if (!mp.count(s)) mp[s] = ++tam;
    	
    	Cry c;
    	c.val = x;
    	c.pos = i;
    	c.color = mp[s];
    	
    	a.pb(c);
    }
    
    sort(ALL(a),cmp);
    
    if (tam < k){
    	cout << "IMPOSIBLE" << nl;
    	return 0;
    }
    
    vi res;
    ll ans = 0;
    for(auto &elm : a){
    	if (!mk[elm.color] && sz(res) < k){
    		mk[elm.color] = true;
    		ans += elm.val;
    		res.pb(elm.pos);
    	}
    }
    
    sort(ALL(res));
    
    cout << ans << nl;
    for(auto &elm : res) cout << elm << " ";
    cout << nl;
    
    return 0;
}