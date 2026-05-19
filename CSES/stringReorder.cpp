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
 
using namespace __gnu_pbds;
using namespace std;

const ll alpha = 26;

int b[alpha];
string s;

int main(){
    fast;
	cin >> s;
	for(auto &i : s){
		int val = (int)(i-'A');
		b[val]++;
	}
	    
	int tam = sz(s);
	
	int tope = (tam/2) + (tam%2);
	
	// check if it possible to build the string:
	set <pii> mst; // occurences set.
	set <ll> st; // letters set.
	fore(i,0,alpha){
		if (b[i] > tope){
			cout << -1 << nl;
			return 0;
		}
		if (b[i] > 0){
			mst.insert({b[i],-i});
			st.insert(i);
		}
	}
	
	int pv = -1;
	string ans = "";
	
	fore(i,0,tam){
		tope = ((tam-i)/2) + ((tam-i)%2); // tope restante.
		pii p = *mst.rbegin();
		if (p.fst == tope && (tam-i)%2 == 1){
			if (-p.snd == pv){
				mst.erase(p);
				pii p2 = *mst.rbegin();
				mst.insert(p);
				p = p2;
			}
			
			//cout << i << ": (tope) " << -p.snd << nl;
			
			char c = (char)((-p.snd) + 'A');
			
			ans += c;
			
			mst.erase(p);
			b[-p.snd]--;
			if (b[-p.snd] == 0) st.erase(-p.snd);
			else mst.insert({b[-p.snd],p.snd});
			
			pv = -p.snd;
		}
		else{ // choose the smallest.
			int val = *st.begin();
			if (val == pv){
				st.erase(val);
				int val2 = *st.begin();
				st.insert(val);
				val = val2;
			}
			
			//cout << i << ": " << val << nl;
			char c = (char)(val + 'A');
			ans += c;
			
			mst.erase({b[val],-val});
			b[val]--;
			if (b[val] == 0) st.erase(val);
			else mst.insert({b[val],-val});
			
			pv = val;
		}
	}

	cout << ans << nl;
	return 0;
}