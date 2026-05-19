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
#define RB(x) (x<n?r[x]:0)
 
using namespace std;

const ll maxn = 1e5+10;
const ll M = 1e9+7;
const ll B = 131;

string s;
ll pws[maxn],h[maxn],tams,e[maxn];

// SUFFIX ARRAY

void csort(vi& sa, vi& r, int k){
	int n=sa.size();
	vi f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vi constructSA(){ // O(n log n)
	int n=s.size(),rank;
	vi sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}

// HASHING

ll conv(char c){ return (c-'$'+1); }
bool sameHash(int l1, int len1, int l2, int len2){
	int r1 = l1 + len1;
	int r2 = l2 + len2;
	if (sz(s) < max(r1,r2)) return false;
	
	ll h1 = (h[r1]-h[l1]*pws[len1]%M + M)%M;
	ll h2 = (h[r2]-h[l2]*pws[len2]%M + M)%M;
	return h1 == h2;
}
void precalc(){
	s = "$" + s; // just in case, to avoid conflicts
	tams = sz(s);
	pws[0] = 1;
	fore(i,1,maxn) pws[i] = (pws[i-1]*B)%M; 
	h[0] = conv(s[0]);
	fore(i,0,tams) h[i+1] = ((h[i]*B)+conv(s[i]))%M;
}

// PROBLEM SOLVING

int main(){
    fast;
    ll k;
	cin >> s;
	cin >> k;
	precalc();
	
	vi sa = constructSA();
	
	ll cure = 0; // current elevation.
	fore(i,1,sz(sa)){
		cure += e[i];
		while(cure < sz(s)-sa[i]){
			int l = i;
			int r = sz(sa)-1;
			while(l < r){
				ll mid = (l+r+1)/2;
				if (sameHash(sa[i],cure+1,sa[mid],cure+1)) l = mid;
				else r = mid-1;
			}
			
			// once gotten the range with common height (prefix), check if we can raise it more to speed up runtime
			int ini = cure+1;
			int fin = sz(s);
			while(ini < fin){
				ll mid = (ini+fin+1)/2;
				if (sameHash(sa[i],mid,sa[l],mid)) ini = mid;
				else fin = mid-1;
			}
			
			ll add_elev = ini-cure;
			ll totnew = add_elev * (l-i+1);
			
			if (totnew >= k){ // the answer is in this new block
				string res = "";
				fore(j,0,cure) res += s[sa[i] + j];
				
				int pos = cure;
				while(k > 0){
					k -= (l-i+1);
					res += s[sa[i] + pos];
					pos++;
				}
				
				cout << res << nl;
				return 0;
			}
			k -= totnew;
			
			cure += add_elev;
			e[l+1] -= add_elev;
			
			if (l == i) break;
		}
	}
	return 0;
}