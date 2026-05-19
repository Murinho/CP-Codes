// Problem: M. Multiple Downloads
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/M
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
 
using namespace std;

const ld eps = 1e-5;
ll n;
double t,curt=0.0;

void sub_mb(double rem_mb, vector<double> &p){
	rofe(i,sz(p),0){
		p[i] -= rem_mb;
		if (p[i] <= eps) p.ppb();
	}
}

int main(){
    fast;
    vector <double> p,np;
   	cin>>n>>t;
   	char c;
   	double x;
   	fore(i,0,n){
   		cin>>c>>x;
   		if (c == 'P') p.eb(x);
   		else np.eb(x);
   	}
   	
   	sort(ALL(p)), reverse(ALL(p));
   	sort(ALL(np)), reverse(ALL(np));
   	
   	double smp,sub_p,finp,smnp,sub_np,finnp,sub_time;
   	
   	double p_rate = (t/4.0)*3.0;
   	double np_rate = (t/4.0);
   	
   	while(sz(p) && sz(np)){
   		// ver quien termina primero.
   		smp = p.back();
   		sub_p = p_rate/(double)sz(p); //cuanto voy a restar a cada elemento de p por segundo.
   		finp = smp/sub_p;
   		
   		smnp = np.back();
   		sub_np = np_rate/(double)sz(np); // cuanto voy a restar a cada elemento de np por segundo.
   		finnp = smnp/sub_np;
   		
   		sub_time = min(finp,finnp);
   		
   		sub_mb(sub_time*sub_p,p);
   		sub_mb(sub_time*sub_np,np);
   		
   		curt += sub_time;
   		//cout<<fixed<<setprecision(3)<<curt<<nl;
   		//for(auto &elm : p) cout<<"P: "<<elm<<nl;
   		//for(auto &elm : np) cout<<"NP: "<<elm<<nl;
   	}
   	if (!sz(p) && sz(np)) swap(p,np);
   	while(sz(p)){
   		ld sm = p.back();
   		ld sub_p = t/(ld)sz(p); // cuanto voy a restar a cada elemento de p por segundo.
   		ld sub_time = sm/sub_p;
   		
   		sub_mb(sub_time*sub_p,p);
   		
   		curt += sub_time;
   	}
   	cout<<fixed<<setprecision(9)<<curt<<nl;
   	return 0;
}