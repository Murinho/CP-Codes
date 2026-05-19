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

const ll maxn = 1e6+100;
const ll alpha = 27;

ll c[alpha],occ[alpha],f[alpha],lf[maxn];
string s;
ll n;

int getid(char x){
	if (x == '#') return 0;
	return (int)x-'a'+1;
}

char fromid(int x){
	if (x == 0) return '#';
	return (char)(x-1)+'a';
}

int main(){
    fast;
    
    cin >> s;
    n = sz(s);
    
    // get the freqs of the chars:
    for(auto &au : s){
    	f[getid(au)]++;
    }
    
    // do the prefix sums of chars
    fore(i,1,alpha) c[i] = c[i-1] + f[i-1];
    
    // compute the lf for each position:
    fore(i,0,n){
    	int x = getid(s[i]);
    	int k = occ[x]++;
    	lf[i] = c[x] + k;
    }
    
    // fore(i,0,n){
    	// cout << i << " " << lf[i] << nl;
    // }
    
    // find the '#' char
    int cur = -1;
    fore(i,0,n){
    	if (s[i] == '#'){
    		cur = i;
    		break;
    	}
    }
    
    string ans = "";
    fore(i,1,n+1){
		cur = lf[cur];
		ans += s[cur];
    }
    ans.ppb();
    reverse(ALL(ans));
    cout << ans << nl;
    return 0;
}