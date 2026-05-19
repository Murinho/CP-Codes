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

const ll maxn = 1005;
const ll loga = 12;

string q[loga],res[loga];
int a[maxn],p[maxn];
int n;

void init(){
	fore(i,0,loga) res[i] = q[i] = ".";
}

void respond(){
	cout << "! ";
	fore(i,1,n+1) cout << a[i] << " ";
	cout << nl;
	cout.flush();
}

string ask(string s){
	cout << "? " << s << nl;
	cout.flush();
	string ret;
	cin >> ret;
	return ret;
}

int main(){
    fast;
    cin >> n;
    init();

    if (n == 1){
    	cout << "! 1" << nl;
    	cout.flush();
    	return 0;
    }

    int it = 0;
	vector <pii> ivs = {{1,(n/2)},{(n/2)+1,n}};
	string s = "";
	fore(i,0,n) s += ".";

    while(1){	
		sort(ALL(ivs));
		int cnt = 0;
		for(auto &[l,r] : ivs){
			fore(j,l,r+1) s[j-1] = (cnt == 0 ? '1' : '0');
			cnt = 1-cnt;
		}

		res[it] += ask(s);
    	q[it] += s;
    	it++;
		// construir los nuevos intervalos
		vector <pii> ivs2;
		bool f = false;
    	for(auto &[l,r] : ivs){
			if (l == r){
				ivs2.pb({l,r});
				continue;
			}
			f = true;
			int mid = (l+r)/2;
			ivs2.pb({l,mid}), ivs2.pb({mid+1,r});
		}
		if (!f) break;

		ivs = ivs2;
    }

	assert(it <= 10);
    
    fore(i,1,n+1){ // ir posicion por posicion
    	set <int> st;
    	fore(j,1,n+1) st.insert(j);
    	
    	fore(j,0,it){
    		vi del;
    		if (res[j][i] == '1'){ // solo tomar a los que tengan 1 en la query
    			for(auto &elm : st){
    				if (q[j][elm] == '0') del.pb(elm);
    			}
    		}
    		else{ // solo tomar a los que tengan 0 en la query
				for(auto &elm : st){
					if (q[j][elm] == '1') del.pb(elm);
				}    			
    		}
    		for(auto &elm : del) st.erase(elm);
    	}
    	a[i] = *st.begin();
    }
    
    respond();
    
    return 0;
}