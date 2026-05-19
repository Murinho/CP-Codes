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
#define fore(i,a,b) for(int i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <int>
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

const int maxn = 1e6+5;
string a,b;
ll ans,n;
vi d1,d2,d3,d4;
int where[maxn][2];
int add[maxn];

void clean(){
	fore(i,0,n+1){
		add[i] = 0;
	}
}

void init(){
	n = sz(a);
	ans = 0;
	d1.resize(n);
	d2.resize(n);
	d3.resize(n);
	d4.resize(n);
}

//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s, vi &d1, vi &d2){
	int l=0,r=-1;
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}

void doit(bool flag){
	manacher(a,d1,d2);
	manacher(b,d3,d4);
	
	clean();
	
	// fore(i,0,n) cout << d1[i];
	// cout << nl;
	// fore(i,0,n) cout << d2[i];
	// cout << nl;
	
	fore(i,0,n-1){
		// check the odds:
		{
			int mn = min(d1[i],d3[i]);
			int fin = i+mn-1;
			add[fin+1]++;
			add[i]--;
		}
		{ // check the evens:
			int mn = min(d2[i],d4[i]);
			if (mn == 0) continue;
			
			int fin = i+mn-1;
			add[fin+1]++;
			add[i]--;
		}
	}
	
	int l = 0;
	int r = n-1;
	int cnt = add[n];
	while(r >= 0 && a[l] == b[r] && b[l] == a[r]){
		if (flag) ans++;
		
		cnt += add[r];
		
		ans += cnt;
		
		l++, r--;
	}
}

void solve(){
	cin >> a;
	cin >> b;
	
	init();
	
	doit(true);
	
	reverse(ALL(a));
	reverse(ALL(b));
	
	doit(false);
	
	cout << ans << nl;
}

int main(){
    fast;
    ll tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}