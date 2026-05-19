// Problem: B. Boring Non-Palindrome
// Contest: Codeforces - 2019 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/102307/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const ll maxn = 1e5+100;

bool check(string &t){
	int l = 0;
	int r = sz(t)-1;
	while(l < r){
		if (t[l] != t[r]) return false;
		l++, r--;
	}
	return true;
}

int main(){
    fast;
	string s;
	cin>>s;
	int n = sz(s);
	fore(i,0,n){
		string t = s;
		for(int j = i-1; j>=0; j--) t += s[j];
		if (check(t)){
			cout<<t<<nl;
			break;
		}
	}
	return 0;
}