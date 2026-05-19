#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll int
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
 
using namespace std;

const int maxn = 3e3 + 10;
const int maxa = 26;
const int segundo = 1e8;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
int a[maxn][maxn];
bool fl[maxn];
vi v[maxa][maxn];
ll n,m;

int main() {
	srand(time(0));
    fast;
	cin >> n >> m;
	fore(i,1,n+1){
		cin >> s;
		fore(j,1,n+1){
			a[i][j] = s[j-1]-'A';
			v[a[i][j]][i].eb(j);
		}
	}
	vi b;
	fore(i,0,m){
		b.clear();
		
		fore(j,1,n+1){
			if (sz(v[i][j]) >= 2){
				b.eb(j);
			}
		}
		
		int ops = segundo/m/10;
		shuffle(ALL(b), rng);
		
		for(int jx = 0, j = b[jx], cnt = 0; jx < sz(b); jx++, j = b[jx]){
			for(int kx = jx+1, k = b[kx]; kx < sz(b); kx++, k = b[kx]){
				cnt = 0;
				if (sz(v[i][j]) < sz(v[i][k])){
					for(auto &x : v[i][j]){
						cnt += (a[k][x] == i);
					}
				}
				else{
					for(auto &x : v[i][k]){
						cnt += (a[j][x] == i);
					}
				}
				if (cnt >= 2){
					fl[i] = true;
					break;
				}
				ops--;
				if (ops == 0) break;
			}
			if (fl[i]) break;
			if (ops == 0) break;
		}
		cout << (fl[i]?"YES":"NO") << nl;
	}
    
    return 0;
}