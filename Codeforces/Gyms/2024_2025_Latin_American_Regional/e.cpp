// Problem: E. Evereth Expedition
// Contest: Codeforces - 2024-2025 ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/105505/problem/E
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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e5+100;

ll n,a[maxn];
ll toder[maxn],toizq[maxn]; // guarda la siguiente posicion donde hay un numero != 0.

bool check(){ // checar que se forme montanita.
	ll tope = -1;
	fore(i,1,n+1){
		if (a[i] == n) tope = i;
	}
	
	fore(i,2,tope+1){
		if (a[i-1] >= a[i]) return false;
	}
	
	fore(i,tope+1,n+1){
		if (a[i-1] <= a[i]) return false;
	}
	return true;
}

int main(){
    fast;
   	cin >> n;
   	fore(i,1,n+1) cin >> a[i];
   	
   	// calculate the toizq.
   	ll las = -1;
   	fore(i,1,n+1){
   		if (a[i] > 0) las = i;
   		toizq[i] = las;
   	}
   	
   	// calculate the toder.
   	las = n+1;
   	rofe(i,n+1,1){
   		if (a[i] > 0) las = i;
   		toder[i] = las;
   	}
   	
   	
   	// calculate the answer
   	int l = 1;
   	int r = n;
   	int cur = 1;
   	while(l < r){
   		if (a[l] > 0 && a[r] > 0){
   			if (a[l] == cur) l++;
   			else if (a[r] == cur) r--;
   			else{
   				cout << "*" << nl;
   				return 0;
   			}
   		}
   		else if (a[l] > 0){
   			if (a[l] == cur) l++;
   			else a[r] = cur, r--;
   		}
   		else if (a[r] > 0){
   			if (a[r] == cur) r--;
   			else a[l] = cur, l++;
   		}
   		else{ // ambos estan libres.
   			if (toder[l] > r || toizq[r] < l){ // todo lo de en medio tiene puros 0's
   				fore(i,l,r+1) a[i] = cur++;
   				l = r;
   				break;
   			}
   			else if (toder[l] == toizq[r]){ // solo queda un elemento en comun.
   				ll difl = abs(toder[l] - l);
   				ll difr = abs(r - toizq[r]);
   				if (difl < difr){ // l esta mas cerca.
   					a[l] = cur;
   					l++;
   				}
   				else{ // r esta mas cerca.
   					a[r] = cur;
   					r--;
   				}
   			}
   			else if (a[toder[l]] < a[toizq[r]]){ // mover l
   				a[l] = cur;
   				l++;
   			}
   			else{
   				a[r] = cur;
   				r--;
   			}
   		}
   		cur++;
   	}
   	
   	if (a[l] == 0) a[l] = cur; // ultimo elemento.
   	
   	if (!check()){ // checar si es montanita.
   		cout << "*" << nl;
   		return 0;
   	}
   	
   	fore(i,1,n+1) cout << a[i] << " ";
   	cout << nl;
   	return 0;
}