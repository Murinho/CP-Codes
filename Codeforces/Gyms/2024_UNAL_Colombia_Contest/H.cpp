// Problem: H. Emblems
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/H
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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

string getRank(ll x){
	if (x <= 1199) return "newbie";
	else if (x <= 1399) return "pupil";
	else if (x <= 1599) return "specialist";
	else if (x <= 1899) return "expert";
	else if (x <= 2099) return "candidate master";
	else if (x <= 2399) return "master";
	return "grandmaster";
}

int main(){
    fast;
	ll a,b,x;
	string s;
	cin>>s>>a>>b>>x;
	if (a+x <= b){
		cout<<"Think about it, you can do it!"<<nl;
		return 0;
	}
	string r1 = getRank(b);
	string r2 = getRank(a + x);
	if (r1 == r2) cout<<"Think about it, you can do it!"<<nl;
	else cout<<r2<<nl;
	return 0;
}