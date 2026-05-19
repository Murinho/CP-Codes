// Problem: M. Maximizing the Sauce
// Contest: Codeforces - 2024 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/105216/problem/M
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
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


//Formula para sacar el cono truncado:
//V = (1/3)*pi*h*(R^2 + Rr + r^2)
//R = base mayor
//r = base menor.

const ld eps = 1e-7;
ld lad,rad,ans;

ld f(ld h){
	return h*((3*rad*rad) + (sqrt((lad*lad) - (h*h))*(sqrt((lad*lad) - (h*h)) + (3*rad))));
}

ld ternarySearch(){
	ld l = 0;
	ld r = lad;
	
	while (r - l > eps) {
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;
        ld f1 = f(m1);      //evaluates the function at m1
        ld f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2) l = m1;
        else r = m2;
    }
    ld ans = acos(l/lad) + (PI/2.0);
    return ans;
}

int main(){
    fast;
	ll tc;
	cin>>tc;
	while(tc--){
		cin>>lad>>rad;
		ans = ternarySearch();
		cout<<fixed<<setprecision(9)<<ans<<nl;
	}
	return 0;
}