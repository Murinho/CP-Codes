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

const int maxn = 1005;
int n,m,a[maxn][maxn];
ld tot_sa, cov_sa = 0.0, ans;

ld piece_sa[maxn];

ld sphere_surface_area(ld radius){
	return 4.0*PI*radius*radius;
}

ld cap_surface_area(ld height, ld radius){
	return 2.0*PI*height*radius;
}

int main(){
    fast;
    cin >> n >> m;
    
    fore(i,1,n+1){
    	fore(j,1,m+1) cin >> a[i][j];
    }
    
    // calculate the cap areas:
    ld sphere_rad = (ld)n/2.0;
    int l = 1;
    int r = n;
    while(l <= r){
    	if (l == r){
    		piece_sa[l] = ((cap_surface_area(l-0.5,sphere_rad) - cap_surface_area(l-1,sphere_rad)) * 2.0)/m;
    		piece_sa[r] = piece_sa[l];
    	}
    	else{
    		piece_sa[l] = (cap_surface_area(l,sphere_rad) - cap_surface_area(l-1,sphere_rad))/m;
    		piece_sa[r] = piece_sa[l];
    	}
    	l++, r--;
    }
    
    tot_sa = sphere_surface_area(sphere_rad);
    
    fore(i,1,n+1){
    	fore(j,1,m+1){
    		cov_sa += ((ld)a[i][j] * piece_sa[i] / 100.0);
    	}
    }
    
    ans = (cov_sa / tot_sa) * 100.0;
    
    cout << fixed << setprecision(9) << ans << nl;
    return 0;
}