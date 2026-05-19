// Problem: L. Strobogrammatic
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

bool eq(char c, char d){
	if (c == '0' && d == '0') return true;
	else if (c == '1' && d == '1') return true;
	else if (c == '2' && d == '2') return true;
	else if (c == '5' && d == '5') return true;
	else if (c == '3' && d == 'E') return true;
	else if (c == '6' && d == '9') return true;
	else if (c == '8' && d == '8') return true;
	return false;
}

bool toOne(char c){
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '5' || c == '6' || c == '8' || c == '9' || c == 'E') return true;
	return false;
}

int main(){
    fast;
	string s;
	cin>>s;
	int n = sz(s);
	int l = 0;
	int r = n-1;
	int ans = 0;
	while(l < r){
		if (!eq(s[l],s[r]) && !eq(s[r],s[l])){
			if (toOne(s[l]) || toOne(s[r])) ans++;
			else ans += 2;
		}
		l++, r--;
	}
	if (l == r){
		if (!eq(s[l],s[l])) ans++;
	}
	cout<<ans<<nl;
	return 0;
}