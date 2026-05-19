// Problem: I. d-parkour
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/I
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

const ll maxn = 1e6+100;

ll n,p[maxn],ans,amou;
string a,b;

void init(){
	a = "$", b = "$";
}

bool valid(int pos){
	if (a[pos] != b[pos] && a[pos-1] != b[pos-1] && a[pos-1] == b[pos] && b[pos-1] == a[pos]) return true;
	return false;
}


int main(){
    fast;
	cin>>n;
	fore(i,1,n+1) cin>>p[i];
	
	//Compute the string a:
	fore(i,2,n+1){
		if (p[i-1] < p[i]) a += "U";
		else a += "D";
	}
	//Compute the string b:
	fore(i,2,n+1){
		if (p[i-1] < p[i]) b += "D";
		else b += "U";
	}
	
	//Compute for the evens:
	amou = 0;
	for(int i = 2; i<sz(a); i+= 2){
		if (valid(i)){
			if (!valid(i-1)){
				amou=0;
			}
			amou++;
			ans += amou;
		}
		else amou = 0;
	}
	//Compute for the odds:
	amou = 0;
	for(int i = 3; i<sz(a); i += 2){
		if (valid(i)){
			if (!valid(i-1)){
				amou=0;
			}
			amou++;
			ans += amou;
		}
		else amou = 0;
	}
	cout<<ans + n<<nl;
	return 0;
}