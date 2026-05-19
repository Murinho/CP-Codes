// Problem: F. Froginald the frog
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103708/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const ll mod = 1e9+7;

vvi mul(vvi &a, vvi &b) {
    vvi c(sz(a), vi(sz(b[0])));
    for (int i = 0; i < sz(a); i++) 
        for (int j = 0; j < sz(b); j++)
            for (int k = 0; k < sz(a); k++) 
                (c[i][j] += a[i][k]*b[k][j]%mod)%=mod; 
    return c;
}

vvi exp(vvi &x, ll y) {
    vvi r(sz(x), vi(sz(x)));
    bool flag = false;
    while (y>0){
        if (y&1) {
            if (!flag) r = x, flag = true;
            else r = mul(r,x);
        }
        y=y>>1;
        x = mul(x,x);
    }
    return r;
}

map <ll, vector <ll> > mp;

int main(){
    fast;
    int k,n;
    cin >> k >> n;
    vector<int> a(n+2);
    fore(i,1,n+1) cin >> a[i];
    
   	a[0] = -1;
   	a[n+1] = k+1;
    
    sort(ALL(a));
    
    ll las = 1;
    vvi mat = {{1,1},{1,0}};
    ll dif;
    fore(i,1,sz(a)){
    	dif = a[i] - a[i-1] - 1;
    	
    	if (dif == 0){
    		cout << 0 << nl;
    		return 0;
    	}
    	
    	if (dif <= 2) continue;
    	
    	if (!mp.count(dif-2)){
    		mat[0][0] = mat[0][1] = mat[1][0] = 1;
    		mat[1][1] = 0;
    	
    		mat = exp(mat,dif-2);
    		
    		mp[dif-2] = {mat[0][0], mat[0][1]};
    	}
    	
    	
    	las = (((mp[dif-2][0] * las)) + ((mp[dif-2][1] * las)%mod))%mod;
    }
    
    cout << las << nl;
    return 0;
}