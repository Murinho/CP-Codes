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

struct Query{
	char c;
	int l,r;
};

struct Fen{ // keep the sum of the sells in the fenwick
	vi fen;
	ll n;
	Fen(int n): fen(n + 5,0), n(n) {}
    // Sum of values. (1-indexed).
    void add(ll x, ll v){
        while (x <= n){
            fen[x] += v;
            x += lsb(x);
        }
    }
    // Getting to whole prefix [1,x]
    ll get(ll x){ 
        ll freq = 0;
        while (x > 0){
            freq += fen[x];
            x -= lsb(x);
        }
        return freq;
    }
};
 
const int maxn = 2e5+5;
const int mxfen = 6e5+15;
Query q[maxn];
int a[maxn],n,qrs;
vi uni;

int main(){
	fast;
	cin>>n>>qrs;
	for (int i = 1; i<=n; i++){
		cin>>a[i];
		uni.pb(a[i]);
	}
	fore(i,0,qrs){
		cin>>q[i].c>>q[i].l>>q[i].r;
		uni.pb(q[i].r);
		if (q[i].c == '?') uni.pb(q[i].l);
	}
	
	sort(ALL(uni));
	uni.erase(unique(ALL(uni)),uni.end());
	
	int k = sz(uni);
	Fen fen(k+1);
	
	fore(i,1,n+1){
		 a[i] = lower_bound(ALL(uni), a[i]) - uni.begin() + 1;
		 fen.add(a[i],1);
	}
	fore(i,0,qrs){
		if (q[i].c == '?') q[i].l = lower_bound(ALL(uni), q[i].l) - uni.begin() + 1;
		q[i].r = lower_bound(ALL(uni), q[i].r) - uni.begin() + 1;
		
		if (q[i].c == '!'){
			fen.add(a[q[i].l],-1);
			a[q[i].l] = q[i].r;
			fen.add(a[q[i].l], +1);
		}
		else{
			ll ans = fen.get(q[i].r);
			if (q[i].l > 1) ans -= fen.get(q[i].l - 1);
			cout<<ans<<nl;
		}
	}
	return 0;
}