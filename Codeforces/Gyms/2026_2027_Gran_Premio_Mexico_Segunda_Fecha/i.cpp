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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

// simple implementation.
// check the statement carefully to review rules.

set <char> st,bad;
string ss = "!?.,;$#^{}_=+*";
string bs = "_^{}";
bool ok = true;

void precalc(){
	for(auto &c : ss){ // special symbols
		st.insert(c);
	}
	for(char c = 'a'; c <= 'z'; c++){ // lower case
		st.insert(c);
	}
	for(char c = 'A'; c <= 'Z'; c++){ // upper case
		st.insert(c);
	}
	for(char c = '0'; c <= '9'; c++){ // digits
		st.insert(c);
	}
	st.insert(' '); // add space char as valid too
	
	for(auto &c : bs){
		bad.insert(c);
	}
}

bool spaceCheck(string &s){
	if (s.front() == ' ' || s.back() == ' ') return false;
	
	fore(i,1,sz(s)){
		if (s[i-1] == ' ' && s[i] == ' ') return false;
	}
	return true;
}

bool validCharsCheck(string &s){
	for(auto &c : s){
		if (!st.count(c)) return false;
	}
	return true;
}

bool isValidNumber(string &s){
	if (sz(s) == 0) return false;
	
	if (sz(s) == 1) return true;
	
	if (s.front() == '0') return false;
	
	for(auto &c : s){
		if ('0' > c || c > '9') return false;
	}
	
	return true;
}

bool isSubscript(string &s){
	bool clo = false, op = false, sp = false;
	
	if (s.back() != '}') return false;
	
	string t = "";
	
	for(int i = sz(s)-1; i>=0; i--){
		if (s[i] == '}'){
			if (clo || op || sp) return false;
			
			clo = true;
		}
		else if (s[i] == '{'){
			if (!clo || op || sp) return false;
			
			op = true;
		}
		else if (s[i] == '^' || s[i] == '_'){
			if (!clo || !op || sp) return false;
			
			if (sz(t)){
				 reverse(ALL(t));
				 // cout << "the number: " << t << nl;
			}
			
			if (!isValidNumber(t)) return false;
			
			sp = true;
		}
		else if ('0' <= s[i] && s[i] <= '9'){
			if (!clo) return false;
			t += s[i];
		}
		else if ('a' <= s[i] && s[i] <= 'z'){
			if (!clo || !op || !sp) return false;
		}
		else if ('A' <= s[i] && s[i] <= 'Z'){
			if (!clo || !op || !sp) return false;
		}
		else{ // is a special character
			return false;
		}
	}
	
	if (clo && op && sp) return true;
	return false;
}

bool validWord(string &s){
	for(auto &c : s){
		if (bad.count(c)) return false;
	}
	return true;
}

bool solve(){
	string s;
	getline(cin,s);
	if (!spaceCheck(s)){
		// cout << "space check" << nl;
		return false;
	}
	else if (!validCharsCheck(s)){
		// cout << "valid chars check" << nl;
		return false;
	}
	
	string word = "";
	for(int i = 0; i<sz(s); i++){
		if (s[i] == ' '){
			// cout << "word: " << word << nl;
			if (!isSubscript(word)){
				if (!validWord(word)){
					// cout << "Not valid word" << nl;
					return false;
				}
			}
			word = "";
		}
		else{
			word += s[i];
		}
	}
	// cout << "word: " << word << nl;
	if (!isSubscript(word)){
		if (!validWord(word)){
			// cout << "Not valid word" << nl;
			return false;
		}
	}
	return true;
}

int main(){
	fast;
	precalc();
	ll tc;
	cin>>tc;
	cin.ignore();
	fore(i,1,tc+1){
		if(!solve()){
			// cout << i << ": failed" << nl;
	    		ok = false;
	    }
	}
    
    if (ok) cout << "Ok" << nl;
    else cout << "Validation failed" << nl;
    
    return 0;
}