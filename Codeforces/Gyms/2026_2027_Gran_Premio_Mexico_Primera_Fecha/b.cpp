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

bool is_number(string t){
	if (t.front() == '0') return false;
	for(auto &elm : t){
		if ('0' > elm || elm > '9') return false;
	}
	return true;
}

bool pten(string t){
	if (t[0] != '1') return false;
	fore(i,1,sz(t)){
		if (t[i] != '0') return false;
	}
	return true;
}

// void print_ascii(){
	// fore(i,40,200){
		// cout << i << ": " << (char)i << nl;
 	// }
// }

int main(){
    fast;
    ll n;
    cin >> n;
    // print_ascii();
    string s;
    cin.ignore();
    fore(i,0,n){
	    	getline(cin,s);
	    	int cnt = 0;
	    	
	    	int pos = 0;
	    	while(pos < sz(s)){
	    		string t = "";
	    		while(pos < sz(s) && s[pos] != ' ') t += s[pos], pos++;
	    	
		    	if (sz(t) >= 5 && is_number(t)){
		    		if (pten(t)){
		    			string tt = "";
		    			tt = "10^{";
		    			ll x = sz(t)-1;
		    			string aux = to_string(x);
		    			tt += aux;
		    			tt += "}";
		    			t = tt;
		    		}
		    		else{
		    			int amou = 0;
		    			int posi = sz(t)-1;
		    			while(posi >= 0 && t[posi] == '0') amou++, posi--;
		    			
		    			if (amou >= 4){
		    				int tam = sz(t)-1;
		    				string tt = "";
		    				tt += t[0];
		    				if (posi > 0) tt += ".";
		    				fore(i,1,posi+1) tt += t[i];
		    				
		    				char aux = 92;
		    				
		    				tt += aux;
		    				
		    				tt += "cdot10^{";
		    				string aux2 = to_string(tam);
		    				tt += aux2;
		    				tt += "}";
		    				
		    				t = tt;
		    			}
		    		}
		    	}
		    	
		    	if (cnt > 0) cout << " ";
		    	
		    	cout << t;
		    	cnt++;
		    	pos++;
		    	
		    	while(pos < sz(s) && s[pos] == ' ') pos++;
	    	}
	    	cout << nl;
    }
    return 0;
}