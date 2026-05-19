// Problem: L. LED Counter
// Contest: Codeforces - The 2025 ICPC Latin America Championship
// URL: https://codeforces.com/gym/105789/problem/L
// Memory Limit: 1024 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll n,m;
string t[10];

void init(){
	t[0] = "1110111";
	t[1] = "0000011";
	t[2] = "0111110";
	t[3] = "0011111";
	t[4] = "1001011";
	t[5] = "1011101";
	t[6] = "1111101";
	t[7] = "0010011";
	t[8] = "1111111";
	t[9] = "1011111";
}

bool check(string &s, string &t){
	fore(i,0,7){
		if (s[i] == '+' || s[i] == '-') continue;
		else if (s[i] == 'G'){
			if (t[i] == '0') return false;
		}
		else if (s[i] == 'g'){
			if (t[i] == '1') return false;
		}
	}
	return true;
}

int main(){
    fast;
    init();
    ll n;
    cin>>n;
    string s;
    fore(i,0,n){
    	cin>>s;
    	int cnt = 0;
    	int who = 0;
    	fore(j,0,10){
    		if (check(s,t[j])){
    			cnt++;
    			who = j;
    		}
    	}
    	if (cnt == 1) cout<<who;
    	else cout<<"*";
    }
    cout<<nl;
    return 0;
}