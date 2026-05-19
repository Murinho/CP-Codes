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
 
ll n;
i128 ans=0;

void print_int128(__int128 x) {
    if (x == 0) {
        cout << "0";
        return;
    }

    if (x < 0) {
        cout << "-";
        x = -x;
    }

    string s;
    while (x > 0) {
        s.pb('0' + x % 10);
        x /= 10;
    }
    reverse(ALL(s));
    cout << s;
}
 
void process(vi &a){
	sort(ALL(a));
	
	i128 sum = 0;
	i128 cnt = 0;
	fore(i,0,n){
		ll pos = i;
		while(pos < n && a[pos] == a[i]) pos++;
		
		i128 ap = (-a[i]);
		i128 add = sum - (cnt * ap);
		add *= (pos-i);
		ans += add;
		
		sum += (ap*(pos-i));
		cnt += (pos-i);
		i = pos-1;
	}
}
 
int main(){
	fast;
	cin >> n;
	vi a(n), b(n);
	fore(i,0,n) cin >> a[i] >> b[i];
	
	process(a);
	process(b);
	
	print_int128(ans);
	return 0;
}