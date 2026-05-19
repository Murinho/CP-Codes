// Problem: J. Jigsaw of Shadows
// Contest: Codeforces - 2024-2025 ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/105505/problem/J
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
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ld eps = 1e-6;

struct Event{
	ld pos;
	ll tipo; // 0 entrada, 1 salida.
};

ll rang,n,cnt=0;
ld ans = 0.0;
ld ang;
vector <Event> e;

bool cmp(Event &e1, Event &e2){
	if (e1.pos == e2.pos) return e1.tipo < e2.tipo;
	return e1.pos < e2.pos;
}

ld degreesToRadians(ld degrees) { return degrees * PI / 180.0; }
ld radiansToDegrees(ld radians){ return radians * (180.0 / PI); }

ld get_ca(ll h){
	ld tann = tan(ang);
	ld x = (ld)h/(ld)tann;
	return x;
}

int main(){
    fast;
    cin >> rang >> n;
    ang = (ld)rang;
    ang = degreesToRadians(ang);
    fore(i,0,n){
    	ll pos,h;
    	cin >> pos >> h;
    	ld lenca = get_ca(h);
    	ld pos2 = (ld)pos + (ld)lenca;
    	//cout << pos << " " << pos2 << nl;
    	e.pb({(ld)pos,0}); 
    	e.pb({pos2,1});
    }
    
    sort(ALL(e),cmp);
    
    ld las = 0.0;
    for(auto &ev : e){
    	if (ev.tipo == 0){
    		if (cnt == 0) las = ev.pos;
    		cnt++;
    	}
    	else{
    		cnt--;
    		if (cnt == 0){
    			ans += ((ld)ev.pos - las);
    		}
    	}
    }
    
    cout << fixed << setprecision(9) << ans << nl;
    return 0;
}