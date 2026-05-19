// Problem: B. Missing LDAP
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/B
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
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

int res;
string s,nom,ape,ape2;

string bs(){
	ll l = 2;
	ll r = sz(nom);
	while(l < r){
		ll mid = (l+r)/2;
		string aux = "";
		fore(i,0,mid) aux += nom[i];
		aux += ape;
		fore(i,0,min(mid,sz(ape2))) aux += ape2[i];
		cout<<aux<<nl;
		cout.flush();
		cin>>res;
		if (res == 0) r = mid;
		else l = mid+1;
	}
	string aux = "";
	fore(i,0,r) aux += nom[i];
	return aux;
}

int main(){
    //fast;
	vector <string> a;
	getline(cin,s);
	string t;
	for(auto au : s){
		if (au == ' '){
			a.pb(t);
			t = "";
		}
		else t += au;
	}
	if (sz(t)>0) a.pb(t);
	if (sz(a) == 4){ //tiene segundo nombre.
		nom = a[0];
		ape = a[1][0];
		ape += a[2];
		ape2 = a[3];
	}
	else{
		nom = a[0];
		ape = a[1];
		ape2 = a[2];
	}
	string inis = "";
	inis += nom[0];
	inis += ape;
	inis += ape2[0];
	cout<<inis<<nl;
	cout.flush();
	cin>>res;
	if (res == 0){
		cout<<"! "<<inis<<nl;
		cout.flush();
		return 0;
	}
	//Else do binary search:
	string pref = bs();
	string npref = pref;
	pref += ape;
	ll l = 0;
	ll r = min(sz(npref),sz(ape2));
	if (r == sz(nom)) r = sz(ape2);
	
	while(l < r){
		ll mid = (l+r)/2;
		string aux = pref;
		fore(i,0,mid) aux += ape2[i];
		cout<<aux<<nl;
		cout.flush();
		cin>>res;
		if (res == 0) r = mid;
		else l = mid+1;
	}
	fore(i,0,l) pref += ape2[i];
	cout<<"! "<<pref<<nl;
	cout.flush();
	return 0;
}