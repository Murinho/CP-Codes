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
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+100;
const ll inf = 1e9;

ll n,m,a[maxn],b[maxn];
ll lis[maxn],pre[maxn];
ll ubi[maxn];
ll tam=0;

int main(){
    fast;
    cin >> n >> m;
    fore(i,1,n+1) cin >> a[i];
    fore(i,1,m+1){
    	cin >> b[i];
    	ubi[b[i]] = i;
    }
    
    fore(i,1,min(n,m)+1) lis[i] = inf;
    
    lis[0] = 0;
    pre[0] = 0;
    fore(i,1,n+1){
    	if (a[i] > min(n,m)) continue;
    	
    	int l = 0;
    	int r = tam;
    	while(l < r){
    		ll mid = (l+r+1)/2;
    		if (lis[mid] < ubi[a[i]]) l = mid;
    		else r = mid-1;
    	}
    	
    	pre[ubi[a[i]]] = lis[l];
    	
    	if (l == tam) tam++;
    	
    	lis[l+1] = min(lis[l+1],ubi[a[i]]);
    }
    
    cout << tam << nl;
    
    vi res;
    ll cur = lis[tam];
    while(cur > 0){
    	res.pb(b[cur]);
    	cur = pre[cur];
    }
    
    reverse(ALL(res));
    
    for(auto &elm : res) cout << elm << " ";
    cout << nl;
    
    return 0;
}