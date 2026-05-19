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
#define pii pair<int,int>
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const int maxn = 1e5+10;
const int inf = 1e9+7;

int n,k,ans;
map <int,int> mf,ms;

int ask(char c, int x){
	if (c == 'F' && mf.count(x)) return mf[x];
	else if (c == 'S' && ms.count(x)) return ms[x];
	
	cout << c << " " << x << nl;
	cout.flush();
	
	int ret;
	cin >> ret;
	
	if (c == 'F') mf[x]=ret;
	else if (c == 'S') ms[x]=ret;
	
	return ret;
}

void respond(){
	cout << "! " << ans << nl;
	cout.flush();
	return;
}

int main(){
    fast;
    cin >> n >> k;

    mf[0] = ms[0] = inf;
    mf[n+1] = ms[n+1] = 0;

    int l = max(k-n,0);
    int r = min(k,n);
	// cout << "Search: " << l << " " << r << nl;
    ans = -1;
    while(l < r){
    	int mid = (l+r)/2;
    	int fi = ask('F',mid);
    	int fi2 = ask('F',mid+1);
    	
    	int ot = k-mid;
    	
    	int sw = ask('S',ot);
    	int sw2 = ask('S',ot+1);
    	
    	vector <pii> v = {{fi,0},{fi2,1},{sw,2},{sw2,3}};
    	sort(ALL(v));
		reverse(ALL(v));
    	
    	if ((v[0].s == 0 && v[1].s == 2) || (v[0].s == 2 && v[1].s == 0)){
    		l = r;
    		ans = v[1].f;
    	}
    	else if (v[1].s == 1){ // fi, fi2, sw, sw2
    		l = mid+1;
    	}
    	else if (v[1].s == 3){ // sw, sw2, fi, fi2
    		r = mid-1;
    	}
    }
    
    if (ans == -1){
    	int fi = ask('F',l);
    	int sw = ask('S',k-l);
    	ans = min(fi,sw);
    }
    
    respond();
    
    return 0;
}